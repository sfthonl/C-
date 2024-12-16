#pragma once
#include "board.h"
#include "visualboard.h"

struct Game{
    bool game_is_over = false;
    Board our_board;
    int board_size = 3;
    VisualBoard our_visual_board;

    int cross_win_id = 10;//and put
    int zero_win_id = 20;//and put
    int draw_id = -1;

    Game();

    void game_over(int game_over_id);
    void start_game_cycle();

    static void play_again_button_pushed(Fl_Widget *widget, void *data);
    static void close_program_button_pushed(Fl_Widget *widget, void *data);

    Fl_Button *menu_button;
    Fl_Button *play_again_button;
    Fl_Button *close_program_button;

    Game(const Game & ) = delete;
    ~Game();
};
