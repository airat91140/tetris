//
// Created by airat on 02.07.2021.
//

#ifndef TETRIS_T_FIGURE_H
#define TETRIS_T_FIGURE_H

#include "figure.h"

namespace tetris {
    class t_figure : public Figure {
    private:
        enum pos {
            up, left, middle, right
        };
    public:
        void paint(QGraphicsScene *scene) override;

    public:
        t_figure(qreal width, qreal height, QObject *parent = nullptr);

        ~t_figure() override = default;

    public slots:

        virtual void rotate() {}
    };
};


#endif //TETRIS_T_FIGURE_H
