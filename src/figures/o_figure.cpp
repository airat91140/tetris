//
// Created by airat on 02.07.2021.
//

#include "o_figure.h"

void tetris::o_figure::paint(QGraphicsScene *scene) {
    scene->addItem(pieces[up_left]);
    scene->addItem(pieces[up_right]);
    scene->addItem(pieces[down_left]);
    scene->addItem(pieces[down_right]);

    pieces[up_left]->setPos(point_width * 4, 0);
    pieces[up_right]->setPos(point_width * 5, 0);
    pieces[down_left]->setPos(point_width * 4, point_height * 1);
    pieces[down_right]->setPos(point_width * 5, point_height * 1);
}

tetris::o_figure::o_figure(qreal width, qreal height, QObject *parent) : Figure(width, height, parent) {
    pieces.reserve(4);
    for (int i = 0; i < 4; ++i) {
        pieces.append(new piece(point_width, point_height, Qt::green));
    }
}
