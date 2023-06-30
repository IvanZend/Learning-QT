#include "widget.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow main_window;
    //MenuBar main_menu(main_window);
    QMenuBar menu_bar(&main_window);
    QMenu file_menu("file");
    QMenu settings_menu("settings");
    menu_bar.addMenu(&file_menu);
    menu_bar.addMenu(&settings_menu);
    //menu_bar->show();
    //QMenu *fileMenu;
    //QMenu::&fileMenu = menu_bar()->addMenu(tr("&File"));

    //main_menu.addMenu(tr("&File"));
    //main_menu.show();

    main_window.show();

    Widget w;
    //w.show();
    return a.exec();
}
