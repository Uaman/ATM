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

private:
    Ui::AnotherSumFrame *ui;
};

#endif // ANOTHERSUMFRAME_H
