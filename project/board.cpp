#include "board.h"
#include <iostream>

Board::Board() { 
  this->board.assign(3, std::vector <int> (3, 0));
  this->moved = 1;
  this->moves = 0;
}

Board::Board(int board_size) { 
  this->board.assign(board_size, std::vector <int> (board_size, 0));
  this->moved = 1;
  this->moves = 0;
}

int Board::check_win()
{   
    int winner=0;
    for (int i=0;i<3;i++)
    {
        if (board[0][i]==board[1][i] and board[1][i]==board[2][i] and board[0][i]!=0)
            winner = board[0][i];
        if (board[i][0]==board[i][1] and board[i][1]==board[i][2] and board[i][0]!=0)
            winner = board[i][0];
    }
    if (board[0][0]==board[1][1] and board[1][1]==board[2][2] and board[0][0]!=0)
        winner = board[0][0];
    if (board[2][0]==board[1][1] and board[1][1]==board[0][2] and board[2][0]!=0)
        winner = board[2][0];
    return winner;
}

void Board::check_board()
{
    for (int i=0;i<3;i++)
    {
        for (int i1:board[i])
        {
            std::cout<<i1<<" ";
        }
        std::cout<<"\n"; 
    }
    std::cout<<"\n";
}

int Board::check_pos(int x, int y)
{   
    if (board[y][x]==0)
    {
        moves++;
        board[y][x]=moved;
        moved=1+moved%2;
        int win = check_win();
        //checkboard();
        if (win!=0)
            return win*10;
        if (win==0 and moves==9)
            return -1;
        return board[y][x];
    }
    else
        return 0;
}

void Board::clean_board(int board_size) {
  this->board.assign(board_size, std::vector <int> (board_size, 0));
  this->moved = 1;
  this->moves = 0;
}
