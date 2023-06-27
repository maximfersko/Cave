#include "Application.h"

#include "ui_Application.h"

Application::Application(model::controller *controller, QWidget *parent)
    : QMainWindow(parent),
      ui_(new Ui::Application),
      controller_(controller),
      timer_(new QTimer(this)) {
    Init();
}

Application::~Application() {
}

void Application::on_openFileButton_clicked() {
    QString path = QFileDialog::getOpenFileName(
        this, tr("Open a file"), QDir::currentPath() + "../../../",
        tr("txt(*.txt)"));
    ui_->pathLabel->setText(path);
    ui_->draw->paintFromFile(path);
}

void Application::Init() {
    ui_->setupUi(this);
    this->setWindowTitle("Cave");
    ui_->draw->setController(controller_.get());
    connect(timer_.get(), SIGNAL(timeout()), this, SLOT(timerFinish()));
}

void Application::on_generateButton_clicked() {
    try {
        controller_->generateMapCave(ui_->width->value(), ui_->height->value(),
                                     ui_->chance->value());
    } catch (std::exception &e) {
        msg_.showMessage(e.what());
        msg_.exec();
    }
    ui_->draw->paintCave();
}

void Application::on_step_clicked() {
    try {
        ui_->draw->step(ui_->deathLimit->value(), ui_->birthLimit->value());
        update();
    } catch (std::exception &e) {
        msg_.showMessage(e.what());
        msg_.exec();
    }
}

void Application::on_automate_clicked() {
    (timer_->isActive()) ? ui_->automate->setText("START"),
        timer_->stop()   : ui_->automate->setText("STOP"),
        timer_->start(ui_->ms->value());
}

void Application::timerFinish() { emit ui_->step->clicked(); }
