QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractpropertycontroller.cpp \
    fractal-model/fractalcontrollerfabric.cpp \
    fractal-model/labeledslider.cpp \
    fractal-model/labeledwidget.cpp \
    main.cpp \
    ./properties/property.cpp \
    ./properties/rangebasedproperty.cpp \
    ./fractal-model/fractalmodel.cpp \
    sliderpropertycontroller.cpp

HEADERS += \
    ./properties/property.h \
    ./properties/rangebasedproperty.h \
    ./fractal-model/fractalmodel.h \
    abstractpropertycontroller.h \
    fractal-model/fractalcontrollerfabric.h \
    fractal-model/labeledslider.h \
    fractal-model/labeledwidget.h \
    sliderpropertycontroller.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
