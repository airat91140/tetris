//
// Created by airat on 02.07.2021.
//

#include "j_figure.h"

void tetris::j_figure::paint(QGraphicsScene *scene) {
    scene->addItem(pieces[down_left]);
    scene->addItem(pieces[down]);
    scene->addItem(pieces[middle]);
    scene->addItem(pieces[up]);

    pieces[up]->set_vertical_coord(0);
    pieces[middle]->set_vertical_coord(1);
    pieces[down]->set_vertical_coord(2);
    pieces[down_left]->set_vertical_coord(2);

    pieces[up]->set_horizontal_coord(5);
    pieces[middle]->set_horizontal_coord(5);
    pieces[down]->set_horizontal_coord(5);
    pieces[down_left]->set_horizontal_coord(4);

    for (auto &it : pieces) {
        it->setPos(point_width * it->get_horizontal_coord(), point_height * it->get_vertical_coord());
    }
}

tetris::j_figure::j_figure(qreal width, qreal height, QObject *parent) : Figure(width, height, parent) {
    pieces.reserve(4);
    for (int i = 0; i < 4; ++i) {
        pieces.append(new piece(point_width, point_height, Qt::red));
    }
}

void tetris::j_figure::fall() {
    QList<QGraphicsItem *> found_items;
    if (angle == 0) {
        if (pieces[down]->get_vertical_coord() == 19 || pieces[down_left]->get_vertical_coord() == 19) {
            emit signal_check_figure_under();
            return;
        }
        found_items.append((pieces[down_left]->find_items_near(piece::under)));
        found_items.removeOne(pieces[down_left]);

        found_items.append((pieces[down]->find_items_near(piece::under)));
        found_items.removeOne(pieces[down]);
        found_items.removeIf(is_line);

    }
    else if (angle == 90) {

    }
    else if (angle == 180) {

    }
    else if (angle == 270) {

    }
    if (found_items.empty())
        step_fall();
    else
        emit signal_check_figure_under();
}

void tetris::j_figure::move(bool is_left) {
    QList<QGraphicsItem *> found_items;
    bool move_access = true;
    if (angle == 0) {
        if (is_left) {
            found_items.append((pieces[down_left]->find_items_near(piece::left)));
            found_items.removeOne(pieces[down_left]);
            found_items.removeIf(is_line);
        }
        else {
            found_items.append((pieces[up]->find_items_near(piece::right)));
            found_items.removeOne(pieces[up]);

            found_items.append((pieces[middle]->find_items_near(piece::right)));
            found_items.removeOne(pieces[middle]);

            found_items.append((pieces[down]->find_items_near(piece::right)));
            found_items.removeOne(pieces[down]);
            found_items.removeIf(is_line);
        }
    }
    else if (angle == 90) {

    }
    else if (angle == 180) {

    }
    else if (angle == 270) {

    }
    for (const auto &it : pieces) {
        if (it->get_horizontal_coord() == (is_left ? 0 : 9)) {
            move_access = false;
            break;
        }
    }
    if (found_items.empty() && move_access)
        step_move(is_left);
}
