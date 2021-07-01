#include <QApplication>
#include <QPushButton>
#include "gamewindow.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    //button.show();
    GameWindow *w = new GameWindow(nullptr);
    w->show();
    return QApplication::exec();
}
