#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>
#include <bankAccountMain_global.h>
#include "transaction.h"

namespace Ui {
class account;
}

class BANKACCOUNTMAIN_EXPORT account : public QDialog
{
    Q_OBJECT

public:
    explicit account(QWidget *parent = nullptr);
    ~account();

private slots:
    void on_btnNosto_clicked();

    void on_btnSaldo_clicked();

    void on_btnUlos_clicked();

    void on_btnTapahtumat_clicked();

private:
    Ui::account *ui;
    transaction *ptr_transaction;
};

#endif // ACCOUNT_H
