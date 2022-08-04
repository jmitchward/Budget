
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql gui core5compat

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD

HEADERS += \
    DTO/category.h \
    DTO/dataStructs.h \
    DTO/member.h \
    DTO/transaction.h \
    Model/dataController.h \
    SQL/readFile.h \
    SQL/readTable.h \
    SQL/sqlTableModel.h \
    SQL/writeFile.h \
    SQL/writeTable.h \
    View/addExpenseBox.h \
    View/addIncomeBox.h \
    View/categoryEditBox.h \
    View/mainwindow.h \
    View/viewStats.h


SOURCES += \
    App/main.cpp \
    DTO/category.cpp \
    DTO/dataStructs.cpp \
    DTO/member.cpp \
    DTO/transaction.cpp \
    Model/dataController.cpp \
    SQL/readFile.cpp \
    SQL/readTable.cpp \
    SQL/sqlTableModel.cpp \
    SQL/writeFile.cpp \
    SQL/writeTable.cpp \
    View/addExpenseBox.cpp \
    View/addIncomeBox.cpp \
    View/categoryEditBox.cpp \
    View/mainwindow.cpp \
    View/viewStats.cpp

RESOURCES += \
    Resources/july_transactions.csv \
    Resources/august_transactions.csv \
    Resources/september_transactions.csv \
    Resources/october_transactions.csv \
    Resources/november_transactions.csv \
    Resources/budget.db


FORMS += \
    View/addExpenseBox.ui \
    View/addIncomeBox.ui \
    View/mainwindow.ui \
    View/viewStats.ui


message(Budget.pro path $$INCLUDEPATH)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    /Resources/july_transactions.csv
