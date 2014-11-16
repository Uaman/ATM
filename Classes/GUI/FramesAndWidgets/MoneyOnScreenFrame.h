//Developed by Dima Zvazhii
//08.11.14
#ifndef MONEYONSCREENFRAME_H
#define MONEYONSCREENFRAME_H

#include <QFrame>
#include <QLabel>

namespace Ui {
class MoneyOnScreenFrame;
}

class MoneyOnScreenFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MoneyOnScreenFrame(QWidget *parent = 0);
    ~MoneyOnScreenFrame();
    QLabel* getLine();
signals:
    void backToMainMenu();
    void goToTakingMoney();
private slots:
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

private:
    Ui::MoneyOnScreenFrame *ui;
};

#endif // MONEYONSCREENFRAME_H
