QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./json-loader/jsonfractalloader.cpp \
    mainwindow.cpp \
    main.cpp \
    ./properties/property.cpp \
    ./properties/rangebasedproperty.cpp \
    ./fractal-model/fractalmodel.cpp \
    ./controllers/labeledslider.cpp \
    ./controllers/labeledwidget.cpp \
    ./controllers/abstractpropertycontroller.cpp \
    ./controller-creator/PropertyControllerContainer.cpp \
    controllers/pointwidget/pointwidget.cpp \
    properties/pointproperty.cpp

HEADERS += \
    ./properties/property.h \
    ./properties/rangebasedproperty.h \
    ./fractal-model/fractalmodel.h \
    ./controllers/labeledslider.h \
    ./controllers/labeledwidget.h \
    ./controllers/abstractpropertycontroller.h \
    ./json-loader/jsonfractalloader.h \
    ./controller-creator/PropertyControllerContainer.h \
    controllers/pointwidget/pointwidget.h \
    mainwindow.h \
    properties/pointproperty.h

FORMS += \
  controllers/pointwidget/pointwidget.ui \
  mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
