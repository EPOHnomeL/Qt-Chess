#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *main = new MainWindow();
    main->show();
    return a.exec();
}
