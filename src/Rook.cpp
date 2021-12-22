//
// Created by shinj on 12/5/2020.
//

#include "../headers/Piece.h"

Rook::Rook(int posX, int posY, bool color,string input){
    curr_x = posX;
    curr_y = posY;
    white = color;
    name = input;
}

bool Rook::movement(int new_x, int new_y, Board* board) {

    //vertical for rooks
    if(curr_x == new_x && curr_y == new_y) {return false;}
    if(new_x == curr_x){
        int tempY = curr_y;
        if(curr_y < new_y) { //
            tempY++;
            while(!board->isFoe(curr_x, curr_y, new_x, tempY)){
                if( ( tempY == new_y && board->isFoe(curr_x, curr_y, new_x, tempY) ) || (tempY == new_y && board->isFree(new_x, tempY) ) ){
                    return true;
                }
                if(!board->isFree(new_x, tempY)){
                    return false;
                }
                tempY++;
            }
            if(tempY == new_y){
                return true;
            }
            return false;
        } else if(curr_y > new_y) {
            tempY--;
            while(!board->isFoe(curr_x, curr_y, new_x, tempY)){
                if( (tempY == new_y && board->isFoe(curr_x, curr_y, new_x, tempY) ) || (tempY == new_y && board->isFree(new_x, tempY) ) ){
                    return true;
                }
                if(!board->isFree(new_x, tempY)){
                    return false;
                }
                tempY--;
            }
            if(tempY == new_y){
                return true;
            }
            return false;
        }

    } else if( new_y == curr_y ) {

        int tempX = curr_x;
        if(curr_x < new_x) { //
            tempX++;
            while(!board->isFoe(curr_x, curr_y, tempX, new_y)){
                if( ( tempX == new_x && board->isFoe(curr_x, curr_y, tempX, new_y) ) || (tempX == new_x && board->isFree(tempX, new_y) ) ){
                    return true;
                }
                if(!board->isFree(tempX, new_y)){
                    return false;
                }
                tempX++;
            }
            if(tempX == new_x){
                return true;
            }
            return false;
        } else if(curr_x > new_x) {
            tempX--;
            while(!board->isFoe(curr_x, curr_y, tempX, new_y)){
                if( ( tempX == new_x && board->isFoe(curr_x, curr_y, tempX, new_y) ) || (tempX == new_x && board->isFree(tempX, new_y) ) ){
                    return true;
                }
                if(!board->isFree(tempX, new_y)){
                    return false;
                }
                tempX--;
            }
            if(tempX == new_x){
                return true;
            }
            return false;
        }

    } else {
        return false;
    }

}