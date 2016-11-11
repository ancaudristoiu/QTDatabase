#-------------------------------------------------
#
# Project created by QtCreator 2016-11-02T12:40:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

TARGET = MyQtSqlBrowser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbconnection.cpp \
    dbdialog.cpp \
    tableswidget.cpp

HEADERS  += mainwindow.h \
    dbconnection.h \
    dbdialog.h \
    tableswidget.h

FORMS    += mainwindow.ui \
    dbdialog.ui \
    tableswidget.ui
