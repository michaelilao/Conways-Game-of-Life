//Michael Ilao ilaom

#include <algorithm>
#include <iostream>
#include <vector>

#include "GOL_Board.h"
#include "in_outReader.h"
#include "viewBoard.h"
typedef vector<vector<string>> boardArray;

int main() {

    in_outReader input;
    viewBoard view;
    string data = input.readInput("data//data1.txt");
    input.writeOutput("data//output1.txt", data);

    data = input.readInput("data//output1.txt");
    GOL_Board game(data);
    boardArray b= game.getBoardArray();
    for(int i = 0; i< 5; i++)
    {
        view.printBoard(b);
        game.nextMove();
        b = game.getBoardArray();

    }
    data = game.toString();
    input.writeOutput("data//output1.txt", data);

    return 0;
}
