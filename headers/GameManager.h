//
// Created by shinj on 12/2/2020.
//

#ifndef CHESSGAME_GAMEMANAGER_H
#define CHESSGAME_GAMEMANAGER_H

#include "../headers/Board.h"
#include "../headers/Pawn.h"

using namespace std;

class Board;

class Piece;

class Pawn;

// singleton-based object which will manage who's turn it is, as well as keep track of status of game
class GameManager {
private:
    Board* gameboard;
    bool isWhiteTurn;
    bool gameIsOver;
    bool whiteIsInCheck;
    bool blackIsInCheck;
    bool userWantsToPlay;
public:
    GameManager();

    void check(Piece* piece);
    void startGame();
    bool quitPrompt();
    void printPlayerTurn();
    bool selectDifferentPiece();
    Piece* selectPiecePrompt();
    void move();
    bool isValidSelectPiece(int startX, int startY);
};



#endif //CHESSGAME_GAMEMANAGER_H



