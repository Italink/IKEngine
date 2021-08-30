QT     += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#增加CREATE_TEST将不会生成静态库，而是生成一个带有测试界面的程序
#DEFINES += CREATE_TEST
CONFIG += c++17
SOURCES += \
        IkDef.cpp \
        IkFactroy.cpp \
        IkItem.cpp \
        IkItem/IkBool.cpp \
        IkItem/IkBoundedNumber.cpp \
        IkItem/IkColor.cpp \
        IkItem/IkDouble.cpp \
        IkItem/IkEnum.cpp \
        IkItem/IkFloat.cpp \
        IkItem/IkInt.cpp \
        IkItem/IkString.cpp \
        IkItem/IkVector2D.cpp \
        IkItem/IkVector3D.cpp \
        IkItem/Widgets/NumberBox.cpp \
        IkItem/Widgets/NumberSlider.cpp \
        IkPanel.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    IkDef.h \
    IkFactroy.h \
    IkItem.h \
    IkItem/IkBool.h \
    IkItem/IkBoundedNumber.h \
    IkItem/IkColor.h \
    IkItem/IkDouble.h \
    IkItem/IkEnum.h \
    IkItem/IkFloat.h \
    IkItem/IkInt.h \
    IkItem/IkString.h \
    IkItem/IkVector2D.h \
    IkItem/IkVector3D.h \
    IkItem/Widgets/NumberBox.h \
    IkItem/Widgets/NumberSlider.h \
    IkPanel.h \

if(contains(DEFINES,CREATE_TEST)){
    SOURCES += Test.cpp main.cpp
    HEADERS += Test.h
}
else{
    TEMPLATE = lib
    CONFIG += staticlib
}
