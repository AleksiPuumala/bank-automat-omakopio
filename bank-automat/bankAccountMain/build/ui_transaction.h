/********************************************************************************
** Form generated from reading UI file 'transaction.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTION_H
#define UI_TRANSACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_transaction
{
public:
    QLabel *label;
    QPushButton *btnExit;

    void setupUi(QDialog *transaction)
    {
        if (transaction->objectName().isEmpty())
            transaction->setObjectName("transaction");
        transaction->resize(576, 464);
        label = new QLabel(transaction);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 100, 191, 41));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        btnExit = new QPushButton(transaction);
        btnExit->setObjectName("btnExit");
        btnExit->setGeometry(QRect(290, 340, 261, 71));
        btnExit->setFont(font);

        retranslateUi(transaction);

        QMetaObject::connectSlotsByName(transaction);
    } // setupUi

    void retranslateUi(QDialog *transaction)
    {
        transaction->setWindowTitle(QCoreApplication::translate("transaction", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("transaction", "Tilitapahtumat", nullptr));
        btnExit->setText(QCoreApplication::translate("transaction", "Poistu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transaction: public Ui_transaction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTION_H
