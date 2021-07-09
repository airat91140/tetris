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
            << QPoint( (int)width, 0)
            << QPoint( (int)width,  (int)height)
            << QPoint(0,  (int)height);

    painter->setBrush(color);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

tetris::piece::piece(qreal width, qreal height, QColor color, QObject *parent) : QObject(parent), QGraphicsItem() {
    this->width = width;
    this->height = height;
    this->color = color;
}
