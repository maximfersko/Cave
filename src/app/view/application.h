#ifndef APPLICATION_H
#define APPLICATION_H

#include <QErrorMessage>
#include <QFileDialog>
#include <QMainWindow>
#include <QTimer>
#include <memory>

#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Application;
}
QT_END_NAMESPACE

class Application : public QMainWindow {
    Q_OBJECT

   public:
    Application(model::controller *controller, QWidget *parent = nullptr);
    ~Application();

   private slots:
    void on_openFileButton_clicked();
    void on_generateButton_clicked();
    void on_step_clicked();
    void on_automate_clicked();
    void timerFinish();

   private:
    std::unique_ptr<Ui::Application> ui_;
    std::unique_ptr<model::controller> controller_;
    std::unique_ptr<QTimer> timer_;
    QErrorMessage msg_;

    void Init();
};
#endif  // APPLICATION_H
