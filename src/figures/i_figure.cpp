//
// Created by airat on 02.07.2021.
//

#include "i_figure.h"

tetris::i_figure::i_figure(qreal width, qreal height, QObject *parent) : Figure(width, height, parent) {
    pieces.reserve(4);
    for (int i = 0; i < 4; ++i) {
        pieces.append(QSharedPointer<piece>(new piece(point_width, point_height, Qt::blue)));
    }
}

void tetris::i_figure::paint(QGraphicsScene *scene) {
    scene->addItem(pieces[left].get());
    scene->addItem(pieces[middle_left].get());
    scene->addItem(pieces[middle_right].get());
    scene->addItem(pieces[right].get());

    pieces[left]->setPos(3 * point_width, 0);
    pieces[middle_left]->setPos(4 * point_width, 0);
    pieces[middle_right]->setPos(5 * point_width, 0);
    pieces[right]->setPos(6 * point_width, 0);
}
