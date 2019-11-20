//Michael Ilao ilaom

/**
 *  \file GOL_Board.h
 *  \author Michael Ilao
 *  \brief Module that simulates John Conway's Game of Life
 */

#ifndef GAME_OF_LIFE_BOARD
#define GAME_OF_LIFE_BOARD

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
/**
 * \brief defines a 2D array
 */
typedef vector<vector<string>> boardArray;


/**
 *  \brief Class defining the GameBoard and its functions
 *  \details Game Board for John Conway's Game of Life
 */
class GOL_Board
{
  public:
      /**
       *  \brief Constructs a new game board
       *  \details Sets starting position for game board from the String data
       *  \param data a string of 0's and 1's to be read into an array
       */
    GOL_Board(string data);

    /**
     *  \brief advances the move to next game board position
     *  \details based on the rules fills in and deletes cells
     */
    void nextMove();

    /**
     *  \brief converts game board to a string
     *  \return a string representation of the game board
     */
    string toString();

    /**
     *  \brief returns the 2D boad array
     *  \return the gameBoardArray
     */
    boardArray getBoardArray();
  private:
      boardArray game;
      boardArray Updatedgame;
      int xSize(string data);
      int ySize(string data);
      bool checkStatus(string e,int i,int j);
      bool checkValid(int x, int y, int i, int j);
      bool checkAlive(string e, int aliveNeighbours);




  };
#endif
