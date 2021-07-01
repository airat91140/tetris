//
// Created by airat on 30.06.2021.
//

#ifndef TETRIS_FIGURE_H
#define TETRIS_FIGURE_H

#include <QString>
#include <QGraphicsItem>

namespace tetris {
    /**
     * @brief struct for defining a color
     */
    struct Color {
        inline const static QString red = "abc",
                                    green = "",
                                    blue = "",
                                    purple = "",
                                    yellow = "";
    };

    /**
     * @brief abstract class of figure
     */
    class Figure : public QGraphicsItem, public QObject {
    private:
        Color color;

    public:
        Figure();
        virtual void draw() = 0;

    };
}

#endif //TETRIS_FIGURE_H
