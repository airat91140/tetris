//
// Created by airat on 30.06.2021.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <QVector>
#include <QPointf>
#include <Qpair>
#include <QGraphicsScene>

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
        void step_fall();
        void step_move(bool is_left);

    public:
        virtual void paint(QGraphicsScene *scene) = 0;

        explicit Figure(qreal width = 0, qreal height = 0, QObject *parent = nullptr);

        ~Figure() override = default;

        virtual void move(bool is_left) {};

        static bool is_line(QGraphicsItem *it);

    public slots:
        virtual void fall() {};

    signals:
        void signal_check_figure_under();
    };
}

#endif //TETRIS_FIGURE_H
