/********************************************************************************
** Form generated from reading UI file 'balance.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCE_H
#define UI_BALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_balance
{
public:
    QLabel *label;
    QPushButton *btnExitBalance;

    void setupUi(QDialog *balance)
    {
        if (balance->objectName().isEmpty())
            balance->setObjectName("balance");
        balance->resize(512, 358);
        label = new QLabel(balance);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 70, 81, 61));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        btnExitBalance = new QPushButton(balance);
        btnExitBalance->setObjectName("btnExitBalance");
        btnExitBalance->setGeometry(QRect(230, 240, 261, 71));
        btnExitBalance->setFont(font);

        retranslateUi(balance);

        QMetaObject::connectSlotsByName(balance);
    } // setupUi

    void retranslateUi(QDialog *balance)
    {
        balance->setWindowTitle(QCoreApplication::translate("balance", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("balance", "Saldo", nullptr));
        btnExitBalance->setText(QCoreApplication::translate("balance", "Poistu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class balance: public Ui_balance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCE_H
