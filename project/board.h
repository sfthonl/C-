#pragma once
#include <vector>

struct Board{
    std::vector <std::vector <int>> board;

    int moved;
    int moves;

    Board();
    Board(int board_size);

    int check_win();
    int check_pos(int x, int y);

    void check_board();
    void clean_board(int board_size);
}; 
