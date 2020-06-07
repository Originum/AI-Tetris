#include "mainwindow.h"

#include <QApplication>

#include "board.h"

#include "menu.h"

int main(int argc, char *argv[])

{

    QApplication a(argc, argv);
    menu m;
    m.show();

    return a.exec();

}
