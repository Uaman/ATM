#ifndef TAKINGMONEY_H
#define TAKINGMONEY_H

#include <QFrame>

namespace Ui {
class TakingMoney;
}

class TakingMoney : public QFrame
{
    Q_OBJECT

public:
    explicit TakingMoney(QWidget *parent = 0);
    ~TakingMoney();

private:
    Ui::TakingMoney *ui;
};

#endif // TAKINGMONEY_H
