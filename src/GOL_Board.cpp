//Michael Ilao ilaom
#include "GOL_Board.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//public
GOL_Board::GOL_Board(string data)
{
    int xArrSize = xSize(data);
    int yArrSize = ySize(data);
    vector<string> line;

    for(int i = 0; i<data.length(); i++)
    {
        string element = data.substr(i,1);
        if(data.substr(i,1) == "1" || data.substr(i,1)=="0")
        {
            line.push_back(element);
        }
        if(line.size() == xArrSize)
        {
            this->game.push_back(line);
            line.clear();
        }
    }
    this->Updatedgame = this->game;
}

void GOL_Board::nextMove()
{
    vector<string> line;
    bool status;
    for(int i = 0;i<this->game.size();i++)
    {
        line = this->game[i];
        for(int j = 0;j<line.size();j++)
        {
            string e = line[j];
            status = checkStatus(e,i,j);
            if(status)
                this->Updatedgame[i][j] = "1";
            else
                this->Updatedgame[i][j] = "0";

        }
    }
    this->game = Updatedgame;
}

string GOL_Board::toString()
{
    string data = "";
    for(int i = 0;i<this->game.size();i++)
    {
        for(int j = 0; j<this->game[i].size();j++)
        {
            data = data + this->game[i][j] + " ";
        }
        data = data + "\n";
    }
    return data;
}

boardArray GOL_Board::getBoardArray()
{
    return this->game;
}

//private
int GOL_Board::xSize(string data)
{
    int x = 0;
    for(int i = 0; i<data.length();i++)
    {
        if(data.substr(i,1) == "0" || data.substr(i,1) == "1")
            x++;
        if(data.substr(i,1) == "\n")
            break;
    }
    return x;
}

int GOL_Board::ySize(string data)
{
    int y = 0;
    for(int i = 0; i<data.length();i++)
    {
        if(data.substr(i,1) == "\n")
            y++;
    }
    return y;
}

bool GOL_Board::checkStatus(string e,int i,int j)
{
    int aliveNeighbours = 0;

    for(int x = i-1; x<i+2; x++)
    {
        for(int y = j-1; y<j+2;y++)
        {
            if(checkValid(x,y,i,j))
            {
                if(this->game[x][y] == "1")
                    aliveNeighbours++;

            }
        }
    }
    return checkAlive(e, aliveNeighbours);

}
bool GOL_Board::checkValid(int x, int y, int i, int j)
{
    int xUpperBound = this->game.size();
    int yUpperBound = this->game[0].size();
    return (x > -1 && y >-1) && (x < xUpperBound && y < yUpperBound) && !(x==i && y ==j);
}
bool GOL_Board::checkAlive(string e, int aliveNeighbours)
{
    if(e == "1" && (aliveNeighbours == 2 || aliveNeighbours == 3))
        return true;
    else if(e == "0" && aliveNeighbours == 3)
        return true;
    else
        return false;
}
