#ifndef SUCCESSFULFRAME_H
#define SUCCESSFULFRAME_H

#include <QFrame>

namespace Ui {
class SuccessfulFrame;
}

class SuccessfulFrame : public QFrame
{
    Q_OBJECT

public:
    explicit SuccessfulFrame(QWidget *parent = 0);
    ~SuccessfulFrame();
signals:
    //signal going to main menu
    void toMainMenu();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::SuccessfulFrame *ui;
};

#endif // SUCCESSFULFRAME_H
