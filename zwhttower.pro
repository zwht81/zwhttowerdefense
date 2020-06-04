#-------------------------------------------------
#
# Project created by QtCreator 2020-06-01T20:26:11
#
#-------------------------------------------------

QT       += core gui multimedia network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zwhttower
TEMPLATE = app
CONFIG += resources_big

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    menu.cpp \
    mybutton.cpp \
    map.cpp \
    player.cpp \
    enemy.cpp \
    game.cpp \
    towerarea.cpp \
    tower.cpp \
    buildtowerbutton.cpp \
    bullet.cpp

HEADERS += \
        mainwindow.h \
    menu.h \
    mybutton.h \
    map.h \
    player.h \
    enemy.h \
    game.h \
    towerarea.h \
    tower.h \
    buildtowerbutton.h \
    bullet.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    game.qrc

DISTFILES +=
