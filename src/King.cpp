//
// Created by shinj on 12/5/2020.
//
#include "../headers/Piece.h"

King::King(int posX, int posY, bool color,string input){
    curr_x = posX;
    curr_y = posY;
    white = color;
    name = input;
}

bool King::movement(int new_x, int new_y, Board *board) {
    /*x changes but y doesnt captures nothing*/
    if(curr_x == new_x && curr_y == new_y) {return false;}
    if( (new_x - 1 == curr_x || new_x + 1 == curr_x ) && curr_y == new_y && board->isFree(new_x, new_y) ) {
        return true;
    }
        /*y changes but x doesnt captures nothing*/
    else if ( new_x == curr_x && (curr_y == new_y - 1 || curr_y == new_y + 1) && board->isFree(new_x, new_y) ) {
        return true;
    }
        /*both x and y change*/
    else if( ( (new_x - 1 == curr_x  && new_y - 1 == curr_y ) || (new_x - 1 == curr_x && new_y + 1 == curr_y ) || (new_x + 1 == curr_x && new_y - 1 == curr_y) || (new_x + 1 == curr_x && new_y + 1 == curr_y ) ) && board->isFree(new_x, new_y)  ) {
        return true;
    }
    //attacking
    //x changes
    else if( (new_x - 1 == curr_x || new_x + 1 == curr_x ) && curr_y == new_y && board->isFoe(curr_x, curr_y, new_x, new_y) ) {
        return true;
    } //Y changes
    else if ( new_x == curr_x && (curr_y == new_y - 1 || curr_y == new_y + 1) && board->isFoe(curr_x, curr_y, new_x, new_y) ) {
        return true;
    } else if( ( (new_x - 1 == curr_x  && new_y - 1 == curr_y ) || (new_x - 1 == curr_x && new_y + 1 == curr_y ) || (new_x + 1 == curr_x && new_y - 1 == curr_y) || (new_x + 1 == curr_x && new_y + 1 == curr_y ) ) && board->isFoe(curr_x, curr_y, new_x, new_y)  ) {
        return true;
    } else {
        return false;
    }

}