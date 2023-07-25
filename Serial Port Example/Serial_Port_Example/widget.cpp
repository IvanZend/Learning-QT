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

    d.serial_pointer = &serial_port;
    codeSize = code.size();

    connect(&poll_timer, SIGNAL(timeout()), this, SLOT(check_uart()));
    connect(&serial_port,SIGNAL(readyRead()),this, SLOT(receiveMessage()));
}

void Widget::check_uart()
{

}

Widget::~Widget()
{
    delete ui;
}

void Widget::open_uart_settings()
{
    d.show();
}

void Widget::connect_uart()
{
    if (serial_port.isOpen())
    {
       serial_port.close();
        //poll_timer.stop();
    }
    else
    {
       serial_port.open(QIODevice::ReadWrite);
       //poll_timer.start(100);
    }
}


void Widget::receiveMessage()
{
    QByteArray dataBA = serial_port.readAll();
    QString data(dataBA);
    buffer.append(data);
    int index = buffer.indexOf(code);
    if(index != -1){
       QString message = buffer.mid(0,index);
       //ui->textBrowser->setTextColor(Qt::blue); // Receieved message's color is blue.
       //ui->textBrowser->append(message);
       buffer.remove(0,index+codeSize);
    }
}

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
