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

    QToolBar tool_bar("Tools", w.ui->wMenu);
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
    QAction connect(icon_connect, "Connect", &tool_bar);
    QAction bluetooth(icon_bluetooth, "Bluetooth", &tool_bar);
    QAction about(icon_about, "About", &tool_bar);
    QAction erase(icon_erase, "Erasae", &tool_bar);
    QAction firmware(icon_firmware, "Log", &tool_bar);
    QAction log(icon_log, "Log", &tool_bar);
    QAction pause(icon_pause, "Pause", &tool_bar);


    tool_bar.addAction(&connect);
    tool_bar.addAction(&bluetooth);
    tool_bar.addAction(&start);
    tool_bar.addAction(&pause);
    tool_bar.addAction(&log);
    tool_bar.addAction(&erase);
    tool_bar.addAction(&firmware);
    tool_bar.addAction(&about);
    top_bar_layout.addWidget(&tool_bar);



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

    QHBoxLayout motor_layout;

    for (int i = 0; i < w.motors.size(); i++)
    {
        motor_layout.addWidget(&w.motors[i]->motor_lbl);
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

    for (int i = 0; i < w.motors.size(); i++)
    {
        w.motors[i]->motor_lbl.show();
    }

    /*
    QProgressBar test_prgrs(&w);
    test_prgrs.setValue(40);
    //test_prgrs.setTextDirection(QProgressBar::);
    test_prgrs.setOrientation(Qt::Vertical);
    //test_prgrs.setTextVisible(true);
    test_prgrs.show();
    */

    return a.exec();
}
