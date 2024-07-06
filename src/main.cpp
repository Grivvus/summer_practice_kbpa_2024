#include "include/mainwindow.h"

// #include "include/personanswersgame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // PersonAnswersGame inst;
    // inst.show();
    return a.exec();
}
