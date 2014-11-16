#ifndef SENDINGMONEYFRAME_H
#define SENDINGMONEYFRAME_H

#include <QFrame>
#include "MyEditLine.h"

namespace Ui {
class SendingMoneyFrame;
}

class SendingMoneyFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SendingMoneyFrame(QWidget *parent = 0);
    QString getCardNumber();
    double getMoney();
    ~SendingMoneyFrame();
signals:
    //void redirecting to MainMenuFrame
    void backToMainMenu();
    //send money
    void sendMoney();
//    //editLine
//    void editLine();
public slots:
    void doSmth();
    //editting line for password
    void passwordLineEditing();
    //editing line for card number
    void cardLineEditting();

private slots:
    //edit Line
    void editLine();

    //clear Line
    void clearLine();

    //clearing the last character
    void clearLast();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

private:
    Ui::SendingMoneyFrame *ui;
    MyEditLine* _cardNumber;
    MyEditLine* _password;
    bool _flag;
    QString _st;
};

#endif // SENDINGMONEYFRAME_H
