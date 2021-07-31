#include "gamewindow.h"
#include "ui_gamewindow.h"

#include "j_figure.h"

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::GameWindow) {
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    main_scene = new QGraphicsScene();
    ui->mainGraphicsView->setScene(main_scene);

    main_scene->setSceneRect(0, 0, main_scene_w, main_scene_h);
    for (int i = 0; i < 20; ++i) { // adding horizontal lines
        main_scene->addLine(0,
                            i * main_scene_h / 20,
                            main_scene_w,
                            i * main_scene_h / 20,
                            QPen(Qt::gray));
    }
    for (int i = 0; i < 10; ++i) { // adding vertical lines
        main_scene->addLine(i * main_scene_w / 10,
                            0,
                            i * main_scene_w / 10,
                            main_scene_h,
                            QPen(Qt::gray));
    }
    current = new tetris::j_figure(main_scene_w / 10, main_scene_h / 20);
    current->paint(main_scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, current, &tetris::Figure::fall);
    timer->start(500);
    connect(current, &tetris::Figure::signal_check_figure_under, this, &GameWindow::slot_change_current);
}

GameWindow::~GameWindow() {
    delete ui;
    delete main_scene;
    delete timer;
    delete current;
}

void GameWindow::keyPressEvent(QKeyEvent *ke) {
    if (ke->key() == Qt::Key_A) {
        current->move(true);
    }
    if (ke->key() == Qt::Key_D) {
        current->move(false);
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *ke) {

}

void GameWindow::slot_change_current() {
    timer->stop();
    delete current;
    current = new tetris::j_figure(main_scene_w / 10, main_scene_h / 20);//random_figure_generator();
    current->paint(main_scene);
    connect(timer, &QTimer::timeout, current, &tetris::Figure::fall);
    timer->start();
    connect(current, &tetris::Figure::signal_check_figure_under, this, &GameWindow::slot_change_current);
}

tetris::Figure *GameWindow::random_figure_generator() const {
    switch (QRandomGenerator::global()->bounded(0, 6)) {
        case (0):
            return new tetris::i_figure(main_scene_w / 10, main_scene_h / 20);
        case (1):
            return new tetris::j_figure(main_scene_w / 10, main_scene_h / 20);
        case (2):
            return new tetris::l_figure(main_scene_w / 10, main_scene_h / 20);
        case (3):
            return new tetris::o_figure(main_scene_w / 10, main_scene_h / 20);
        case (4):
            return new tetris::s_figure(main_scene_w / 10, main_scene_h / 20);
        case (5):
            return new tetris::t_figure(main_scene_w / 10, main_scene_h / 20);
        case (6):
            return new tetris::z_figure(main_scene_w / 10, main_scene_h / 20);
    }
    return nullptr;
}
