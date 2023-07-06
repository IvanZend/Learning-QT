#include "widget.h"
#include "ui_widget.h"

#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QIcon>
#include <QLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;

    QVBoxLayout top_bar_layout(w.ui->wMenu);

    QMenuBar menu_bar(w.ui->wMenu);
    QMenu file_menu("File");
    QMenu settings_menu("Settings");
    QAction openAct("Open", &file_menu);
    file_menu.addAction(&openAct);
    menu_bar.addMenu(&file_menu);
    menu_bar.addMenu(&settings_menu);
    top_bar_layout.addWidget(&menu_bar);


    QToolBar tool_bar("Tools", w.ui->wMenu);
    QIcon icon_start = QIcon(":/new/prefix1/images/start.png");
    QIcon icon_stop = QIcon(":/new/prefix1/images/stop.png");
    QIcon icon_settings = QIcon(":/new/prefix1/images/settings.png");
    QAction connection_open(icon_start, "Connect", &tool_bar);
    QAction connection_settings(icon_settings, "Settings", &tool_bar);
    tool_bar.addAction(&connection_open);
    tool_bar.addAction(&connection_settings);
    top_bar_layout.addWidget(&tool_bar);

    QGridLayout main_layout(&w);
    main_layout.addWidget(w.ui->wMenu, 0, 0, Qt::AlignTop);
    main_layout.addWidget(w.ui->wSensors, 1, 0);
    main_layout.addWidget(w.ui->wGraph, 1, 1);
    main_layout.addWidget(w.ui->wConsole, 2, 0);
    w.setLayout(&main_layout);


    // QGridLayout child_layout;
    // main_layout.addLayout(&child_layout, 0, 0, Qt::AlignLeft);

    w.show();
    return a.exec();
}
