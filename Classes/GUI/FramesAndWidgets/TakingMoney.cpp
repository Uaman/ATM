//Developed by Dima Zvazhii
//08.11.14
#include "TakingMoney.h"
#include "ui_TakingMoney.h"

TakingMoney::TakingMoney(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TakingMoney),
    _sumToTakeOut(0)
{
    ui->setupUi(this);
}

TakingMoney::~TakingMoney()
{
    delete ui;
}

const int& TakingMoney::getSumToTakeOut()const
{
    return _sumToTakeOut;
}


void TakingMoney::on_commandLinkButton_clicked()
{
    _sumToTakeOut=10;
    emit takeOutMoney();
}

void TakingMoney::on_commandLinkButton_2_clicked()
{
    _sumToTakeOut=20;
    emit takeOutMoney();
}

void TakingMoney::on_commandLinkButton_3_clicked()
{
    _sumToTakeOut=50;
    emit takeOutMoney();
}

void TakingMoney::on_commandLinkButton_4_clicked()
{
    _sumToTakeOut=100;
    emit takeOutMoney();
}

void TakingMoney::on_commandLinkButton_5_clicked()
{
    _sumToTakeOut=200;
    emit takeOutMoney();
}

void TakingMoney::on_commandLinkButton_6_clicked()
{
    _sumToTakeOut=500;
    emit takeOutMoney();
}

void TakingMoney::on_commandLinkButton_7_clicked()
{
    emit anotherSum();
}

void TakingMoney::on_commandLinkButton_8_clicked()
{
    emit signalBack();
}
