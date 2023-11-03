#include "dalimain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DaliMain w;
    w.show();
    return a.exec();
}
