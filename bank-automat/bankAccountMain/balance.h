#ifndef BALANCE_H
#define BALANCE_H

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDialog>

namespace Ui {
class balance;
}

class balance : public QDialog
{
    Q_OBJECT

public:
    explicit balance(QWidget *parent = nullptr);
    ~balance();

private slots:
    void on_btnExitBalance_clicked();
    void balanceSlot(QNetworkReply *reply);

private:
    Ui::balance *ui;
    QString account;
    QString amount;
    QString limit;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // BALANCE_H
