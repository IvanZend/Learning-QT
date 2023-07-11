#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>
#include <QMenu>
#include <QMenuBar>
#include <QMainWindow>
#include <QProgressBar>
#include <QList>

#include "dialog_uart.h"
#include "qboxlayout.h"

#define NUMBER_OF_EMGS      8

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
    QHBoxLayout emg_layout;

private slots:
    //void on_pushButton_6_clicked();

private:

    Dialog d;
    //QDialog uart_settings;
    //QString settings_file;

    //MenuBar main_menu();

    QMenu file_menu;

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
