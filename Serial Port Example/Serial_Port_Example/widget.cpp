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
        emgs[i]->emg_bar.setMinimum(0);
        emgs[i]->emg_bar.setMaximum(1000);
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

    //serial_port.baudRate()

    serial_port.setBaudRate(settings_0.value("uart_baudrate").toInt());
    //serial_port.setDataBits(settings_0.value("data_bits"));
    //serial_port.setStopBits(settings_1.value("stop_bits").toInt());
    //serial_port.setParity(settings_1.value("parity").toInt());

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

void Widget::parse_uart()
{

    for (int i = 0; i < buffer.size(); i++)
    {

       switch (buffer.at(i).toLatin1())
       {
       case 0x01:
       {
           QString hardware_string;
           for (int ii = 0; ii < UART_PACKAGE_SIZE; ii++)
           {
               i++;
               if (i < buffer.size())
               {
                   hardware_string.append(buffer.at(i));
                   bool tmp_ok;
                   int hardware_val = hardware_string.toInt(&tmp_ok);
                   emgs[0]->set_value_bar(hardware_val);
               }
           }

           break;
       }
       }

       /*
       if (buffer.at(i).toLatin1() == 0x01)
       {
           QString hardware_string;
           for (int ii = 0; ii < UART_PACKAGE_SIZE; ii++)
           {
               hardware_string.append(buffer.at(i + 1 + ii));
           }

           bool tmp_ok;
           int hardware_val = hardware_string.toInt(&tmp_ok);



           //emgs[0]->set_value_bar(hardware_val);
       }
       */


       /*
       if (buffer.at(i) == 'a')
       {
           //while (buffer.at(i) != 'b')
           //{
               i++;

               QString hardware_string;
               for (int ii = 0; ii < UART_PACKAGE_SIZE; ii++)
               {
                   hardware_string.append(buffer.at(ii + i + 1));
               }

               bool tmp_ok;
               int hardware_val = hardware_string.toInt(&tmp_ok, 16);


               switch (buffer.at(i).toLatin1())
               {
               case 0x01:
               {


                   QString hardware_string;
                   for (int ii = 0; ii < UART_PACKAGE_SIZE; ii++)
                   {
                       hardware_string.append(buffer.at(i + 1 + ii));
                   }

                   bool tmp_ok;
                   int hardware_val = hardware_string.toInt(&tmp_ok);


                   //emgs[0]->set_value_bar(hardware_val);

                   break;
               }
               case 0x02:
               {

                   break;
               }
               case 0x03:
               {

                   break;
               }
               case 0x04:
               {

                   break;
               }
               case 0x05:
               {

                   break;
               }
               case 0x06:
               {

                   break;
               }
               default:
               {

                   break;
               }

               //}

               //i += UART_PACKAGE_SIZE;
           }

       }

       */
    }
}


/*
int Widget::uart_val_to_int()
{

}
*/


void Widget::receiveMessage()
{
    QByteArray dataBA = serial_port.readAll();
    QString data(dataBA);
    buffer.append(data);


    if (buffer[buffer.size() - 1].toLatin1() == 0x62)
    {
       parse_uart();
       buffer.remove(0, (buffer.size() - 1));
    }


    /*
    int index = buffer.indexOf(code);
    if(index != -1){
       QString message = buffer.mid(0,index);
       //ui->textBrowser->setTextColor(Qt::blue); // Receieved message's color is blue.
       //ui->textBrowser->append(message);
       buffer.remove(0,index+codeSize);
    }
    */
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

void Emg::set_value_bar(int emg_val)
{
    emg_bar.setValue(emg_val);
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
