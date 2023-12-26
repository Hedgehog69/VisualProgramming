#-------------------------------------------------
#
# Project created by QtCreator 2023-11-12T16:48:35
#
#-------------------------------------------------

QT       += core gui
QT       += widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# Если вы используете стандартный SQLite, можете воспользоваться встроенной библиотекой

#LIBS += -L"C:/Users/ilyap/Downloads/shop" -lsqlite3

TARGET = YourProjectName
TEMPLATE = app


TARGET = shop
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
        about_us.cpp \
        buygoods.cpp \
        cartmanager.cpp \
        cartridgepage.cpp \
        feedback.cpp \
        helpdialog.cpp \
        inkpage.cpp \
        loginform.cpp \
        main.cpp \
        mainwindow.cpp \
        mytableform.cpp \
        ourshops.cpp \
        printerpage.cpp \
        receiptform.cpp

HEADERS += \
        about_us.h \
        buygoods.h \
        cartmanager.h \
        cartridgepage.h \
        feedback.h \
        helpdialog.h \
        inkpage.h \
        loginform.h \
        mainwindow.h \
        mytableform.h \
        ourshops.h \
        printerpage.h \
        receiptform.h

RESOURCES += \
    styles.qrc \
    styles.qrc

FORMS += \
        about_us.ui \
        buygoods.ui \
        cartmanager.ui \
        cartridgepage.ui \
        feedback.ui \
        helpdialog.ui \
        inkpage.ui \
        loginform.ui \
        mainwindow.ui \
        mytableform.ui \
        ourshops.ui \
        printerpage.ui \
        receiptform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    styles.css
