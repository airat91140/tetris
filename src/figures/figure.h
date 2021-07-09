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
        QVector<QSharedPointer<piece> > pieces;

        virtual void paint(QGraphicsScene *scene) = 0;

    public:
        explicit Figure(qreal width = 0, qreal height = 0, QObject *parent = nullptr);
        ~Figure() override = default;

    public slots:
        virtual void rotate() = 0;
    };
}

#endif //TETRIS_FIGURE_H
