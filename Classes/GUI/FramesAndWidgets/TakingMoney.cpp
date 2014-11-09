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
