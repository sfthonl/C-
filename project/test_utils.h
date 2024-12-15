#pragma once
#include <iostream>
#include <string>
#include "board.h"

//функция для вывода результата теста
inline void assert_equal(int actual, int expected, const std::string& message) {
    if (actual != expected) {
        std::cerr << "Test Failed: " << message << ". Expected: " << expected << ", Actual: " << actual << std::endl;
    } else {
        std::cout << "Test Passed: " << message << std::endl;
    }
}

inline void run_board_tests() {
    std::cout << "Running Board Tests..." << std::endl;

    // Тестирование конструктора по умолчанию
    Board board;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            assert_equal(board.board[i][j], 0, "Default Constructor Board Init"); // Проверка, что конструктор инициализирует 0 по умолчанию
        }
    }
    assert_equal(board.moved, 1, "Default Constructor 'moved' Init"); // Проверка, что поле moved установлено в 1
    assert_equal(board.moves, 0, "Default Constructor 'moves' Init"); // Проверка, что поле moves установлено в 0

    // Тестирование конструктора с параметром
    Board board2(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            assert_equal(board2.board[i][j], 0, "Param Constructor Board Init"); // Проверка, что конструктор с параметром инициализирует 0
        }
    }
    assert_equal(board2.moved, 1, "Param Constructor 'moved' Init"); // Проверка инициализации 'moved'
    assert_equal(board2.moves, 0, "Param Constructor 'moves' Init"); // Проверка инициализации 'moves'

    // Тестирование check_win при отсутствии победителя
    assert_equal(board.check_win(), 0, "check_win no winner"); // Проверка, что победителей на данном этапе нет (значение 0)

    // Тестирование check_win при победе первого игрока по строке
    board.board[0][0] = 1;
    board.board[0][1] = 1;
    board.board[0][2] = 1;
    assert_equal(board.check_win(), 1, "check_win Row win"); // Первый игрок победил по строке

    // Тестирование check_win при победе второго игрока по столбцу
    Board board3;
    board3.board[0][0] = 2;
    board3.board[1][0] = 2;
    board3.board[2][0] = 2;
    assert_equal(board3.check_win(), 2, "check_win column win"); // Второй игрок победил по столбцу

    // Тестирование check_win при победе второго игрока по побочной диагонали
    Board board4;
    board4.board[0][0] = 2;
    board4.board[1][1] = 2;
    board4.board[2][2] = 2;
    assert_equal(board4.check_win(), 2, "check_win Diagonal1 win"); // Второй игрок победил по побочной диагонали

     // Тестирование check_win при победе первого игрока по главной диагонали
    Board board5;
    board5.board[2][0] = 1;
    board5.board[1][1] = 1;
    board5.board[0][2] = 1;
    assert_equal(board5.check_win(), 1, "check_win Diagonal2 win"); // Первый игрок победил по главной диагонали

    // Тестирование check_pos при ходе в пустую ячейку
    Board board6;
    assert_equal(board6.check_pos(1, 1), 1, "check_pos free"); // Проверка, что ход можно сделать в пустую ячейку
    assert_equal(board6.board[1][1], 1, "check_pos free, check board"); // Проверка, что ход регистрируется

    // Тестирование check_pos при попытке сходить в занятую ячейку
    Board board7;
    board7.check_pos(1, 1);
    assert_equal(board7.check_pos(1, 1), 0, "check_pos busy"); // Проверка, что нельзя сходить в занятую ячейку
    assert_equal(board7.moved, 2, "check_pos busy, check moved"); // Проверка, что если ход не регистрируется, то moved меняется корректно
    assert_equal(board7.moves, 1, "check_pos busy, check moves"); // проверка что moves сохраняет свое значение

    // Тестирование check_pos на выигрыш
    Board board8;
    board8.board[0][0] = 1;
    board8.board[0][1] = 1;
    assert_equal(board8.check_pos(0, 2), 10, "check_pos, win"); // Проверка, что должна быть победа при ходе в (0,2)

    // Тестирование check_pos на ничью
    Board board9;
    board9.moves = 8;
    assert_equal(board9.check_pos(0, 0), -1, "check_pos draw"); // Проверка на ничью

    // Тестирование функции очистки доски (clean_board)
    Board board10(3);
    board10.check_pos(0, 0);
    board10.check_pos(1, 1);
    board10.check_pos(2, 2);
    board10.clean_board(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            assert_equal(board10.board[i][j], 0, "clean_board, check board"); // Проверка, что все ячейки доски сброшены в 0
        }
    }
    assert_equal(board10.moved, 1, "clean_board, check moved"); // Проверка, что поле moved сброшено в 1
    assert_equal(board10.moves, 0, "clean_board, check moves"); // Проверка, что поле moves сброшено в 0

    std::cout << "Board Tests Finished" << std::endl;
}