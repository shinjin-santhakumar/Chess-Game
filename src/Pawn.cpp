//
// Created by shinj on 12/2/2020.
//

#include "../headers/Piece.h"
#include "../headers/Pawn.h"


using namespace std;

//create pawn
Pawn::Pawn(int posX, int posY, bool color,string input){
    curr_x = posX;
    curr_y = posY;
    white = color;
    name = input;
    firstMove = true;
}


//verify that movement is valid
bool Pawn::movement(int new_x, int new_y, Board* board) {

    if(curr_x == new_x && curr_y == new_y) {return false;}
    if(white) {
        //WHITE CASES
        if (new_x == curr_x && new_y == curr_y - 1 && board->isFree(new_x, new_y)) {
            if(curr_y == 0){
                //create new queen and replace
            }
            firstMove = false;
            return true;
        } else if (new_x == curr_x && new_y == curr_y - 2 && board->isFree(new_x, new_y) && firstMove) {
            if(curr_y == 0){
                //create new queen and replace
            }
            firstMove = false;
            return true;
        } else if ( (new_x == curr_x - 1 || new_x == curr_x + 1) && new_y == curr_y - 1 && board->isFoe(curr_x, curr_y, new_x, new_y ) ) {
            if(curr_y == 0){
                //create new queen and replace
            }
            firstMove = false;
            return true;
        } else {
            return false;
        }
    } else {
        //BLACK CASES
        if (new_x == curr_x && new_y == curr_y + 1 && board->isFree(new_x, new_y)) {
            if(curr_y == 7){
                //create new queen and replace
            }
            firstMove = false;
            return true;
        } else if (new_x == curr_x && new_y == curr_y + 2 && board->isFree(new_x, new_y) && firstMove) {
            if(curr_y == 7){
                //create new queen and replace
            }
            firstMove = false;
            return true;
        } else if ( (new_x == curr_x - 1 || new_x == curr_x + 1) && new_y == curr_y + 1 && board->isFoe(curr_x, curr_y, new_x, new_y ) ) {
            if(curr_y == 7){
                //create new queen and replace
            }
            firstMove = false;
            return true;
        } else {
            return false;
        }
    }

}

