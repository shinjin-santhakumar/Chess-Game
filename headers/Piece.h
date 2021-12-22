//
// Created by shinj on 12/2/2020.
//

#ifndef CHESSGAME_PIECE_H
#define CHESSGAME_PIECE_H

#include "../headers/Board.h"

#include <string>
#include <iostream>
#include "Board.h"
#include "GameManager.h"

class Board;

using namespace std;

class Piece {
public:

    virtual bool movement(int new_x, int new_y, Board* board) = 0;
    int getPosX(){return curr_x;}
    int getPosY(){return curr_y;}
    void setPosX(int input){ curr_x = input;}
    void setPosY(int input){ curr_y = input;}
    string getName(){return name;}
    bool getColor(){return white;}

protected:
    int curr_x ;
    int curr_y ;
    string name;
    bool white;
};



class Pawn: public Piece {
private:
    bool firstMove;

public:
    //true is white and false is black
    Pawn(int posX, int posY, bool white, string name);
    bool movement(int new_x, int new_y, Board* board) override ;

};



class King : public Piece {
public:
    King(int posX, int posY, bool white, string name);
    bool movement(int new_x, int new_y, Board* board) override;
};

class Rook : public Piece {
public:
    Rook(int posX, int posY, bool white, string name);
    bool movement(int new_x, int new_y, Board* board) override;
};


class Knight : public Piece {
public:
    Knight(int posX, int posY, bool white, string name);
    bool movement(int destX, int destY, Board* board) override ;
};

class Bishop : public Piece {
public:
    Bishop(int posX, int posY, bool white, string name);
    bool movement(int destX, int destY, Board* board) override ;

};

class Queen : public Piece {
public:
    Queen(int posX, int posY, bool white, string name);
    bool movement(int destX, int destY, Board* board) override ;
};


#endif //CHESSGAME_PIECE_H
