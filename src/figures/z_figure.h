//
// Created by airat on 02.07.2021.
//

#ifndef TETRIS_Z_FIGURE_H
#define TETRIS_Z_FIGURE_H

#include "figure.h"

namespace tetris {
    class z_figure : public Figure {
    private:
        enum pos {left, middle_up, middle_down, right};
    public:
        void paint(QGraphicsScene *scene) override;

    public:
        z_figure(qreal width, qreal height, QObject *parent = nullptr);
        ~z_figure() override = default;

    public slots:
        virtual void rotate() {}
    };
};


#endif //TETRIS_Z_FIGURE_H
