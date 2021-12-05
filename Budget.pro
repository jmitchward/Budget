
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql gui

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD

#include($$INCLUDEPATH/SQL/SQL.pri)
#include($$INCLUDEPATH/DTO/DTO.pri)

HEADERS += \
    DTO/dataStructs.h \
    DTO/transaction.h \
    SQL/readfile.h \
    SQL/sqltablemodel.h \
    SQL/writefile.h \
    SQL/writetable.h \
    View/mainwindow.h


SOURCES += \
    App/main.cpp \
    DTO/dataStructs.cpp \
    DTO/transaction.cpp \
    SQL/readfile.cpp \
    SQL/sqltablemodel.cpp \
    SQL/writefile.cpp \
    SQL/writetable.cpp \
    View/mainwindow.cpp

RESOURCES += \
    Resources/july_transactions.csv \
    Resources/august_transactions.csv \
    Resources/september_transactions.csv \
    Resources/october_transactions.csv \
    Resources/november_transactions.csv \
    Resources/budget.db


FORMS += \
    View/mainwindow.ui


message(Budget.pro path $$INCLUDEPATH)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    /Resources/july_transactions.csv
