#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLCDNumber>
#include <QTime>
#include <QFrame>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void settingLcdTime(QLCDNumber *);
    void setLcdTime(QLCDNumber *, QTime *time);

private:
    Ui::Widget *ui;
    QTimer* timer;
    QTime   curTime;

private slots:
    void timeSetWidget();
    void curStatus();
};

#endif // WIDGET_H
