#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Button.H>

#include <utility>

struct Game;

struct Cell : public Fl_Button {
    std::pair<int, int> crd;
    int cellState; // 0 - пустая, 1 - крестик, 2 - нолик
    Game *pointer_to_our_game;

    Cell(int X, int Y, Game *pointer_to_our_game);
    Cell(const Cell &) = delete;
    ~Cell();

    void draw() override;
    static void cell_pushed(Fl_Widget *widget, void *data);
};
