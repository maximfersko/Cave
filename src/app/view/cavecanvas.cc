#include "cavecanvas.h"

caveCanvas::caveCanvas(QWidget *parent)
    : QWidget(parent), canvas_(QSize(500, 500), QImage::Format_ARGB32) {
    setFocusPolicy(Qt::ClickFocus);
}

void caveCanvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect, canvas_, rect);
    painter.drawRect(1, 1, 498, 498);
}

void caveCanvas::paintFromFile(QString path) {
    controller_->initiliazeMapCaveFromFile(path.toStdString());
    paintCave();
}

void caveCanvas::clearCave() { canvas_.fill(QColor(0, 0, 0, 0)); }

void caveCanvas::paintCave() {
    clearCave();
    const auto &[count_rows, count_columns] = controller_->getMapCaveSize();
    cellH_ = 500.0 / count_rows;
    cellW_ = 500.0 / count_columns;
    QPainter painter(&canvas_);
    for (std::size_t i = 0; i < count_rows; ++i) {
        for (std::size_t j = 0; j < count_columns; ++j) {
            QPoint point(cellW_ * j, cellH_ * i);
            QSize sizePoint(cellW_, cellH_);
            if (controller_->getMapCave()(i, j) == model::kAlive) {
                painter.setPen(Qt::black);
                painter.setBrush(Qt::black);
            } else {
                painter.setPen(Qt::white);
                painter.setBrush(Qt::white);
            }
            painter.drawRect(QRect(point, sizePoint));
        }
    }
    update();
}

void caveCanvas::step(int death, int birth) {
    controller_->setLimits(death, birth);
    controller_->updateMapCave();
    this->paintCave();
}
