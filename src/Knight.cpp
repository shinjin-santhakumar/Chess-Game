//
// Created by shinj on 12/6/2020.
//

#include "../headers/Piece.h"


Knight::Knight(int posX, int posY, bool color, string input){
    curr_x = posX;
    curr_y = posY;
    white = color;
    name = input;
}

bool Knight::movement(int destX, int destY, Board* board){
    if(curr_x == destX && curr_y == destY) {return false;}
    if((curr_x+2) == destX && (curr_y+1) == destY) {
        if(board->isFree(destX, destY)){
            return true;
        }
        if(board->isFoe(curr_x, curr_y, destX, destY)){
            return true;
        }

    } else if((curr_x+1) == destX && (curr_y+2) == destY) {
        if(board->isFree(destX, destY)){
            return true;
        }
        if(board->isFoe(curr_x, curr_y, destX, destY)){
            return true;
        }
    } else if((curr_x-2) == destX && (curr_y-1) == destY) {
        if(board->isFree(destX, destY)){
            return true;
        }
        if(board->isFoe(curr_x, curr_y, destX, destY)){
            return true;
        }
    } else if((curr_x-1) == destX && (curr_y-2) == destY) {
        if(board->isFree(destX, destY)){
            return true;
        }
        if(board->isFoe(curr_x, curr_y, destX, destY)){
            return true;
        }
    } else if((curr_x+2) == destX && (curr_y-1) == destY) {
        if(board->isFree(destX, destY)){
            return true;
        }
        if(board->isFoe(curr_x, curr_y, destX, destY)){
            return true;
        }
    } else if((curr_x-2) == destX && (curr_y+1) == destY) {
        if(board->isFree(destX, destY)){
            return true;
        }
        if(board->isFoe(curr_x, curr_y, destX, destY)){
            return true;
        }
    } else if((curr_x-1) == destX && (curr_y+2) == destY) {
        if(board->isFree(destX, destY)){
            return true;
        }
        if(board->isFoe(curr_x, curr_y, destX, destY)){
            return true;
        }
    } else if((curr_x+1) == destX && (curr_y-2) == destY) {
        if(board->isFree(destX, destY)){
            return true;
        }
        if(board->isFoe(curr_x, curr_y, destX, destY)){
            return true;
        }
    } else {
        return false;
    }

}