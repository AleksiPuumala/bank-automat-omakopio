#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QList>
#include <QStandardItemModel>

namespace Ui {
class transaction;
}

class transaction : public QDialog
{
    Q_OBJECT

public:
    explicit transaction(QWidget *parent = nullptr);
    ~transaction();

private slots:
    void on_btnExit_clicked();
    void transactionSlot(QString, QByteArray);
    void showTransactionSlot(QNetworkReply*);

    void on_btnNext_clicked();
    void on_btnBack_clicked();

private:
    Ui::transaction *ui;
    QNetworkReply *reply;
    QByteArray response_data;
    QNetworkAccessManager *transactionManager;
    QString cnum, timestamp, amount, ttype, tid;
    //QList<QString> tList {cnum, timestamp, amount, ttype, tid};
    QList<QStandardItem*> tList {typeitem, amountitem,timestampitem, cardnumitem, tranid};
    QJsonArray tArray;
    QStandardItemModel *table_model;
    QStandardItem *typeitem, *amountitem, *timestampitem, *cardnumitem, *tranid;

    int rowcount, rowStart, rowEnd;
    void makeTable(int,int);
    void nextTable();
    void backTable();


signals:
    void transactionLogoutSignal();
};

#endif // TRANSACTION_H
