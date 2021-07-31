//
// Created by airat on 30.06.2021.
//

#include "figure.h"

namespace tetris {
    Figure::Figure(qreal width, qreal height, QObject *parent) : QObject(parent) {
        point_height = height;
        point_width = width;
        angle = 0;
    }

    void Figure::step_fall() {
        for (auto &it : pieces) {
            it->setPos(it->mapToParent(0, point_height));
            it->set_vertical_coord(it->get_vertical_coord() + 1);
            qDebug() << it->get_horizontal_coord();
        }
    }

    void Figure::step_move(bool is_left) {
        for (auto &it : pieces) {
            it->setPos(it->mapToParent(point_width * (is_left ? -1 : 1), 0));
            it->set_horizontal_coord(it->get_horizontal_coord() + (is_left ? -1 : +1));
            qDebug() << it->get_horizontal_coord();
        }
    }

    bool Figure::is_line(QGraphicsItem *it) {
        return it->type() != QGraphicsItem::UserType;
    }
}