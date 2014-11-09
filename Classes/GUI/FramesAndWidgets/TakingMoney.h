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
    const int& getSumToTakeOut()const;

signals:
    void takeOutMoney();


private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

private:
    Ui::TakingMoney *ui;
    int _sumToTakeOut;
};

#endif // TAKINGMONEY_H
