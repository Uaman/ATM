#include "AnotherSumFrame.h"
#include "ui_AnotherSumFrame.h"

AnotherSumFrame::AnotherSumFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AnotherSumFrame)
{
    ui->setupUi(this);
}

AnotherSumFrame::~AnotherSumFrame()
{
    delete ui;
}
