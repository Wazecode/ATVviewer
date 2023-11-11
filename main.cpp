#include "avtveiwer.h"

#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AVTveiwer w;
    w.show();
    return a.exec();
}
