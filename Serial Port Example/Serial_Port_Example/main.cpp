#include "qobjectdefs.h"
#include "widget.h"
#include "ui_widget.h"

#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QIcon>
#include <QLayout>
#include <QFrame>
#include <QRect>
#include <QVector>
#include <QPixmap>
#include <QSizePolicy>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;

    QVBoxLayout top_bar_layout(w.ui->wMenu);

    /*
    QMenuBar menu_bar(w.ui->wMenu);
    QMenu file_menu("File");
    QMenu settings_menu("Settings");
    QAction openAct("Open", &file_menu);
    file_menu.addAction(&openAct);
    menu_bar.addMenu(&file_menu);
    menu_bar.addMenu(&settings_menu);
    top_bar_layout.addWidget(&menu_bar);
    */

    ToolBar tool_bar(w.ui->wMenu);
    QIcon icon_start = QIcon(":/new/prefix1/images/start.png");
    //QIcon icon_stop = QIcon(":/new/prefix1/images/stop.png");
    QIcon icon_settings = QIcon(":/new/prefix1/images/settings.png");
    QIcon icon_connect = QIcon(":/new/prefix1/images/connect.png");
    QIcon icon_bluetooth = QIcon(":/new/prefix1/images/bluetooth.png");
    QIcon icon_about = QIcon(":/new/prefix1/images/about.png");
    QIcon icon_erase = QIcon(":/new/prefix1/images/erase.png");
    QIcon icon_firmware = QIcon(":/new/prefix1/images/firmware.png");
    QIcon icon_log = QIcon(":/new/prefix1/images/log.png");
    QIcon icon_pause = QIcon(":/new/prefix1/images/pause.png");

    QAction start(icon_start, "Start", &tool_bar);
    //QAction stop(icon_stop, "Stop", &tool_bar);
    QAction settings(icon_settings, "Settings", &tool_bar);
    QAction connection(icon_connect, "Connect", &tool_bar);
    QAction bluetooth(icon_bluetooth, "Bluetooth", &tool_bar);
    QAction about(icon_about, "About", &tool_bar);
    QAction erase(icon_erase, "Erasae", &tool_bar);
    QAction firmware(icon_firmware, "Log", &tool_bar);
    QAction log(icon_log, "Log", &tool_bar);
    QAction pause(icon_pause, "Pause", &tool_bar);

    tool_bar.addAction(&settings);
    tool_bar.addAction(&connection);
    tool_bar.addAction(&bluetooth);
    tool_bar.addAction(&start);
    tool_bar.addAction(&pause);
    tool_bar.addAction(&log);
    tool_bar.addAction(&erase);
    tool_bar.addAction(&firmware);
    tool_bar.addAction(&about);
    top_bar_layout.addWidget(&tool_bar);

    QObject::connect(&settings, SIGNAL(triggered()), &w, SLOT(open_uart_settings()));
    QObject::connect(&connection, SIGNAL(triggered), &w, SLOT(connect_uart()));


    w.show();

    /*
    QProgressBar tmp_bar(w.ui->wSensors);
    tmp_bar.setOrientation(Qt::Vertical);
    tmp_bar.setValue(70);
    tmp_bar.show();
    emg_layout.addWidget(&tmp_bar);
    emg_layout.addWidget(&emgs[0]->emg_bar);
    */

    //QWidget single_emg_wgt;
    //QVBoxLayout single_emg_layout;
    QVBoxLayout emg_layout;
    for (int i = 0; i < w.emgs.size(); i++)
    {
        //w.emgs[i]->emg_bar.setTextVisible(true);
        w.emgs[i]->emg_bar.setFormat("EMG " + QString::number(i + 1));
        //w.emgs[i]->emg_bar.setFixedHeight(100);
        emg_layout.addWidget(&w.emgs[i]->emg_bar);
        //emg_layout.addWidget(&w.emgs[i]->emg_lbl);
    }

    w.ui->wEmgs->setLayout(&emg_layout);

    //w.emgs[1]->emg_bar.setSizePolicy(QSizePolicy::Minimum);

    QGridLayout motor_layout;

    for (int i = 0; i < w.motors.size(); i++)
    {

        //w.motors[i]->mot_bar_lay.setParent(&w.motors[i]->motor_bar_light);
        //w.motors[i]->mot_bar_lay.addWidget(&w.motors[i]->fault_light);
        //w.motors[i]->mot_bar_lay.addWidget(&w.motors[i]->motor_bar);
        //motor_layout.addWidget(&w.motors[i]->motor_lbl);
        int row_tmp, column_tmp;
        if (i <(w.motors.size()/2))
        {
            column_tmp = 0;
            row_tmp = i;
        }
        else
        {
            column_tmp = 2;
            row_tmp = i - (w.motors.size()/2);
        }

        motor_layout.addWidget(&w.motors[i]->fault_light, row_tmp, column_tmp);
        motor_layout.addWidget(&w.motors[i]->motor_bar, row_tmp, column_tmp + 1);
        w.motors[i]->motor_bar.setFormat("Motor " + QString::number(i + 1));
    }

    //motor_layout.setStretch(1, QSizePolicy::Expanding);
    w.ui->wMotors->setLayout(&motor_layout);

    QVBoxLayout sensors_layout(w.ui->wSensors);

    sensors_layout.addWidget(w.ui->wEmgs);
    sensors_layout.addWidget(w.ui->wMotors);

    w.ui->wSensors->setLayout(&sensors_layout);


    QHBoxLayout center_layout(w.ui->wCenter);
    center_layout.addWidget(w.ui->wSensors);
    center_layout.addWidget(w.ui->wGraph);
    w.ui->wCenter->setLayout(&center_layout);

    QHBoxLayout console_layout(w.ui->wConsole);
    console_layout.addWidget(w.ui->textBrowser_console);
    w.ui->wConsole->setLayout(&console_layout);

    QGridLayout main_layout(&w);
    main_layout.addWidget(w.ui->wMenu, 0, 0, Qt::AlignTop);
    main_layout.addWidget(w.ui->wCenter, 1, 0);
    main_layout.addWidget(w.ui->wConsole, 2, 0);
    w.setLayout(&main_layout);



    //w.motors[0]->motor_lbl.show();

    /*
    for (int i = 0; i < w.motors.size(); i++)
    {
        w.motors[i]->motor_lbl.show();
    }
    */

    /*
    QProgressBar test_prgrs(&w);
    test_prgrs.setValue(40);
    //test_prgrs.setTextDirection(QProgressBar::);
    test_prgrs.setOrientation(Qt::Vertical);
    //test_prgrs.setTextVisible(true);
    test_prgrs.show();
    */

    //QLabel test_lbl(&w);
    //QPixmap pxmp_tmp(":/new/prefix1/images/needle.png");
    //QPainter pntr_tmp(&w);
    //QPoint tmp_pnt;
    //pntr_tmp.drawPixmap(tmp_pnt, pxmp_tmp);
    //test_lbl.setScaledContents(true);
    //test_lbl.setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    //test_lbl.setPixmap(pxmp_tmp.scaled(40, 400, Qt::KeepAspectRatio));

    //test_lbl.show();

    return a.exec();
}
