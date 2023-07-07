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
