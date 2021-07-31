//
// Created by airat on 02.07.2021.
//

#include "piece.h"

QRectF tetris::piece::boundingRect() const {
    return QRect(0, 0, width, height);
}

void tetris::piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPolygon polygon;
    polygon << QPoint(0, 0)
            << QPoint((int) width, 0)
            << QPoint((int) width, (int) height)
            << QPoint(0, (int) height);

    painter->setBrush(color);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

tetris::piece::piece(qreal width, qreal height, QColor color, QObject *parent) : QObject(parent), QGraphicsItem() {
    this->width = width;
    this->height = height;
    this->color = color;
    this->vertical_coord = 0;
    this->horizontal_coord = 0;
}

QList<QGraphicsItem *> tetris::piece::find_items_near(direction dir) {
    switch (dir) {
        case under:
            return scene()->items(QPolygonF() << mapToScene(0, height)
                    << mapToScene(width, height)
                    << mapToScene(width, height * 2)
                    << mapToScene(0, height * 2));
        case left:
            return scene()->items(QPolygonF() << mapToScene(0, 0)
                                              << mapToScene(-width, 0)
                                              << mapToScene(-width, height)
                                              << mapToScene(0, height));
        case right:
            return scene()->items(QPolygonF() << mapToScene(width, 0)
                                              << mapToScene(width * 2, 0)
                                              << mapToScene(width * 2, height)
                                              << mapToScene(width, height));
    }
}

void tetris::piece::set_horizontal_coord(int coord) {
    if (coord >= 0 && coord <= 9) {
        horizontal_coord = coord;
    }
    else
        throw std::invalid_argument("Wrong distance value");
}

void tetris::piece::set_vertical_coord(int coord) {
    if (coord >= 0 && coord <= 19) {
        vertical_coord = coord;
    }
    else
        throw std::invalid_argument("Wrong distance value");
}