//
// Created by airat on 02.07.2021.
//

#include "s_figure.h"

void tetris::s_figure::paint(QGraphicsScene *scene) {
    scene->addItem(pieces[left]);
    scene->addItem(pieces[middle_up]);
    scene->addItem(pieces[middle_down]);
    scene->addItem(pieces[right]);

    pieces[left]->setPos(point_width * 4, point_height * 1);
    pieces[middle_up]->setPos(point_width * 5, 0);
    pieces[middle_down]->setPos(point_width * 5, point_height * 1);
    pieces[right]->setPos(point_width * 6, 0);
}

tetris::s_figure::s_figure(qreal width, qreal height, QObject *parent) : Figure(width, height, parent) {
    pieces.reserve(4);
    for (int i = 0; i < 4; ++i) {
        pieces.append(new piece(point_width, point_height, Qt::black));
    }
}
