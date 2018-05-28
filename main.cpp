#include "mainwindow.h"
#include <QApplication>

#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\core\types_c.h>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.centerAndResize();
    w.show();

    return a.exec();
}
