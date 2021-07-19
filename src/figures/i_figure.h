//
// Created by airat on 02.07.2021.
//

#ifndef TETRIS_I_FIGURE_H
#define TETRIS_I_FIGURE_H

#include "figure.h"

namespace tetris {
    class i_figure : public Figure {
    private:
        enum pos {left, middle_left, middle_right, right};
    public:
        void paint(QGraphicsScene *scene) override;

    public:
        i_figure(qreal width, qreal height, QObject *parent = nullptr);
        ~i_figure() override = default;

    public slots:
        virtual void rotate() {}
    };
};


#endif //TETRIS_I_FIGURE_H
