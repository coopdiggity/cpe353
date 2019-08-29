#include "dialog.h"
#include "echodialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication myApp(argc, argv);
    EchoDialog myDialog;
    myDialog.show();

    return myApp.exec();
}
