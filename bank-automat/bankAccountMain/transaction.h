#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDialog>

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

private:
    Ui::transaction *ui;
};

#endif // TRANSACTION_H