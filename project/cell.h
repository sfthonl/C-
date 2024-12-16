#pragma once
#include <vector>

#include <D:\Game\fltk\FL\Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

struct Game;
struct Cell{
  std::pair <int, int> crd;
  Fl_Button *button;
  static void cell_pushed(Fl_Widget *widget, void *data);
  Game *pointer_to_our_game;

  Cell(int X, int Y, Game *pointer_to_our_game);
  Cell(const Cell & ) = delete;
  ~Cell();
};
