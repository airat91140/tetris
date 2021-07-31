//
// Created by airat on 02.07.2021.
//

#ifndef TETRIS_PIECE_H
#define TETRIS_PIECE_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>

namespace tetris {
    /**
     * @brief class of the piece of figure
     */
    class piece : public QObject, public QGraphicsItem {
    Q_OBJECT
    private:
        qreal width, height;
        QColor color;
        int vertical_coord;
        int horizontal_coord;

        QRectF boundingRect() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    public:
        enum direction {left, right, under};

        explicit piece(qreal width = 0, qreal height = 0, QColor color = Qt::blue, QObject *parent = nullptr);

        QList<QGraphicsItem *> find_items_near(direction dir);

        ~piece() override = default;

        inline int get_horizontal_coord() const {return horizontal_coord;}

        void set_horizontal_coord(int coord);

        inline int get_vertical_coord() const {return vertical_coord;}

        void set_vertical_coord(int coord);
    };
}


#endif //TETRIS_PIECE_H
