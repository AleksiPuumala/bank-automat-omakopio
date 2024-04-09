/********************************************************************************
** Form generated from reading UI file 'account.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_H
#define UI_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_account
{
public:
    QPushButton *btnTapahtumat_2;
    QPushButton *btnSaldo;
    QPushButton *btnUlos;
    QPushButton *btnNosto;
    QPushButton *btnTapahtumat;

    void setupUi(QDialog *account)
    {
        if (account->objectName().isEmpty())
            account->setObjectName("account");
        account->resize(538, 431);
        btnTapahtumat_2 = new QPushButton(account);
        btnTapahtumat_2->setObjectName("btnTapahtumat_2");
        btnTapahtumat_2->setGeometry(QRect(10, 290, 241, 61));
        QFont font;
        font.setPointSize(18);
        btnTapahtumat_2->setFont(font);
        btnSaldo = new QPushButton(account);
        btnSaldo->setObjectName("btnSaldo");
        btnSaldo->setGeometry(QRect(260, 290, 271, 61));
        btnSaldo->setFont(font);
        btnUlos = new QPushButton(account);
        btnUlos->setObjectName("btnUlos");
        btnUlos->setGeometry(QRect(260, 360, 271, 61));
        btnUlos->setFont(font);
        btnNosto = new QPushButton(account);
        btnNosto->setObjectName("btnNosto");
        btnNosto->setGeometry(QRect(260, 220, 271, 61));
        btnNosto->setFont(font);
        btnTapahtumat = new QPushButton(account);
        btnTapahtumat->setObjectName("btnTapahtumat");
        btnTapahtumat->setGeometry(QRect(10, 360, 241, 61));
        btnTapahtumat->setFont(font);

        retranslateUi(account);

        QMetaObject::connectSlotsByName(account);
    } // setupUi

    void retranslateUi(QDialog *account)
    {
        account->setWindowTitle(QCoreApplication::translate("account", "Dialog", nullptr));
        btnTapahtumat_2->setText(QString());
        btnSaldo->setText(QCoreApplication::translate("account", "Saldo", nullptr));
        btnUlos->setText(QCoreApplication::translate("account", "Kirjaudu ulos", nullptr));
        btnNosto->setText(QCoreApplication::translate("account", "Nosto", nullptr));
        btnTapahtumat->setText(QCoreApplication::translate("account", "Tapahtumat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class account: public Ui_account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_H
