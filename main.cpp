/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

char pieceNames[] = {'P','R','B', 'k', 'Q', 'K'};
string alphabet = "abcdefghijklmnopqrstuvwxyz";

namespace util
{
    string pieceLookup(char abbrev) {
        string pieces[] = {"Pawn", "Rook", "Bishop", "Knight", "Queen", "King"};
        char *result = find(begin(pieceNames), end(pieceNames), abbrev);
        return pieces[*result];
    }
    
    string spaceLookup(int x, int y) {
        string temp = to_string(y);
        return alphabet.at(x) + temp;
    }
}

class Piece {
    public:
        char pieceName;
        int pos [2] = {0,0};
        int xPos = 0;
        int yPos = 0;
        bool isWhite = true;
        bool inPlay = false;
       
        Piece(char, bool);
        char getName() {return pieceName;}
        int getXPos() {return xPos;}
        int getYPos() {return yPos;}
        void move(int[]);
        void kill();
        void promote(char);
};

Piece::Piece(char name, bool color) {
    pieceName = name;
    isWhite = color;
    inPlay = true;
    pos[0] = xPos;
    pos[1] = yPos;
}

void Piece::move(int endPos[]) {
    xPos = endPos[0];
    yPos = endPos[1];
}

void Piece::kill() {
    inPlay = false;
}

void Piece::promote(char promoteTo) {
    if (((pieceName == 'P') && (isWhite == true) && (yPos == 8)) || ((pieceName == 'P') && (isWhite == false) && (yPos == 1))) {
        cout << "Promoted to " << util::pieceLookup(promoteTo);
        pieceName = promoteTo;
    }
}

class Space
{
    public:
        bool empty = true;
        bool isWhite = true;
        int xCoord = 0;
        int yCoord = 0;
    
};

class Board
{
    public:
        int x = 8;
        int y = 8;
        std::vector<std::vector<Space>> board(x, vector<Space>(y));
        
    Board ();
};

Board::Board() {
    bool boolVal = false;
    cout<<"Board";
    for(int i = 1; i < 9; i++) {
        for(int j = 1; j < 9; j++) {
            if(!boolVal) {
                board[i][j].isWhite = false;
                boolVal = !boolVal;
            }
            board[i][j].xCoord = j;
            board[i][j].yCoord = i;
        }
    }
}

string gamePrint(Board game) {
        for(int i = 1; i<9;i++) {
            for(int j=1;j<9;j++) {
                cout << "[" << game[i][j].xCoord << "," << game[i][j].yCoord << "]" << to_string(game[i][j].isWhite);
            }
            cout << "\n";
        }
}

int main()
{
    cout<<"Hello World";
    Board newgame;
    gamePrint(newgame);
    

    return 0;
}



