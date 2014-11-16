//Developed by Dima Zvazhii
//08.11.14
#ifndef ANOTHERSUMFRAME_H
#define ANOTHERSUMFRAME_H

#include <QFrame>
#include <QLineEdit>

namespace Ui {
class AnotherSumFrame;
}

class AnotherSumFrame : public QFrame
{
    Q_OBJECT

public:
    explicit AnotherSumFrame(QWidget *parent = 0);
    const int getMoneyFromLine()const;
    ~AnotherSumFrame();
signals:
    void signalBackOnTackingMoneyFrame();
    //take another sum signal
    void takeAnotherSum();


private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_clicked();

private:
    Ui::AnotherSumFrame *ui;
};

#endif // ANOTHERSUMFRAME_H
