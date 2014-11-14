//Developed by Dima Zvazhii
//08.11.14
#include "MoneyOnScreenFrame.h"
#include "ui_MoneyOnScreenFrame.h"

MoneyOnScreenFrame::MoneyOnScreenFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MoneyOnScreenFrame)
{
    ui->setupUi(this);
    //ui->label->setText("HELLO");
}

MoneyOnScreenFrame::~MoneyOnScreenFrame()
{
    delete ui;
}

//Returning backToMainMenu signal
void MoneyOnScreenFrame::on_commandLinkButton_clicked()
{
    emit backToMainMenu();
}

//Returning goToTakingMoney signal
void MoneyOnScreenFrame::on_commandLinkButton_2_clicked()
{
    emit goToTakingMoney();
}
