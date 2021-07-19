//
// Created by airat on 02.07.2021.
//

#include "l_figure.h"

void tetris::l_figure::paint(QGraphicsScene *scene) {
    scene->addItem(pieces[up]);
    scene->addItem(pieces[middle]);
    scene->addItem(pieces[down]);
    scene->addItem(pieces[down_right]);

    pieces[up]->setPos(point_width * 4, 0);
    pieces[middle]->setPos(point_width * 4, point_height * 1);
    pieces[down]->setPos(point_width * 4, point_height * 2);
    pieces[down_right]->setPos(point_width * 5, point_height * 2);
}

tetris::l_figure::l_figure(qreal width, qreal height, QObject *parent) : Figure(width, height, parent) {
    pieces.reserve(4);
    for (int i = 0; i < 4; ++i) {
        pieces.append(new piece(point_width, point_height, Qt::yellow));
    }
}
