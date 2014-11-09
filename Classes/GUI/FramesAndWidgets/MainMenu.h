//Developed by Dima Zvazhii
//08.11.14
#ifndef MAINMENU_H
#define MAINMENU_H

#include <QFrame>

namespace Ui {
class MainMenu;
}

class MainMenu : public QFrame
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

signals:
    void signal_on_pay_clicked(void);

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
