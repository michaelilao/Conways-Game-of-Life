//Michael Ilao ilaom

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "viewBoard.h"
using namespace std;

viewBoard::viewBoard()
{}

void viewBoard::printBoard(boardArray game)
{
    if(game.size() == 0)
        throw std::out_of_range("Board cannot be empty");
    for(int j = 0; j < game.size(); j++)
    {
        if(game[j].size() == 0)
            throw std::out_of_range("Board cannot be empty");
    }
    vector<string> line;
    cout<<"\n__BOARD__\n";
    for(int i = 0;i<game.size();i++)
    {
        line = game[i];
        for(int j = 0;j<line.size();j++)
        {
            cout<<line[j]<<" ";
        }
        cout << "\n";
    }
}
