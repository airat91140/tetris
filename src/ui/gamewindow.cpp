#include "gamewindow.h"
#include "ui_gamewindow.h"

#include "j_figure.h"
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

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
    timer->start(1000);
}

GameWindow::~GameWindow()
{
    delete ui;
    delete main_scene;
}

bool GameWindow::event(QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        auto ke = dynamic_cast<QKeyEvent *>(event);
        if (ke->key() == Qt::Key_A) {
            current->move(true);
        }
        if (ke->key() == Qt::Key_D) {
            current->move(false);
        }
    }
    return QMainWindow::event(event);
}
