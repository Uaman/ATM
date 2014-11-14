//Developed by Dima Zvazhii
//08.11.14
#ifndef ANOTHERSUMFRAME_H
#define ANOTHERSUMFRAME_H

#include <QFrame>

namespace Ui {
class AnotherSumFrame;
}

class AnotherSumFrame : public QFrame
{
    Q_OBJECT

public:
    explicit AnotherSumFrame(QWidget *parent = 0);
    ~AnotherSumFrame();
signals:
    void signalBackOnTackingMoneyFrame();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::AnotherSumFrame *ui;
};

#endif // ANOTHERSUMFRAME_H
