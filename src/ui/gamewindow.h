#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>

#include "figure.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    QGraphicsScene *main_scene, *pocket_scene, *next_scene;
    long count;
    tetris::Figure *next, *current, *pocket;
    inline const static int x_size = 720, y_size = 1080;
};

#endif // GAMEWINDOW_H
