#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    main_scene = new QGraphicsScene();
    ui->mainGraphicsView->setScene(main_scene);

    qDebug() << ui->mainGraphicsView->heightMM();
    qreal w(347), h(677);
    main_scene->setSceneRect(0, 0, w, h);
    for (int i = 0; i < 20; ++i) { // adding horizontal lines
        main_scene->addLine(0, i * h / 20, w, i * h / 20, QPen(Qt::gray));
    }
    for (int i = 0; i < 10; ++i) { // adding horizontal lines
        main_scene->addLine(i * w / 10, 0, i * w / 10, h, QPen(Qt::gray));
    }
}

GameWindow::~GameWindow()
{
    delete ui;
    delete main_scene;
}
