//
// Created by shinj on 12/4/2020.
//

#include "../headers/Board.h"
#include <string>

using namespace std;


bool Board::isFree(int x, int y){
    if(vectorBoard[x][y] == nullptr )
        return true;
    else
        return false;
}

bool Board::isFoe(int x, int y, int new_x, int new_y) {
    if(vectorBoard[new_x][new_y] == nullptr) {
        return false;
    } else {
        if (vectorBoard[x][y]->getColor() && !vectorBoard[new_x][new_y]->getColor()) { //white
            return true;
        } else if (!vectorBoard[x][y]->getColor() && vectorBoard[new_x][new_y]->getColor()) { //black
            return true;
        } else {
            return false;
        }
    }
}


void Board::setEmptyBoard(){
    for(int i=0; i<8; i++){
        vectorBoard.push_back(vector<Piece*>());
        for(int j=0;j<8;j++){
            vectorBoard.at(i).push_back(nullptr);
        }
    }
}

// vectorBoard
Board::Board(){
    setEmptyBoard();
    /*
    Piece* WR1 = new Rook(true);
    Piece* WK1 = new Knight(true);
    Piece* WB1 = new Bishop(true);
    Piece* WK = new King(true);
    Piece* WQ = new Queen(true);
    Piece* WB2 = new Bishop(true);
    Piece* WK2 = new Knight(true);
    Piece* WR2 = new Rook(true);


    vectorBoard.at(0).at(7) = WR1;
    vectorBoard.at(1).at(7) = WK1;
    vectorBoard.at(2).at(7) = WB1;
    vectorBoard.at(3).at(7) = WK;
    vectorBoard.at(4).at(7) = WQ;
    vectorBoard.at(5).at(7) = WB2;
    vectorBoard.at(6).at(7) = WK2;
    vectorBoard.at(7).at(7) = WR2;
    */
    //--------------------------------------
    // KNIGHTS
    //--------------------------------------

    Piece* WH1 = new Knight(1,7,true, "WH");
    vectorBoard[1][7] = WH1;
    Piece* WH2 = new Knight(6,7,true, "WH");
    vectorBoard[6][7] = WH2;

    Piece* BH1 = new Knight(1,0,false, "BH");
    vectorBoard[1][0] = BH1;
    Piece* BH2 = new Knight(6,0,false, "BH");
    vectorBoard[6][0] = BH2;

    //--------------------------------------
    // BISHOPS
    //--------------------------------------
    Piece* WB1 = new Bishop(2,7,true, "WB");
    vectorBoard[2][7] = WB1;
    Piece* WB2 = new Bishop(5,7,true, "WB");
    vectorBoard[5][7] = WB2;

    Piece* BB1 = new Bishop(2,0,false, "BB");
    vectorBoard[2][0] = BB1;
    Piece* BB2 = new Bishop(5,0,false, "BB");
    vectorBoard[5][0] = BB2;

    //--------------------------------------
    // ROOKS
    //--------------------------------------
    Piece* BR1 = new Rook(0,0, false, "BR");
    vectorBoard[0][0] = BR1;

    Piece* BR2 = new Rook(7,0, false, "BR");
    vectorBoard[7][0] = BR2;

    Piece* WR1 = new Rook(0,7, true, "WR");
    vectorBoard[0][7] = WR1;

    Piece* WR2 = new Rook(7,7, true, "WR");
    vectorBoard[7][7] = WR2;


    //--------------------------------------
    // QUEENS
    //-------------------------------------
    Piece* BQ = new Queen(3, 0, false, "BQ");
    vectorBoard[3][0] = BQ;
    Piece* WQ = new Queen(3, 7, true, "WQ");
    vectorBoard[3][7] = WQ;

    //--------------------------------------
    // KINGS
    //--------------------------------------
    Piece* BK = new King(4, 0, false, "BK");
    vectorBoard[4][0] = BK;

    Piece* WK = new King(4, 7, true, "WK");
    vectorBoard[4][7] = WK;

    //--------------------------------------
    // PAWNS
    //--------------------------------------

    Piece* WP0 = new Pawn(0 , 6, true, "WP");
    vectorBoard[0][6] = WP0;

    Piece* WP1 = new Pawn(1 , 6, true, "WP");
    vectorBoard[1][6] = WP1;

    Piece* WP2 = new Pawn(2 , 6, true, "WP");
    vectorBoard[2][6] = WP2;

    Piece* WP3 = new Pawn(3 , 6, true, "WP");
    vectorBoard[3][6] = WP3;

    Piece* WP4 = new Pawn(4 , 6, true, "WP");
    vectorBoard[4][6] = WP4;

    Piece* WP5 = new Pawn(5 , 6, true, "WP");
    vectorBoard[5][6] = WP5;

    Piece* WP6 = new Pawn(6 , 6, true, "WP");
    vectorBoard[6][6] = WP6;

    Piece* WP7 = new Pawn(7 , 6, true, "WP");
    vectorBoard[7][6] = WP7;

    Piece* BP0 = new Pawn(0 , 1, false, "BP");
    vectorBoard[0][1] = BP0;

    Piece* BP1 = new Pawn(1 , 1, false, "BP");
    vectorBoard[1][1] = BP1;

    Piece* BP2 = new Pawn(2 , 1, false, "BP");
    vectorBoard[2][1] = BP2;

    Piece* BP3 = new Pawn(3 , 1, false, "BP");
    vectorBoard[3][1] = BP3;

    Piece* BP4 = new Pawn(4 , 1, false, "BP");
    vectorBoard[4][1] = BP4;

    Piece* BP5 = new Pawn(5 , 1, false, "BP");
    vectorBoard[5][1] = BP5;

    Piece* BP6 = new Pawn(6 , 1, false, "BP");
    vectorBoard[6][1] = BP6;

    Piece* BP7 = new Pawn(7 , 1, false, "BP");
    vectorBoard[7][1] = BP7;

        //Piece* BP = new Pawn(false);
        //vectorBoard.at(i).at(6) = BP;
}



void Board::print(){
    string border = "  |----|----|----|----|----|----|----|----|";
    string bound = "  =========================================";
    cout << bound << endl;
    for(int y=0;y<8;y++){
        cout << y << " | ";
        for(int x=0;x<8;x++){
            if(vectorBoard.at(x).at(y) != nullptr){
                cout << vectorBoard[x][y]->getName();
            }else{
                cout << "  ";
            }
            cout << " | ";
        }
        cout << endl;
        if(y < 7)
            cout << border << endl;
    }
    cout << bound << endl;
    cout << "    ";
    for(int i=0; i< 8;i++){
        cout << i << "    ";
    }
    cout << endl;
}

void Board::updateBoard(int newX, int newY, Piece* movePiece){
    int temp,temp2;
    temp = movePiece->getPosX();
    temp2 = movePiece->getPosY();

    movePiece->setPosX(newX);
    movePiece->setPosY(newY);



    vectorBoard.at(newX).at(newY) = movePiece;
    vectorBoard.at(temp).at(temp2) = nullptr;
    /*


    */


}

vector<vector<Piece *>> Board::getBoard() {
    return vectorBoard;
}

