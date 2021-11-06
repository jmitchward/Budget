QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql gui

CONFIG += c++11

TEMPLATE = subdirs

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD

include($$INCLUDEPATH/SQL/SQL.pri)
include($$INCLUDEPATH/DTO/DTO.pri)

SUBDIRS += \
    SQL/SQL.pri \
    DTO/DTO.pri

message(Budget.pro path $$INCLUDEPATH)

SOURCES += \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    mainwindow.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    /Resources/july_transactions.csv
