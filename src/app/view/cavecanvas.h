#ifndef CAVECANVAS_H
#define CAVECANVAS_H

#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>

#include "../controller/controller.h"

class caveCanvas : public QWidget {
    Q_OBJECT
   private:
    double cellW_ = 0;
    double cellH_ = 0;
    QImage canvas_;
    model::controller *controller_;

   public:
    explicit caveCanvas(QWidget *parent = nullptr);
    void setController(model::controller *controller) {
        controller_ = controller;
    }
    void paintEvent(QPaintEvent *event) override;

    void paintFromFile(QString path);
    void step(int death, int birth);
    void paintCave();
    void clearCave();
};

#endif  // CAVECANVAS_H
