#include "bankpinui.h"
#include "ui_bankpinui.h"

bankPinUi::bankPinUi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bankPinUi)
{
    ui->setupUi(this);
}

bankPinUi::~bankPinUi()
{
    delete ui;
}

void bankPinUi::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug()<<"Button name: "+name;

    Number=name.last(1);
    QString prevNum=ui->linePin->text();
    ui->linePin->setText(prevNum.append(Number));
}

void bankPinUi::clearAndEnterHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug()<<"Button name: "+name;

    if(name=="btnClear"){
        qDebug()<<"clear pin";
        Number="";
        ui->linePin->setText(Number);
    }
    else {
        // lähetä pin ja kortin numero rest apiin
    }


}




// NAPIT 0-9

void bankPinUi::on_btn1_clicked(){
    numberClickHandler();
}
void bankPinUi::on_btn2_clicked(){
    numberClickHandler();
}
void bankPinUi::on_btn3_clicked(){
    numberClickHandler();
}
void bankPinUi::on_btn4_clicked(){
    numberClickHandler();
}
void bankPinUi::on_btn5_clicked(){
    numberClickHandler();
}
void bankPinUi::on_btn6_clicked(){
    numberClickHandler();
}
void bankPinUi::on_btn7_clicked(){
    numberClickHandler();
}
void bankPinUi::on_btn8_clicked(){
    numberClickHandler();
}
void bankPinUi::on_btn9_clicked(){
    numberClickHandler();
}
void bankPinUi::on_btn0_clicked(){
    numberClickHandler();
}


// CLEAR JA ENTER

void bankPinUi::on_btnEnter_clicked(){
    clearAndEnterHandler();
}


void bankPinUi::on_btnClear_clicked(){
    clearAndEnterHandler();
}


