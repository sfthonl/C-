#include "game.h"
#include <string>
#include <iostream>

std::string message;

void Game::game_over(int game_over_id) {
  //after_game_over_button_pushed = false;
  std::cout << "game over with id " << game_over_id << "\n";
  /*
  show_winner_button->redraw();
  show_winner_button->show();
  */
  Fl_Window *window = new Fl_Window(200, 500, 300, 300 , "Show winner");
  if (game_over_id == cross_win_id) {
    message = "RED WINS\n";
  } else if (game_over_id == zero_win_id) {
    message = "BLUE WINS\n";
  } else {
    message = "DRAW\n";
  }
  Fl_Button *show_winner_button;
  show_winner_button = new Fl_Button(10, 10, 50, 50, message.c_str());
  window->show();
}

Game::Game(): our_visual_board(this) {
    this->menu_button = new Fl_Button(400, 50, 150, 50, "MENU");
    this->play_again_button = new Fl_Button(400, 150, 150, 50, "PLAY AGAIN");
    this->close_program_button = new Fl_Button(400, 250, 150, 50, "EXIT");
    //this->button->callback(cell_pushed, (void*)&(this->crd));
    this->play_again_button->callback(this->play_again_button_pushed, this);
    this->close_program_button->callback(this->close_program_button_pushed, this);
} 

Game::~Game() {
  delete this->play_again_button; 
  delete this->menu_button;
  delete this->close_program_button;
}

void Game::play_again_button_pushed(Fl_Widget *widget, void *data) {
  //after_game_over_button_pushed = true;
  //want_to_play = true;
  auto pointer_to_our_game = static_cast<Game*>(data);
  std::cout << "play_again_button_pushed\n";
  pointer_to_our_game->start_game_cycle();
}

void Game::close_program_button_pushed(Fl_Widget *widget, void *data) {
  //after_game_over_button_pushed = true;
  //want_to_play = false;
  std::cout << "close_program_button_pushed\n";
  exit(0);
}

void Game::start_game_cycle() {
  std::cout << "NEW GAME CYCLE STARTED\n";
  this->game_is_over = false;
  this->our_board.clean_board(this->board_size);
  std::cout << "check board\n";
  this->our_board.check_board();
  this->our_visual_board.clean_board(this->board_size);
}