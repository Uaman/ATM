#include "MoneyOnScreenFrame.h"
#include "ui_MoneyOnScreenFrame.h"

MoneyOnScreenFrame::MoneyOnScreenFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MoneyOnScreenFrame)
{
    ui->setupUi(this);
}

MoneyOnScreenFrame::~MoneyOnScreenFrame()
{
    delete ui;
}
