//
// Created by shinj on 12/6/2020.
//



#include "../headers/Piece.h"

Queen::Queen(int posX, int posY, bool color, string input){
    curr_x = posX;
    curr_y = posY;
    white = color;
    name = input;
}


bool Queen::movement(int destX, int destY, Board* board){

    /*
    currx is the current piece row
    curry is the current piece column
    */
    //vertical for rooks
    if(curr_x == destX && curr_y == destY) {return false;}

    if(destX == curr_x){
        int tempY = curr_y;
        if(curr_y < destY) { //
            tempY++;
            while(!board->isFoe(curr_x, curr_y, destX, tempY)){
                if( ( tempY == destY && board->isFoe(curr_x, curr_y, destX, tempY) ) || (tempY == destY && board->isFree(destX, tempY) ) ){
                    return true;
                }
                if(!board->isFree(destX, tempY)){
                    return false;
                }
                tempY++;
            }
            if(tempY == destY){
                return true;
            }
            return false;
        } else if(curr_y > destY) {
            tempY--;
            while(!board->isFoe(curr_x, curr_y, destX, tempY)){
                if( (tempY == destY && board->isFoe(curr_x, curr_y, destX, tempY) ) || (tempY == destY && board->isFree(destX, tempY) ) ){
                    return true;
                }
                if(!board->isFree(destX, tempY)){
                    return false;
                }
                tempY--;
            }
            if(tempY == destY){
                return true;
            }
            return false;
        }

    } else if( destY == curr_y ) {

        int tempX = curr_x;
        if(curr_x < destX) { //
            tempX++;
            while(!board->isFoe(curr_x, curr_y, tempX, destY)){
                if( ( tempX == destX && board->isFoe(curr_x, curr_y, tempX, destY) ) || (tempX == destX && board->isFree(tempX, destY) ) ){
                    return true;
                }
                if(!board->isFree(tempX, destY)){
                    return false;
                }
                tempX++;
            }
            if(tempX == destX){
                return true;
            }
            return false;
        } else if(curr_x > destX) {
            tempX--;
            while(!board->isFoe(curr_x, curr_y, tempX, destY)){
                if( ( tempX == destX && board->isFoe(curr_x, curr_y, tempX, destY) ) || (tempX == destX && board->isFree(tempX, destY) ) ){
                    return true;
                }
                if(!board->isFree(tempX, destY)){
                    return false;
                }
                tempX--;
            }
            if(tempX == destX){
                return true;
            }
            return false;
        }

    } else if(curr_x > destX && curr_y < destY) { //diagonal backward right
        //cout << "diagonal backward right" << endl;
        int a = curr_x, b = curr_y + 1;
        for(; a > destX; a --) { //8
            for(; b < destY; b ++) { //8
                a -= 1;
                //cout << "location: " << a << ", " << b <<endl;
                //checks the one before destx, desty
                if(board->isFree(a, b) == false && (a != destX && b != destY)) {
                    return false;
                }

            }
        }
        //cout << "location1: " << a << ", " << b <<endl;
        if(board->isFoe(curr_x, curr_y, destX, destY) == true && (a == destX && b == destY)) {
            //cout << "attack" << endl;
            return true;
        }
        if(board->isFree(a, b) == false) { //checks the last x, y
            return false;
        }
        if(a != destX || b != destY){cout << "false" << endl; return false;}
    } else if(curr_x >= destX && curr_y >= destY) { //diagonal backward left
        //cout << "diagonal backward left" << endl;
        int a = curr_x, b = curr_y - 1;
        for(; a > destX; a --) { //8
            for(; b > destY; b --) { //8
                a -= 1;
                //cout << "location: " << a << ", " << b <<endl;
                //checks all spot before the last x, y
                if(board->isFree(a, b) == false) {
                    return false;
                }
            }
        }
        //cout << "location2: " << a << ", " << b <<endl;
        if(board->isFoe(curr_x, curr_y, destX, destY) == true && (a == destX && b == destY)) {
            //cout << "attack" << endl;
            return true;
        }
        if(board->isFree(a, b) == false) { //checks the last x, y
            return false;
        }
        if(a != destX || b != destY){cout << "false" << endl; return false;}
    } else if(curr_x < destX && curr_y < destY) { //diagonal forward left
        //cout << "diagonal forward left" << endl;
        int a = curr_x, b = curr_y + 1;
        for(; a < destX; a ++) { //8
            for(; b < destY; b ++) { //8
                a += 1;
                //cout << "location: " << a << ", " << b <<endl;
                if(board->isFree(a, b) == false && (a != destX && b != destY)) {
                    return false;
                }
            }
        }
        //cout << "location3: " << a << ", " << b <<endl;
        if(board->isFoe(curr_x, curr_y, destX, destY) == true && (a == destX && b == destY)) {
            //cout << "attack" << endl;
            return true;
        }
        if(board->isFree(a, b) == false) { //checks the last x, y
            return false;
        }
        if(a != destX || b != destY){cout << "false" << endl; return false;}

    } else if(curr_x < destX && curr_y > destY) { //diagonal forward right
        //cout << "diagonal forward right" << endl;
        int a = curr_x, b = curr_y - 1;
        for(; a < destX; a ++) { //8
            for(; b > destY; b --) { //8
                a += 1;
                //cout << "location: " << a << ", " << b <<endl;
                if(board->isFree(a, b) == false && (a != destX && b != destY)) {
                    return false;
                }
            }
        }
        //cout << "location4: " << a << ", " << b <<endl;
        if(board->isFoe(curr_x, curr_y, destX, destY) == true && (a == destX && b == destY)) {
            //cout << "attack" << endl;
            return true;
        }
        if(board->isFree(a, b) == false) { //checks the last x, y
            return false;
        }
        if(a != destX || b != destY){cout << "false" << endl; return false;}

    } else {
        return false;
    }

    return true;

}