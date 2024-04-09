#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QDialog>

namespace Ui {
class withdraw;
}

class withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit withdraw(QWidget *parent = nullptr);
    ~withdraw();

private slots:
    void on_btn20_clicked();

    void on_btn40_clicked();

    void on_btn60_clicked();

    void on_btn100_clicked();

    void on_btn200_clicked();

    void on_btn500_clicked();

    void on_btnOther_clicked();

    void on_btnExitWithdraw_clicked();

private:
    Ui::withdraw *ui;
};

#endif // WITHDRAW_H
