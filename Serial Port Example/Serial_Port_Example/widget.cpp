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
        emgs[i]->setParent(ui->wSensors);
        emgs[i]->emg_bar.setOrientation(Qt::Vertical);
        emgs[i]->emg_bar.setValue(70);
    }


    for (int i = 0; i < emgs.size(); i++)
    {
        emg_layout.addWidget(&emgs[i]->emg_bar);
    }

    ui->wSensors->setLayout(&emg_layout);
}

Widget::~Widget()
{
    delete ui;
}

//uart_settings.show();


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
