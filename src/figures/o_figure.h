//
// Created by airat on 02.07.2021.
//

#ifndef TETRIS_O_FIGURE_H
#define TETRIS_O_FIGURE_H

#include "figure.h"

namespace tetris {
    class o_figure : public Figure {
    private:
        enum pos {up_left,down_left, up_right, down_right};
    public:
        void paint(QGraphicsScene *scene) override;

    public:
        o_figure(qreal width, qreal height, QObject *parent = nullptr);
        ~o_figure() override = default;

    public slots:
        virtual void rotate() {}
    };
};


#endif //TETRIS_I_FIGURE_H
