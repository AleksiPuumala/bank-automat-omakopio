/********************************************************************************
** Form generated from reading UI file 'bankpinui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKPINUI_H
#define UI_BANKPINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bankPinUi
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *linePin;
    QGridLayout *gridLayout;
    QPushButton *btn2;
    QPushButton *btn5;
    QPushButton *btn8;
    QPushButton *btn7;
    QPushButton *btn9;
    QPushButton *btnClear;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn1;
    QPushButton *btn6;
    QPushButton *btn0;
    QPushButton *btnEnter;

    void setupUi(QDialog *bankPinUi)
    {
        if (bankPinUi->objectName().isEmpty())
            bankPinUi->setObjectName("bankPinUi");
        bankPinUi->resize(891, 719);
        verticalLayoutWidget = new QWidget(bankPinUi);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(300, 140, 281, 451));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(235, 44));
        label->setMaximumSize(QSize(235, 44));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        linePin = new QLineEdit(verticalLayoutWidget);
        linePin->setObjectName("linePin");
        linePin->setMinimumSize(QSize(171, 61));
        linePin->setMaximumSize(QSize(171, 61));
        QFont font1;
        font1.setPointSize(30);
        linePin->setFont(font1);
        linePin->setReadOnly(false);

        verticalLayout->addWidget(linePin, 0, Qt::AlignHCenter);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btn2 = new QPushButton(verticalLayoutWidget);
        btn2->setObjectName("btn2");
        btn2->setMinimumSize(QSize(61, 61));
        btn2->setMaximumSize(QSize(61, 61));
        QFont font2;
        font2.setPointSize(20);
        btn2->setFont(font2);

        gridLayout->addWidget(btn2, 0, 1, 1, 1);

        btn5 = new QPushButton(verticalLayoutWidget);
        btn5->setObjectName("btn5");
        btn5->setMinimumSize(QSize(61, 61));
        btn5->setMaximumSize(QSize(61, 61));
        btn5->setFont(font2);

        gridLayout->addWidget(btn5, 1, 1, 1, 1);

        btn8 = new QPushButton(verticalLayoutWidget);
        btn8->setObjectName("btn8");
        btn8->setMinimumSize(QSize(61, 61));
        btn8->setMaximumSize(QSize(61, 61));
        btn8->setFont(font2);

        gridLayout->addWidget(btn8, 2, 1, 1, 1);

        btn7 = new QPushButton(verticalLayoutWidget);
        btn7->setObjectName("btn7");
        btn7->setMinimumSize(QSize(61, 61));
        btn7->setMaximumSize(QSize(61, 61));
        btn7->setFont(font2);

        gridLayout->addWidget(btn7, 2, 0, 1, 1);

        btn9 = new QPushButton(verticalLayoutWidget);
        btn9->setObjectName("btn9");
        btn9->setMinimumSize(QSize(61, 61));
        btn9->setMaximumSize(QSize(61, 61));
        btn9->setFont(font2);

        gridLayout->addWidget(btn9, 2, 2, 1, 1);

        btnClear = new QPushButton(verticalLayoutWidget);
        btnClear->setObjectName("btnClear");
        btnClear->setMinimumSize(QSize(61, 61));
        btnClear->setMaximumSize(QSize(61, 61));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        btnClear->setFont(font3);

        gridLayout->addWidget(btnClear, 3, 0, 1, 1);

        btn3 = new QPushButton(verticalLayoutWidget);
        btn3->setObjectName("btn3");
        btn3->setMinimumSize(QSize(61, 61));
        btn3->setMaximumSize(QSize(61, 61));
        btn3->setFont(font2);

        gridLayout->addWidget(btn3, 0, 2, 1, 1);

        btn4 = new QPushButton(verticalLayoutWidget);
        btn4->setObjectName("btn4");
        btn4->setMinimumSize(QSize(61, 61));
        btn4->setMaximumSize(QSize(61, 61));
        btn4->setFont(font2);

        gridLayout->addWidget(btn4, 1, 0, 1, 1);

        btn1 = new QPushButton(verticalLayoutWidget);
        btn1->setObjectName("btn1");
        btn1->setMinimumSize(QSize(61, 61));
        btn1->setMaximumSize(QSize(61, 61));
        btn1->setFont(font2);

        gridLayout->addWidget(btn1, 0, 0, 1, 1);

        btn6 = new QPushButton(verticalLayoutWidget);
        btn6->setObjectName("btn6");
        btn6->setMinimumSize(QSize(61, 61));
        btn6->setMaximumSize(QSize(61, 61));
        btn6->setFont(font2);

        gridLayout->addWidget(btn6, 1, 2, 1, 1);

        btn0 = new QPushButton(verticalLayoutWidget);
        btn0->setObjectName("btn0");
        btn0->setMinimumSize(QSize(61, 61));
        btn0->setMaximumSize(QSize(61, 61));
        btn0->setFont(font2);

        gridLayout->addWidget(btn0, 3, 1, 1, 1);

        btnEnter = new QPushButton(verticalLayoutWidget);
        btnEnter->setObjectName("btnEnter");
        btnEnter->setMinimumSize(QSize(61, 61));
        btnEnter->setMaximumSize(QSize(61, 61));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        btnEnter->setFont(font4);

        gridLayout->addWidget(btnEnter, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(bankPinUi);

        QMetaObject::connectSlotsByName(bankPinUi);
    } // setupUi

    void retranslateUi(QDialog *bankPinUi)
    {
        bankPinUi->setWindowTitle(QCoreApplication::translate("bankPinUi", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("bankPinUi", "Sy\303\266t\303\244 PIN-koodi", nullptr));
        linePin->setText(QString());
        btn2->setText(QCoreApplication::translate("bankPinUi", "2", nullptr));
        btn5->setText(QCoreApplication::translate("bankPinUi", "5", nullptr));
        btn8->setText(QCoreApplication::translate("bankPinUi", "8", nullptr));
        btn7->setText(QCoreApplication::translate("bankPinUi", "7", nullptr));
        btn9->setText(QCoreApplication::translate("bankPinUi", "9", nullptr));
        btnClear->setText(QCoreApplication::translate("bankPinUi", "CLEAR", nullptr));
        btn3->setText(QCoreApplication::translate("bankPinUi", "3", nullptr));
        btn4->setText(QCoreApplication::translate("bankPinUi", "4", nullptr));
        btn1->setText(QCoreApplication::translate("bankPinUi", "1", nullptr));
        btn6->setText(QCoreApplication::translate("bankPinUi", "6", nullptr));
        btn0->setText(QCoreApplication::translate("bankPinUi", "0", nullptr));
        btnEnter->setText(QCoreApplication::translate("bankPinUi", "ENTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bankPinUi: public Ui_bankPinUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKPINUI_H
