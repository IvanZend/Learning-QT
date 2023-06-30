#include "widget.h"
#include "ui_widget.h"




Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Disable maximizing
    //setFixedSize(width(), height());

    // Adding title for widget
    QWidget::setWindowTitle("Serial Port Example");



    //connect(this, SLOT(clicked()), this, SLOT(on_pushButton_6_clicked()));
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_6_clicked()
{
   //uart_settings.show();
    d.show();
}
