#include "widget.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    QMenuBar menu_bar(&w);
    QMenu file_menu("file");
    QMenu settings_menu("settings");
    menu_bar.addMenu(&file_menu);
    menu_bar.addMenu(&settings_menu);
    w.show();
    return a.exec();
}
