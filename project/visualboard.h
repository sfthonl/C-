#pragma once
#include <vector>
#include "cell.h"

struct VisualBoard{
  std::vector <std::vector <Cell*>> playing_field;
  Game *pointer_to_our_game;
  VisualBoard(Game *pointer_to_our_game);
  void clean_board(int board_size);
  VisualBoard(const VisualBoard & ) = delete;
  ~VisualBoard();
};
