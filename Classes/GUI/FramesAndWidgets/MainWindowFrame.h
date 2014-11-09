#ifndef MAINWINDOWFRAME_H
#define MAINWINDOWFRAME_H

#include <QFrame>

namespace Ui {
class MainWindowFrame;
}

class MainWindowFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MainWindowFrame(QWidget *parent = 0);
    ~MainWindowFrame();

signals:
    void signalLogInClicked(void);
public slots:
    void on_pushButton_clicked();
private:
    Ui::MainWindowFrame *ui;
};

#endif // MAINWINDOWFRAME_H
