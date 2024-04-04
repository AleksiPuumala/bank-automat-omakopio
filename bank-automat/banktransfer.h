#ifndef BANKTRANSFER_H
#define BANKTRANSFER_H

#include <QDialog>

namespace Ui {
class banktransfer;
}

class banktransfer : public QDialog
{
    Q_OBJECT

public:
    explicit banktransfer(QWidget *parent = nullptr);
    ~banktransfer();

private:
    Ui::banktransfer *ui;
};

#endif // BANKTRANSFER_H
