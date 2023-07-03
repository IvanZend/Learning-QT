#include "widget.h"

#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    QMenuBar menu_bar(&w);
    QMenu file_menu("File");
    QMenu settings_menu("Settings");
    QAction openAct("Open", &file_menu);
    file_menu.addAction(&openAct);
    menu_bar.addMenu(&file_menu);
    menu_bar.addMenu(&settings_menu);

    QToolBar tool_bar("Tools", &w);
    QIcon icon_test = QIcon(":/new/prefix1/images/stop.png");
    QAction open_connection(icon_test, "Connect", &tool_bar);

    //open_connection.setIcon(&start.png);
    tool_bar.addAction(&open_connection);

    w.show();
    return a.exec();
}
