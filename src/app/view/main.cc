#include <QApplication>

#include "application.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    model::Cave cave;
    model::controller controller(&cave);
    Application w(&controller);
    w.show();
    return a.exec();
}
