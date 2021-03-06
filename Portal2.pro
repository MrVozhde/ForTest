#-------------------------------------------------
#
# Project created by QtCreator 2019-04-20T21:14:05
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Portal2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    employeemaindialog.cpp \
    addstudentdialog.cpp \
    removestudentdialog.cpp \
    editstudentdialog.cpp \
    entekhabvaheddialog.cpp \
    addlessondialog.cpp \
    employeechangepassworddialog.cpp \
    showstudentdialog.cpp \
    addteacherdialog.cpp \
    showteacherdialog.cpp \
    removeteacherdialog.cpp \
    editteacherdialog.cpp \
    teachermaindialog.cpp \
    teacherchangepassword.cpp \
    show_student_lesson.cpp \
    sendjozve.cpp

HEADERS += \
        mainwindow.h \
    employeemaindialog.h \
    addstudentdialog.h \
    removestudentdialog.h \
    editstudentdialog.h \
    entekhabvaheddialog.h \
    addlessondialog.h \
    employeechangepassworddialog.h \
    showstudentdialog.h \
    addteacherdialog.h \
    showteacherdialog.h \
    removeteacherdialog.h \
    editteacherdialog.h \
    teachermaindialog.h \
    teacherchangepassword.h \
    show_student_lesson.h \
    sendjozve.h

FORMS += \
        mainwindow.ui \
    employeemaindialog.ui \
    addstudentdialog.ui \
    removestudentdialog.ui \
    editstudentdialog.ui \
    entekhabvaheddialog.ui \
    addlessondialog.ui \
    employeechangepassworddialog.ui \
    showstudentdialog.ui \
    addteacherdialog.ui \
    showteacherdialog.ui \
    removeteacherdialog.ui \
    editteacherdialog.ui \
    teachermaindialog.ui \
    teacherchangepassword.ui \
    show_student_lesson.ui \
    sendjozve.ui
Employee += \
        addstudentdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
