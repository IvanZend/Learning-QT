#include "widget.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow main_window;
    //MenuBar main_menu(main_window);
    QMenuBar *menu_bar = new QMenuBar(&main_window);
    QMenu fileMenu("file");
    menu_bar->addMenu(&fileMenu);
    menu_bar->show();
    //QMenu *fileMenu;
    //QMenu::&fileMenu = menu_bar()->addMenu(tr("&File"));

    //main_menu.addMenu(tr("&File"));
    // main_menu.show();

    main_window.show();

    Widget w;
    //w.show();
    return a.exec();
}
