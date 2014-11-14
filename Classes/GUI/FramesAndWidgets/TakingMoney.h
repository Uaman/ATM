//Developed by Dima Zvazhii
//08.11.14
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
    void anotherSum();
    void signalBack();

private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_4_clicked();

    void on_commandLinkButton_5_clicked();

    void on_commandLinkButton_6_clicked();

    void on_commandLinkButton_7_clicked();

    void on_commandLinkButton_8_clicked();

private:
    Ui::TakingMoney *ui;
    int _sumToTakeOut;
};

#endif // TAKINGMONEY_H
