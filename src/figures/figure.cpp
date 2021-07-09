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
}