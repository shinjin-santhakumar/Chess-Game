//
// Created by shinj on 12/2/2020.
//

#include "../headers/GameManager.h"

void GameManager::move() {
    Piece* pieceToMove=nullptr;
    // select player, with promper input and ability to pick different piece
    printPlayerTurn();
    bool wantToRetry=false;
    do{
        pieceToMove = selectPiecePrompt();
        wantToRetry = selectDifferentPiece();
    } while (wantToRetry);

    // user indicates desired place on board to move
    int newX=0;
    int newY=0;
    bool isValid=false;
    bool isValidX = false;
    cout << "Select destination: (x,y) " << endl;
    do{
        do{
            if(!isValidX){
                cout << "x-coordinate: " << endl;
                while(!(cin >> newX)){
                    cout << "x-coordinate: " << endl;
                    cin.clear();
                    cin.ignore(1000,'\n');
                }
                isValidX = true;
            }
            cout << "y-coordinate: " <<endl;
            isValidX = false;
            cin.clear();
            cin.ignore(1000,'\n');
        }
        while(!(cin>>newY));
    } while (!pieceToMove->movement(newX, newY, gameboard));

    // update board
    gameboard->updateBoard(newX, newY, pieceToMove);
    check(pieceToMove);



    if(isWhiteTurn){
        isWhiteTurn=false;
    }else{
        isWhiteTurn =true;
    }
}

bool  GameManager::selectDifferentPiece(){
    char retryInput;
    do{
        cout << "press p to confirm this piece, press r to select diff"<<endl;
        while(!(cin >> retryInput)){
            cout << "wrong input!"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }while(retryInput != 'p' && retryInput !='r');
    if(retryInput == 'p')
        return false;
    else
        return true;
}

Piece* GameManager::selectPiecePrompt(){
    bool validX = false;
    int xPos=0;
    int yPos=0;
    cout << "Select Piece: (x,y) " << endl;
    do {
        //int temp;
        //while(cin >> temp)
        do {
            if (!validX) {
                cout << "x-coordinate: " << endl;
                while (!(cin >> xPos)) {
                    cout << "x-coordinate: " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                for(int i=0; i<=7;i++){
                    if( gameboard->getBoard()[xPos][i] != nullptr && gameboard->getBoard()[xPos][i]->getColor() == isWhiteTurn)
                        validX=true;
                }

            }
            cout << "y-coordinate: " << endl;
            validX = false;
            cin.clear();
            cin.ignore(1000, '\n');
        }while (!(cin >> yPos));
    } while (!isValidSelectPiece(xPos, yPos));

    return gameboard->getBoard()[xPos][yPos];
}

bool GameManager::quitPrompt(){
    char input;
    do{
        cout << "press p to make move, press q to quit"<<endl;
        while(!(cin >> input)){
            cout << "wrong input!"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }while(input != 'p' && input !='q');

    if(input == 'p')
        return true;
    else
        return false;
}

void GameManager::printPlayerTurn(){
    string playerTurn = "";
    playerTurn = (isWhiteTurn == true ? "Player1" : "Player2");
    cout << "It is " << playerTurn << "'s turn now" << endl;
}

GameManager::GameManager(){
    isWhiteTurn = true;  // white gets first move
    gameboard = new Board(); // initialize gameboard with default pieces & positions
    gameIsOver = false;  //game has just begun
    whiteIsInCheck = false;
    blackIsInCheck = false;
    userWantsToPlay= true;
}

void GameManager::startGame(){
    while(!gameIsOver && userWantsToPlay){
        gameboard->print();

        if(whiteIsInCheck || blackIsInCheck) {
            if(whiteIsInCheck){
                cout << " =========================================" << endl;
                cout << "                 BLACK WINS               " << endl;
                cout << " =========================================" << endl;
            } else {
                cout << " =========================================" << endl;
                cout << "                 WHITE WINS               " << endl;
                cout << " =========================================" << endl;
            }
            return;
        }

        userWantsToPlay = quitPrompt();
        if(userWantsToPlay)
            move();

    }
}



// when we implement actual "checks", we will need to include
// limitations and more conditionals within move()

bool GameManager::isValidSelectPiece(int startX, int startY){
    // out of bounds
    if(startX > 7 || startX < 0 || startY > 7 || startY < 0){
        return false;
    }
    // no piece exists at location
    if(gameboard->getBoard().at(startX).at(startY) == nullptr){
        return false;
    }

    // cannot move opponents pieces
    Piece* selectPiece = gameboard->getBoard().at(startX).at(startY);

    if(isWhiteTurn && !selectPiece->getColor()){
        return false;
    }
    else if(!isWhiteTurn && selectPiece->getColor()){
        return false;
    }

    // piece has no possible moves
    /*
    if(!selectPiece.hasPossibleMoves()){
        return false;
    }
    */

    return true;
}

void GameManager::check(Piece* movePiece) {
    if(isWhiteTurn){
        for(int i = 0; i < 8; i++ ){
            for(int j = 0; j < 8; j++){
                if(gameboard->getBoard()[i][j] != nullptr && gameboard->getBoard()[i][j]->getName() == "BK"){
                    if(movePiece->movement(i,j, gameboard) ){
                         blackIsInCheck = true;
                    }
                }
            }
        }
    } else {
        for(int i = 0; i < 8; i++ ){
            for(int j = 0; j < 8; j++){
                if(gameboard->getBoard()[i][j] != nullptr && gameboard->getBoard()[i][j]->getName() == "WK"){
                    if(movePiece->movement(i,j, gameboard) ){
                        whiteIsInCheck = true;
                    }
                }
            }
        }
    }

}

