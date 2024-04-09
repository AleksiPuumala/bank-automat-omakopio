/********************************************************************************
** Form generated from reading UI file 'withdraw.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAW_H
#define UI_WITHDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_withdraw
{
public:
    QPushButton *btn100;
    QPushButton *btnOther;
    QPushButton *btn500;
    QPushButton *btn200;
    QPushButton *btnExitWithdraw;
    QPushButton *btn60;
    QPushButton *btn40;
    QPushButton *btn20;

    void setupUi(QDialog *withdraw)
    {
        if (withdraw->objectName().isEmpty())
            withdraw->setObjectName("withdraw");
        withdraw->resize(646, 433);
        btn100 = new QPushButton(withdraw);
        btn100->setObjectName("btn100");
        btn100->setGeometry(QRect(320, 210, 241, 61));
        QFont font;
        font.setPointSize(18);
        btn100->setFont(font);
        btnOther = new QPushButton(withdraw);
        btnOther->setObjectName("btnOther");
        btnOther->setGeometry(QRect(70, 350, 241, 61));
        btnOther->setFont(font);
        btn500 = new QPushButton(withdraw);
        btn500->setObjectName("btn500");
        btn500->setGeometry(QRect(320, 280, 241, 61));
        btn500->setFont(font);
        btn200 = new QPushButton(withdraw);
        btn200->setObjectName("btn200");
        btn200->setGeometry(QRect(70, 280, 241, 61));
        btn200->setFont(font);
        btnExitWithdraw = new QPushButton(withdraw);
        btnExitWithdraw->setObjectName("btnExitWithdraw");
        btnExitWithdraw->setGeometry(QRect(320, 350, 241, 61));
        btnExitWithdraw->setFont(font);
        btn60 = new QPushButton(withdraw);
        btn60->setObjectName("btn60");
        btn60->setGeometry(QRect(70, 210, 241, 61));
        btn60->setFont(font);
        btn40 = new QPushButton(withdraw);
        btn40->setObjectName("btn40");
        btn40->setGeometry(QRect(320, 140, 241, 61));
        btn40->setFont(font);
        btn20 = new QPushButton(withdraw);
        btn20->setObjectName("btn20");
        btn20->setGeometry(QRect(70, 140, 241, 61));
        btn20->setFont(font);

        retranslateUi(withdraw);

        QMetaObject::connectSlotsByName(withdraw);
    } // setupUi

    void retranslateUi(QDialog *withdraw)
    {
        withdraw->setWindowTitle(QCoreApplication::translate("withdraw", "Dialog", nullptr));
        btn100->setText(QCoreApplication::translate("withdraw", "100\342\202\254", nullptr));
        btnOther->setText(QCoreApplication::translate("withdraw", "Muu summa", nullptr));
        btn500->setText(QCoreApplication::translate("withdraw", "500\342\202\254", nullptr));
        btn200->setText(QCoreApplication::translate("withdraw", "200\342\202\254", nullptr));
        btnExitWithdraw->setText(QCoreApplication::translate("withdraw", "Poistu", nullptr));
        btn60->setText(QCoreApplication::translate("withdraw", "60\342\202\254", nullptr));
        btn40->setText(QCoreApplication::translate("withdraw", "40\342\202\254", nullptr));
        btn20->setText(QCoreApplication::translate("withdraw", "20\342\202\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class withdraw: public Ui_withdraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAW_H
