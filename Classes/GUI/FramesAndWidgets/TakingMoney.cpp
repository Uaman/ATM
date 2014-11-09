#include "TakingMoney.h"
#include "ui_TakingMoney.h"

TakingMoney::TakingMoney(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TakingMoney)
{
    ui->setupUi(this);
}

TakingMoney::~TakingMoney()
{
    delete ui;
}
