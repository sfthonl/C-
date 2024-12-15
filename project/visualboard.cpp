#include "visualboard.h"
#include "game.h"
#include <iostream>

VisualBoard::VisualBoard(Game *pointer_to_our_game) {
  this->pointer_to_our_game = pointer_to_our_game;
  int board_size = this->pointer_to_our_game->board_size;
  this->playing_field.resize(board_size);
  for (int i = 0; i < 3; ++i) {
    playing_field[i].resize(board_size);
  }
  for (int y = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++ x) {
      this->playing_field[y][x] = new Cell(x, y, pointer_to_our_game);
    }
  }
}

void VisualBoard::clean_board(int board_size) { 
  std::cout << "cleaning our_visual_board\n";
  this->playing_field.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->playing_field.resize(board_size);
  }
  for (int i = 0; i < board_size; ++i) {
    for (int j = 0; j < board_size; ++j) {
      this->pointer_to_our_game->our_visual_board.playing_field[i][j]->button->color(FL_WHITE);
      this->pointer_to_our_game->our_visual_board.playing_field[i][j]->button->redraw();
    }
  }
  std::cout << "have cleaned\n";
}

int board_size = 3;

VisualBoard::~VisualBoard() {
  for (int i = 0; i < board_size; ++i) {
    for (int j = 0; j < board_size; ++j) {
      delete this->playing_field[i][j]; 
    }
  }
}
