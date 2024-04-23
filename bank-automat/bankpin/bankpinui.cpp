#include "bankpinui.h"
#include "ui_bankpinui.h"
#include <qmessagebox.h>

bankPinUi::bankPinUi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bankPinUi)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
    loginNum=3;
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
    ui->linePin->setText(prevNum.append("*"));
    pinNumber.append(Number);
}

void bankPinUi::clearAndEnterHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug()<<"Button name: "+name;

    if(name=="btnClear"){
        Number="";
        pinNumber="";
        ui->linePin->setText(Number);
    }
    else {
        //QString cardnum="1234"; //väliaikainen korttinumero.

        QJsonObject jsonObj; //lähetettävä json paketti
        jsonObj.insert("cardnumber",cardnum);
        jsonObj.insert("cardpin",pinNumber);

        QString site_url="http://localhost:3000/login";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

        reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());
    }

}

void bankPinUi::loginSlot(QNetworkReply *reply)
{
    qDebug()<<"loginslot";
    response_data=reply->readAll();
    qDebug()<<response_data;
    QMessageBox msgBox;
    if (response_data==""){
        qDebug()<<"Palvelin ei vastaa";
        msgBox.setText("Palvelin ei vastaa");
        msgBox.exec();
        bankPinUi::close();
    } else
    if(response_data=="-4078"){
        msgBox.setText("Tietokantavirhe");
        msgBox.exec();
        bankPinUi::close();
    }
     else if(response_data!="false" && response_data!=""){
            qDebug()<<"kirjautuminen ok";
            // msgBox.setText("Kirjautuminen OK");
            // msgBox.exec();


            emit loginSignal(response_data);

            qDebug()<<"clear pin";
            Number="";
            pinNumber="";
            ui->linePin->setText(Number);
        } else {
            // kirjautuminen ei onnistunut
            msgBox.setText("Väärä PIN");
            msgBox.exec();

            qDebug()<<"väärä pin";
            qDebug()<<"clear pin";
            Number="";
            pinNumber="";
            ui->linePin->setText(Number);
            loginNum=loginNum-1;

            if(loginNum==0){ //kirjautumis yritykset = 0
                qDebug()<<"yritys loppu";
                msgBox.setText("Yritykset loppu");
                msgBox.exec();
                bankPinUi::close();
        }
    }
}

void bankPinUi::cardNum(QString card)
{
    card.remove(0, 3);
    card.remove(10, 3);
    cardnum=card;
    qDebug()<<card;
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




