//
// Created by shinj on 12/4/2020.
//

#ifndef CHESSGAME_BOARD_H
#define CHESSGAME_BOARD_H

#include <iostream>
#include <vector>
#include <string>

#include "../headers/Piece.h"

using namespace std;

class Piece;

class Board
{
private:
    vector< vector<Piece* > > vectorBoard;

public:
    Board();

    vector<vector<Piece*>> getBoard();

    void setEmptyBoard();
    void print();
    //Piece* getBoard(int row, int column);
    bool isFree(int row, int col);
    bool isFoe(int x, int y, int new_x, int new_y);
    //bool isFoe(int row, int col);

    void updateBoard(int newX, int newY, Piece* movePiece);


};

#endif
