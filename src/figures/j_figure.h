//
// Created by airat on 02.07.2021.
//

#ifndef TETRIS_J_FIGURE_H
#define TETRIS_J_FIGURE_H

#include "figure.h"

namespace tetris {
    class j_figure : public Figure {
    private:
        enum pos {
            down_left, down, middle, up
        };
    public:
        void paint(QGraphicsScene *scene) override;

    public:
        j_figure(qreal width, qreal height, QObject *parent = nullptr);

        ~j_figure() override = default;

    public slots:

        void fall() override;
    };
};


#endif //TETRIS_J_FIGURE_H
