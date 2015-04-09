#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer();

    timer->start(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(timeSetWidget()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timeSetWidget()
{
    ui->timeEdit->setTime(QTime::currentTime());
}
