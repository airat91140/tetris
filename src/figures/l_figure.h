//
// Created by airat on 02.07.2021.
//

#ifndef TETRIS_L_FIGURE_H
#define TETRIS_L_FIGURE_H

#include "figure.h"

namespace tetris {
    class l_figure : public Figure {
    private:
        enum pos {
            up, middle, down, down_right
        };
    public:
        void paint(QGraphicsScene *scene) override;

    public:
        l_figure(qreal width, qreal height, QObject *parent = nullptr);

        ~l_figure() override = default;

    public slots:

        virtual void rotate() {}
    };
};


#endif //TETRIS_L_FIGURE_H
