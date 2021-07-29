//
// Created by airat on 02.07.2021.
//

#ifndef TETRIS_PIECE_H
#define TETRIS_PIECE_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsScene>

namespace tetris {
    /**
     * @brief class of the piece of figure
     */
    class piece : public QObject, public QGraphicsItem {
    Q_OBJECT
    private:
        qreal width, height;
        QColor color;

        QRectF boundingRect() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    public:
        explicit piece(qreal width = 0, qreal height = 0, QColor color = Qt::blue, QObject *parent = nullptr);

        QList<QGraphicsItem *> find_items_under();

        ~piece() override = default;
    };
}


#endif //TETRIS_PIECE_H
