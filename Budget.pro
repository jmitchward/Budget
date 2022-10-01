
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql gui core5compat

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD

HEADERS += \
    DTO/Category.h \
    DTO/DataStructs.h \
    DTO/Member.h \
    DTO/Store.h \
    DTO/Transaction.h \
    Model/DataController.h \
    SQL/ReadFile.h \
    SQL/ReadTable.h \
    SQL/SQLTableModel.h \
    SQL/WriteFile.h \
    SQL/WriteTable.h \
    View/AddExpenseBox.h \
    View/AddIncomeBox.h \
    View/CategoryEditBox.h \
    View/MainWindow.h \
    View/MemberEditBox.h \
    View/ViewStats.h


SOURCES += \
    App/main.cpp \
    DTO/Category.cpp \
    DTO/DataStructs.cpp \
    DTO/Member.cpp \
    DTO/Store.cpp \
    DTO/Transaction.cpp \
    Model/DataController.cpp \
    SQL/ReadFile.cpp \
    SQL/ReadTable.cpp \
    SQL/SQLTableModel.cpp \
    SQL/WriteFile.cpp \
    SQL/WriteTable.cpp \
    View/AddExpenseBox.cpp \
    View/AddIncomeBox.cpp \
    View/CategoryEditBox.cpp \
    View/MainWindow.cpp \
    View/MemberEditBox.cpp \
    View/ViewStats.cpp

RESOURCES += \
    Resources/july_transactions.csv \
    Resources/august_transactions.csv \
    Resources/september_transactions.csv \
    Resources/october_transactions.csv \
    Resources/november_transactions.csv \
    Resources/budget.db


FORMS += \
    View/AddExpenseBox.ui \
    View/AddIncomeBox.ui \
    View/MainWindow.ui


message(Budget.pro path $$INCLUDEPATH)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    /Resources/july_transactions.csv
