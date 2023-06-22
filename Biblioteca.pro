
QT += core  charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Biblioteca
TEMPLATE = app
INCLUDEPATH += .
RC_ICONS = logo.ico
# Input
HEADERS += Controller/controller.h \
           Controller/file_manager.h \
           Controller/homecontroller.h \
           Model/autorimodel.h \
           Model/generimodel.h \
           Model/libro.h \
           Model/model.h \
           Model/preferenzemodel.h \
           Model/storage.h \
           View/home.h \
           View/view.h \
    Controller/main_controller.h \
    View/main_view.h \
    View/view_chart.h \
    Controller/charts_controller.h \
    View/pie_view.h \
    View/bar_view.h \
    View/area_view.h \
    Model/model_data.h
SOURCES += main.cpp \
           Controller/controller.cpp \
           Controller/file_manager.cpp \
           Controller/homecontroller.cpp \
           Model/autorimodel.cpp \
           Model/generimodel.cpp \
           Model/libro.cpp \
           Model/model.cpp \
           Model/preferenze.cpp \
           Model/storage.cpp \
           View/home.cpp \
           View/view.cpp \
    Controller/main_controller.cpp \
    View/main_view.cpp \
    Controller/charts_controller.cpp \
    View/pie_view.cpp \
    View/view_chart.cpp \
    View/bar_view.cpp \
    View/area_view.cpp

DISTFILES += \
    logo.ico \
    prova-biblioteca.json
