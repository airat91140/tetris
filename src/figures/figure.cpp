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
        }
    }

    void Figure::move(bool is_left) {
        for (auto &it : pieces) {
            it->setPos(it->mapToParent(point_width * (is_left ? -1 : 1), 0));
        }
    }
}