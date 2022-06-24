QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    asymdecryptwindow.cpp \
    asymencryptwindow.cpp \
    asymencwindow.cpp \
    blowfish_encryption.cpp \
    main.cpp \
    mainwindow.cpp \
    rsa_encryption.cpp \
    symdecryptwindow.cpp \
    symencryptwindow.cpp \
    symencwindow.cpp

HEADERS += \
    asymdecryptwindow.h \
    asymencryptwindow.h \
    asymencwindow.h \
    blowfish_encryption.h \
    mainwindow.h \
    rsa_encryption.h \
    symdecryptwindow.h \
    symencryptwindow.h \
    symencwindow.h

FORMS += \
    asymdecryptwindow.ui \
    asymencryptwindow.ui \
    asymencwindow.ui \
    mainwindow.ui \
    symdecryptwindow.ui \
    symencryptwindow.ui \
    symencwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
