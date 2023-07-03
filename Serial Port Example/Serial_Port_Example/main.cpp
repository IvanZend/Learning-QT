#include "widget.h"
#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QToolBar>

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
    QAction open_connection("Connect", &tool_bar);
    tool_bar.addAction(&open_connection);

    w.show();
    return a.exec();
}
