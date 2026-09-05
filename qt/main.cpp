#include <QApplication>
#include "form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form widget;
    widget.show();
    return a.exec();
}