#include "dialog_uart.h"
#include "ui_dialog_uart.h"


QSettings settings(QSettings::UserScope, "uart_baudrate", "data_bits");

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    serial_pointer = nullptr;
    //serial_pointer->setBaudRate(QSerialPort::BaudRate(9600));
    //serial_pointer = serial;

    ui->setupUi(this);

    // Ports
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox->addItems(stringPorts);

    // Baud Rate Ratios
    QVector<qint32> baudRates = info.standardBaudRates(); // What baudrates does my computer support ?
    QVector<QString> stringBaudRates;
    for(int i = 0 ; i < baudRates.size() ; i++){
        stringBaudRates.append(QString::number(baudRates.at(i)));
    }
    ui->comboBox_2->addItems(stringBaudRates);

    for (int i = 0 ; i < stringBaudRates.size() ; i++)
    {
        if (stringBaudRates[i] == settings.value("uart_baudrate").toString())
        {
            ui->comboBox_2->setCurrentIndex(i);
        }
    }
    //ui->comboBox_2->setItemText(-1, settings.value("uart_baudrate").toString());

    // Data Bits
    ui->comboBox_3->addItem("5");
    ui->comboBox_3->addItem("6");
    ui->comboBox_3->addItem("7");
    ui->comboBox_3->addItem("8");

    ui->comboBox_3->size();

    for (int i = 0; i < (ui->comboBox_3->count()); i++)
    {
        if ((ui->comboBox_3->itemText(i)) == settings.value("data_bits").toString())
        {
            ui->comboBox_2->setCurrentIndex(i);
        }
    }

    //ui->comboBox_3->setItemText(0, settings.value("data_bits").toString());


    // Stop Bits
    ui->comboBox_4->addItem("1 Bit");
    ui->comboBox_4->addItem("1,5 Bits");
    ui->comboBox_4->addItem("2 Bits");

    // Parities
    ui->comboBox_5->addItem("No Parity");
    ui->comboBox_5->addItem("Even Parity");
    ui->comboBox_5->addItem("Odd Parity");
    ui->comboBox_5->addItem("Mark Parity");
    ui->comboBox_5->addItem("Space Parity");

    //Flow Controls

    /*
    ui->comboBox_6->addItem("No Flow Control");
    ui->comboBox_6->addItem("Hardware Flow Control");
    ui->comboBox_6->addItem("Software Flow Control");
    */

}

Dialog::~Dialog()
{

    delete ui;
}


void Dialog::on_pushButton_2_clicked()
{

    QString portName = ui->comboBox->currentText();
    serial_pointer->setPortName(portName);

    serial_pointer->open(QIODevice::ReadWrite);

    //if(!serial_pointer->isOpen()){
        //ui->textBrowser->setTextColor(Qt::red);
        //ui->textBrowser->append("!!!! Something went Wrong !!!!");
    //}
    //else {

        QString stringbaudRate = ui->comboBox_2->currentText();
        int intbaudRate = stringbaudRate.toInt();
        serial_pointer->setBaudRate(intbaudRate);

        QString dataBits = ui->comboBox_3->currentText();
        if(dataBits == "5 Bits") {
            serial_pointer->setDataBits(QSerialPort::Data5);
        }
        else if((dataBits == "6 Bits")) {
            serial_pointer->setDataBits(QSerialPort::Data6);
        }
        else if(dataBits == "7 Bits") {
            serial_pointer->setDataBits(QSerialPort::Data7);
        }
        else if(dataBits == "8 Bits"){
            serial_pointer->setDataBits(QSerialPort::Data8);
        }

        QString stopBits = ui->comboBox_4->currentText();
        if(stopBits == "1 Bit") {
            serial_pointer->setStopBits(QSerialPort::OneStop);
        }
        else if(stopBits == "1,5 Bits") {
            serial_pointer->setStopBits(QSerialPort::OneAndHalfStop);
        }
        else if(stopBits == "2 Bits") {
            serial_pointer->setStopBits(QSerialPort::TwoStop);
        }

        QString parity = ui->comboBox_5->currentText();
        if(parity == "No Parity"){
            serial_pointer->setParity(QSerialPort::NoParity);
        }
        else if(parity == "Even Parity"){
            serial_pointer->setParity(QSerialPort::EvenParity);
        }
        else if(parity == "Odd Parity"){
            serial_pointer->setParity(QSerialPort::OddParity);
        }
        else if(parity == "Mark Parity"){
            serial_pointer->setParity(QSerialPort::MarkParity);
        }
        else if(parity == "Space Parity") {
            serial_pointer->setParity(QSerialPort::SpaceParity);
        }


        /*
        QString flowControl = ui->comboBox_6->currentText();
        if(flowControl == "No Flow Control") {
            serial_pointer->setFlowControl(QSerialPort::NoFlowControl);
        }
        else if(flowControl == "Hardware Flow Control") {
            serial_pointer->setFlowControl(QSerialPort::HardwareControl);
        }
        else if(flowControl == "Software Flow Control") {
            serial_pointer->setFlowControl(QSerialPort::SoftwareControl);
        }
        */

        //code = ui->lineEdit->text();
        codeSize = code.size();

        //connect(serial_pointer,SIGNAL(readyRead()),this,SLOT(receiveMessage()));

    //}

    settings.setValue("uart_baudrate", serial_pointer->baudRate());
    settings.setValue("data_bits", serial_pointer->dataBits());

    this->close();
}

/*
During process of making this program, i encountered a problem.
Library of QSerialPort does not guarantee that received message comes at once.It mostly comes part by part.
Sometimes it comes completely.But it is not guarantee.I tried to solve this issue by giving message a code.
I stored every received message in buffer. Whenever i store message in my buffer,i searched my code in buffer.
If it is found,i display the part of the message until the code. And i remove that message from buffer.
If it is not found i keep storing received message in buffer.
*/

/*
void Dialog::receiveMessage()
{
    QByteArray dataBA = serial_pointer->readAll();
    QString data(dataBA);
    buffer.append(data);
    int index = buffer.indexOf(code);
    if(index != -1){
        QString message = buffer.mid(0,index);
        ui->textBrowser->setTextColor(Qt::blue); // Receieved message's color is blue.
        ui->textBrowser->append(message);
        buffer.remove(0,index+codeSize);
    }
}
*/

/*
void Dialog::on_pushButton_clicked()
{
    QString message = ui->lineEdit_2->text();
    ui->textBrowser->setTextColor(Qt::darkGreen); // Color of message to send is green.
    ui->textBrowser->append(message);
    serial_pointer->write(message.toUtf8());
}
*/

// Button of Disconnect
/*
void Dialog::on_pushButton_3_clicked()
{
    serial_pointer->close();
}
*/

// Button of Refresh Ports
void Dialog::on_pushButton_4_clicked()
{
    ui->comboBox->clear();
    QList<QSerialPortInfo> ports = info.availablePorts();
    QList<QString> stringPorts;
    for(int i = 0 ; i < ports.size() ; i++){
        stringPorts.append(ports.at(i).portName());
    }
    ui->comboBox->addItems(stringPorts);
}

// Button of Clear
void Dialog::on_pushButton_5_clicked()
{
    //ui->textBrowser->clear();
}

