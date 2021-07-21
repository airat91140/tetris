#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>

#include "figure.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow() override;

private:
    Ui::GameWindow *ui;
    QGraphicsScene *main_scene, *pocket_scene, *next_scene;
    long count;
    tetris::Figure *next, *current, *pocket;
    const qreal main_scene_w = 347, main_scene_h = 677;
    QTimer *timer;
    bool event(QEvent *event) override;
};

#endif // GAMEWINDOW_H
