#include <QtGui/QApplication>
#include "clientdashboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientDashboard w;
    w.hide();

    return a.exec();
}
