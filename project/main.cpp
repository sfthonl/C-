#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

#include "cell.h"
#include "game.h"
#include "board.h"
#include "test_utils.h"

int main()
try {
    run_board_tests();

    int windowXLen = 600;
    int windowYLen = 400;

    Fl_Window *window = new Fl_Window(100, 400, windowXLen, windowYLen, "Window");

    Game ourGame;

    std::cout << "board_size: " << ourGame.board_size << "\n";
    std::cout << "BEGIN\n";

    ourGame.start_game_cycle();

    window->show();

    return Fl::run();

} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;

} catch (...) {
    std::cerr << "Oops, something went wrong..." << std::endl;
    return 2;
}
