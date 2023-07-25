#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include <QProgressBar>
#include <QList>
#include <QToolBar>
#include <QPixmap>
#include <QLabel>
#include <QPainter>
#include <QAction>

#include "dialog_uart.h"
#include "qtimer.h"


#define NUMBER_OF_EMGS      8
#define UART_PACKAGE_SIZE	4

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class MenuBar : public QMenuBar
{
    Q_OBJECT


public:
    MenuBar(QWidget *parent);
    MenuBar(QMainWindow *parent);
    ~MenuBar();


};

class Emg : public QWidget
{
    Q_OBJECT

public:
    Emg(QWidget *parent = nullptr);
    Emg(const Emg &);
    ~Emg();

    QProgressBar emg_bar;
    //QLabel emg_lbl;
};


class Motor : public QWidget
{
    Q_OBJECT

public:
    Motor (QWidget *parent = nullptr);
    //Motor (const Motor &);
    ~Motor();

    QLabel motor_lbl;
    QProgressBar motor_bar;
    QLabel fault_light;
    //QPixmap pix_dial;
    //QPixmap pix_needle;
};

class ToolBar : public QToolBar
{
    Q_OBJECT

public:
    ToolBar(QWidget *parent);
    ~ToolBar();
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Ui::Widget *ui;
    Emg emg_1, emg_2, emg_3, emg_4, emg_5, emg_6, emg_7, emg_8;
    QVector<Emg*> emgs {&emg_1, &emg_2, &emg_3, &emg_4, &emg_5, &emg_6, &emg_7, &emg_8};

    QMenu file_menu;
    Motor motor_1, motor_2, motor_3, motor_4, motor_5, motor_6;
    QVector<Motor*> motors {&motor_1, &motor_2, &motor_3, &motor_4, &motor_5, &motor_6};
    //QVector<Motor*> motors {&motor_1};

    QSerialPort serial_port;
    Dialog d;
    QTimer poll_timer;
    QString buffer;
    QString code;
    int codeSize;

public slots:
    //void on_pushButton_6_clicked();
    void open_uart_settings();
    void check_uart();
    void connect_uart();
    void receiveMessage();
    void parse_uart();
    //int  uart_val_to_int();

private:


    //QDialog uart_settings;
    //QString settings_file;

    //MenuBar main_menu();

};


/*
class Dialog : public QDialog
{
    Q_OBJECT

    public:
    Dialog(QDialog *parent = nullptr);


};
*/



#endif // WIDGET_H
