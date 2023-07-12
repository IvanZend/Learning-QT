#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //emgs.resize(8);
    // Disable maximizing
    //setFixedSize(width(), height());
    // Adding title for widget
    //connect(this, SLOT(clicked()), this, SLOT(on_pushButton_6_clicked()));


    QWidget::setWindowTitle("Serial Port Example");

    for (int i = 0; i < emgs.size(); i++)
    {
        emgs[i]->setParent(ui->wEmgs);
        emgs[i]->emg_bar.setOrientation(Qt::Horizontal);
        emgs[i]->emg_bar.setValue(70);
        //emgs[i]->emg_lbl.setText("EMG_0");
    }


    QPixmap pix_dial(":/new/prefix1/images/dial.png");
    //QPixmap pix_needle(":/new/prefix1/images/needle.png");

    for (int i = 0; i < motors.size(); i++)
    {
        motors[i]->setParent(ui->wMotors);

        motors[i]->motor_lbl.setPixmap(pix_dial.scaled(60, 60, Qt::KeepAspectRatio));
        //motors[i]->motor_lbl.setPixmap(pix_needle.scaled(40, 40, Qt::KeepAspectRatio));
        motors[i]->motor_lbl.setParent(ui->wMotors);
    }


}

Widget::~Widget()
{
    delete ui;
}

//uart_settings.show();Pro


MenuBar::MenuBar(QMainWindow *parent)
    : QMenuBar(parent)
{

}

MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent)
{

    // Disable maximizing
    //setFixedSize(width(), height());
    // Adding title for widget
    //connect(this, SLOT(clicked()), this, SLOT(on_pushButton_6_clicked()));
}

MenuBar::~MenuBar()
{

}

Emg::Emg(QWidget *parent)
{
    if (parent)
    {

    }
    //emg_bar.show();
}


Emg::Emg(const Emg&) : QWidget()
{

    //emg_bar.show();
}


Emg::~Emg()
{

}


Motor::Motor(QWidget *parent)
{
    if (parent)
    {

    }


}


Motor::~Motor()
{

}


/*
Motor::Motor(const Motor&) : QWidget()
{

}

*/
