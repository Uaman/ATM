#include "MenuAmount.h"
#include "ui_MenuAmount.h"

MenuAmount::MenuAmount(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MenuAmount)
{
    ui->setupUi(this);
}

MenuAmount::~MenuAmount()
{
    delete ui;
}
