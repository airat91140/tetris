#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QRandomGenerator>

#include "figure.h"
#include "all_figures.h"

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
    tetris::Figure *random_figure_generator() const;

public slots:
    void slot_change_current();

protected:
    void keyPressEvent(QKeyEvent *ke) override;
    void keyReleaseEvent(QKeyEvent *ke) override;
};

#endif // GAMEWINDOW_H
