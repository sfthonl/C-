#include "cell.h"
#include "game.h"
#include <iostream>
#include <FL/fl_draw.H>

int window_x_len = 600;
int window_y_len = 400;
int step_from_edge = 50;
int button_size = 100;
 
 
Cell::Cell (int X, int Y, Game *pointer_to_our_game):Fl_Button(step_from_edge + button_size * X, step_from_edge + button_size * Y, button_size, button_size, ""){ 
  this->crd.first = X;
  this->crd.second = Y;
  /*this->button = new Fl_Button(step_from_edge + button_size * X, step_from_edge + button_size * Y, button_size, button_size, "");
  this->button->color(FL_WHITE);
  this->button->callback(this->cell_pushed, this);//(void*)&(this->crd)
  this->pointer_to_our_game = pointer_to_our_game;*/
  //this->pointer_to_our_game->our_visual_board.playing_field[X][Y] = new Fl_Button(step_from_edge + button_size * X, step_from_edge + button_size * Y, button_size, button_size, "");
  this->color(FL_WHITE);
  this->callback(this->cell_pushed, this);//(void*)&(this->crd)
  this->pointer_to_our_game = pointer_to_our_game;
}

Cell::~Cell() {
  delete this;
}

int cell_occupied_id = 0;
int put_cross_id = 1;
int put_zero_id = 2; 

void Cell::cell_pushed(Fl_Widget *widget, void *data) { 
  //data = this
    //std::pair <int, int> *xy = (std::pair <int, int>*)data;
    auto pointer_to_cell = static_cast<Cell*>(data);
    auto xy = pointer_to_cell->crd;
    std::cout << "Pushed: " << xy.first << ' ' << xy.second << "\n";
    int check_pos_id = pointer_to_cell->pointer_to_our_game->our_board.check_pos(xy.first, xy.second);
    if (check_pos_id == cell_occupied_id) {
      std::cout << "cell occupied\n";
      return;
    } 
    if (pointer_to_cell->pointer_to_our_game->game_is_over) {
      std::cout << "game_is_over\n";
      return;
    }
    if (check_pos_id == put_cross_id) {
      pointer_to_cell->cellState = 1;
      pointer_to_cell->redraw();
      std::cout<<"put cross\n";
      return;
    } else if (check_pos_id == put_zero_id) {
      pointer_to_cell->cellState = 2;
      pointer_to_cell->redraw();
      std::cout<<"put zero\n";
      return;
    }
    //game is over
    int game_over_id = check_pos_id;
    std::cout << "CASE GAME IS OVER\n";
    std::cout << "game_over_id: " << game_over_id << "\n"; 
    
    if (game_over_id == pointer_to_cell->pointer_to_our_game->draw_id) {
      if (pointer_to_cell->pointer_to_our_game->our_board.moved - 1 == 1) {
        pointer_to_cell->cellState = 1;
        pointer_to_cell->redraw();
      } else{
        pointer_to_cell->cellState = 2;
        pointer_to_cell->redraw();
      }
    }
    //cout << "game_o"
    if (game_over_id == pointer_to_cell->pointer_to_our_game->cross_win_id) {
      pointer_to_cell->cellState = 1;
    } else if (game_over_id == pointer_to_cell->pointer_to_our_game->zero_win_id) {
      pointer_to_cell->cellState = 2;
    }
    pointer_to_cell->draw();
    pointer_to_cell->pointer_to_our_game->game_is_over = true;
    pointer_to_cell->pointer_to_our_game->game_over(game_over_id);
}
void Cell::draw() {
    Fl_Button::draw();

    switch (cellState) {
        case 1:
            fl_color(FL_RED);
            fl_line(x() + 10, y() + 10, x() + w() - 10, y() + h() - 10);
            fl_line(x() + w() - 10, y() + 10, x() + 10, y() + h() - 10);
            break;
        case 2:
            fl_color(FL_BLUE);
            fl_arc(x() + 10, y() + 10, w() - 20, h() - 20, 0, 360);
            break;
    }
}
