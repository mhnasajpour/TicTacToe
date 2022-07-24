QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    courtgame.cpp \
    drawdialog.cpp \
    gamehistory.cpp \
    getnames.cpp \
    historydialog.cpp \
    main.cpp \
    mainwindow.cpp \
    winnerdialog.cpp

HEADERS += \
    courtgame.h \
    drawdialog.h \
    gamehistory.h \
    getnames.h \
    historydialog.h \
    mainwindow.h \
    winnerdialog.h

FORMS += \
    courtgame.ui \
    drawdialog.ui \
    gamehistory.ui \
    getnames.ui \
    historydialog.ui \
    mainwindow.ui \
    winnerdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resorces.qrc

STATECHARTS +=
