#include "SuccessfulFrame.h"
#include "ui_SuccessfulFrame.h"

SuccessfulFrame::SuccessfulFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SuccessfulFrame)
{
    ui->setupUi(this);
}

SuccessfulFrame::~SuccessfulFrame()
{
    delete ui;
}

void SuccessfulFrame::on_commandLinkButton_clicked()
{
    emit toMainMenu();
}
