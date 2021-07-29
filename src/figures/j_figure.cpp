//
// Created by airat on 02.07.2021.
//

#include "j_figure.h"

void tetris::j_figure::paint(QGraphicsScene *scene) {
    scene->addItem(pieces[down_left]);
    scene->addItem(pieces[down]);
    scene->addItem(pieces[middle]);
    scene->addItem(pieces[up]);

    pieces[up]->setPos(5 * point_width, 0);
    pieces[middle]->setPos(5 * point_width, 1 * point_height);
    pieces[down]->setPos(5 * point_width, 2 * point_height);
    pieces[down_left]->setPos(4 * point_width, 2 * point_height);
}

tetris::j_figure::j_figure(qreal width, qreal height, QObject *parent) : Figure(width, height, parent) {
    pieces.reserve(4);
    for (int i = 0; i < 4; ++i) {
        pieces.append(new piece(point_width, point_height, Qt::red));
    }
}

void tetris::j_figure::fall() {
    QList<QGraphicsItem *> found_items;
    if (qFuzzyCompare(pieces[down]->y(), point_height * 19)) {
        emit signal_check_figure_under();
        return;
    }
    if (angle == 0) {
        found_items.append((pieces[down_left]->find_items_under()));
        found_items.removeOne(pieces[down_left]);

        found_items.append((pieces[down]->find_items_under()));
        found_items.removeOne(pieces[down]);
    }
    if (found_items.size() <= 8)
        step_fall();
    else
        emit signal_check_figure_under();
}
