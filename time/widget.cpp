#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    popUp = new PopUp();

    curStatus();
    curTime.setHMS(13, 49, 00);
    setLcdTime(ui->lcdTime, &curTime);

    timer = new QTimer(this);
    timer->start(5000);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeSetWidget()));
    timeSetWidget();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::settingLcdTime(QLCDNumber *lcd)
{
    Q_UNUSED(lcd);
}

void Widget::setLcdTime(QLCDNumber *lcd, QTime *time)
{
    QString str;

    str.clear();
    str.append(QString::number(time->hour()));
    str.append(QString::number(time->minute()));
    lcd->display(str);

    lcd->setToolTip("LCD Time");
}

void Widget::timeSetWidget()
{
    //ui->timeEdit->setTime(QTime::currentTime());
    curTime = QTime::currentTime();
    setLcdTime(ui->lcdTime, &curTime);

    if(curTime.minute() > 50)
    {
        ui->labelCurStatus->setText("Мониторинг вкл. Статус отдых");
        popUp->setPopupText(QString("Инженер, отдохни!"));
        popUp->show();
    }
    else
        ui->labelCurStatus->setText("Мониторинг вкл. Статус работа");
}

void Widget::curStatus()
{
    ui->labelCurStatus->setText("Мониторинг вкл...");
}
