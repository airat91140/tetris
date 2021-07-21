//
// Created by airat on 30.06.2021.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <QVector>
#include <QPointf>
#include <Qpair>

#include "piece.h"

namespace tetris {
    /**
     * @brief abstract class of figure
     */
    class Figure : public QObject {
    Q_OBJECT
    protected:
        int angle;
        qreal point_width, point_height;
        QVector<piece *> pieces;

    public:
        virtual void paint(QGraphicsScene *scene) = 0;
        explicit Figure(qreal width = 0, qreal height = 0, QObject *parent = nullptr);
        ~Figure() override = default;
        void move(bool is_left);

    public slots:
        virtual void rotate() = 0;
        virtual void fall();
    };
}

#endif //TETRIS_FIGURE_H
