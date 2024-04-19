QT += gui
QT += widgets
QT += core
QT += network

TEMPLATE = lib
DEFINES += BANKACCOUNTMAIN_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    balance.cpp \
    bankaccountmain.cpp \
    takemoney.cpp \
    transaction.cpp \
    withdraw.cpp

HEADERS += \
    account.h \
    balance.h \
    bankAccountMain_global.h \
    bankaccountmain.h \
    takemoney.h \
    transaction.h \
    withdraw.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    account.ui \
    balance.ui \
    takemoney.ui \
    transaction.ui \
    withdraw.ui
