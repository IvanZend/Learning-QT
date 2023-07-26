#ifndef DIALOG_UART_H
#define DIALOG_UART_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QSettings>

extern QSettings settings_0, settings_1;


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    //explicit Dialog(QWidget *parent = nullptr);
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QSerialPort* serial_pointer;

public slots:
    //void receiveMessage();
    //void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    //void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();


private:
    //QSerialPort* serial_pointer;
    Ui::Dialog *ui;
    //QSerialPort serialPort;
    QSerialPortInfo info;
    //QString buffer;
    //QString code;
    //int codeSize;

};

#endif // DIALOG_UART_H
