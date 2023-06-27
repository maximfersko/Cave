QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    view/cavecanvas.cc \
    controller/controller.cc \
    model/cave.cc \
    model/matrix/matrix.inl \
    view/application.cc \
    view/main.cc
    view/main.cc

HEADERS += \
    view/cavecanvas.h \
    controller/controller.h \
    model/cave.h \
    model/matrix/matrix.h \
    view/application.h

FORMS += \
    ui/application.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/cave/10x10.txt \
    data/maze/4x4.txt
