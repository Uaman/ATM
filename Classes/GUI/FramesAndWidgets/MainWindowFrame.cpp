#include "MainWindowFrame.h"
#include "ui_MainWindowFrame.h"

MainWindowFrame::MainWindowFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MainWindowFrame)
{
    ui->setupUi(this);
}

MainWindowFrame::~MainWindowFrame()
{
    delete ui;
}

void MainWindowFrame::on_pushButton_clicked()
{
    emit signalLogInClicked();
}

const QString& MainWindowFrame::getCardNumber() const
{
    return _cardNumb;
}

const QString& MainWindowFrame::getPassword() const
{
    return _pass;
}

void MainWindowFrame::on_lineEdit_editingFinished()
{
    _cardNumb=ui->lineEdit->text();
    emit loginEntered();
}

void MainWindowFrame::on_lineEdit_2_editingFinished()
{
    _pass=ui->lineEdit_2->text();
    emit passwordEntered();
}
