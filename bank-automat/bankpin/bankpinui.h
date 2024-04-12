#ifndef BANKPINUI_H
#define BANKPINUI_H

#include "bankpin_global.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDialog>

namespace Ui {
class bankPinUi;
}

class BANKPIN_EXPORT bankPinUi : public QDialog
{
    Q_OBJECT

public:
    explicit bankPinUi(QWidget *parent = nullptr);
    ~bankPinUi();

private slots:
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();
    void on_btn9_clicked();
    void on_btn0_clicked();

    void on_btnEnter_clicked();
    void on_btnClear_clicked();

    void loginSlot(QNetworkReply *reply);

private:
    Ui::bankPinUi *ui;
    QString Number;
    QString pinNumber;
    short loginNum;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;

    void numberClickHandler();
    void clearAndEnterHandler();
signals:
    void loginSignal(QByteArray);
};

#endif // BANKPINUI_H
