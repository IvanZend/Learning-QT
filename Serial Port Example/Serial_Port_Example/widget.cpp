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


    //connect(icon_settings, SLOT(clicked()), this, SLOT(on_pushButton_6_clicked()));


    QWidget::setWindowTitle("Serial Port Example");

    for (int i = 0; i < emgs.size(); i++)
    {
        emgs[i]->emg_bar.setValue(0);
    }


    //QPixmap pix_dial(":/new/prefix1/images/dial.png");
    //QPixmap pix_needle(":/new/prefix1/images/needle.png");
    //QPixmap speedometer(60, 60);

    for (int i = 0; i < motors.size(); i++)
    {
        //QPainter painter_tmp(&motors[i]->motor_lbl);
       // QPoint tmp_pnt_1;
        //painter_tmp.drawPixmap(tmp_pnt_1, pix_dial);
        //painter_tmp.drawPixmap(0, 0, pix_dial);
        //painter_tmp.drawPixmap(20, 20, pix_needle);
        //motors[i]->motor_lbl.setPixmap(speedometer.scaled(60, 60, Qt::KeepAspectRatio, Qt::FastTransformation));
        //motors[i]->motor_lbl.setPixmap(pix_needle/*.scaled(40, 40, Qt::KeepAspectRatio)*/);
        //motors[i]->motor_lbl.setScaledContents(true);
        //motors[i]->motor_lbl.setAlignment(Qt::AlignCenter);

        motors[i]->motor_bar.setValue(0);
        //motors[i]->motor_bar.setOrientation(Qt::Vertical);
        motors[i]->fault_light.setPixmap(QPixmap(":/new/prefix1/images/grey_light.png").scaled(15,15));
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::open_uart_settings()
{
    d.show();
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

ToolBar::ToolBar(QWidget *parent)
{
    if (parent)
    {

    }
}

ToolBar::~ToolBar()
{

}


/*
Motor::Motor(const Motor&) : QWidget()
{

}

*/
