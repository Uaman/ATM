#ifndef MYEDITLINE_H
#define MYEDITLINE_H

#include <QLineEdit>

class MyEditLine : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyEditLine(QWidget *parent = 0);
signals:
  //void focussed(bool hasFocus);
  void focused();

protected:
  virtual void focusInEvent(QFocusEvent *e);
  virtual void focusOutEvent(QFocusEvent *e);

public slots:

};

#endif // MYEDITLINE_H
