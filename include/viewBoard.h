//Michael Ilao ilaom

/**
 *  \file viewBoard.h
 *  \author Michael Ilao
 *  \brief graphic representation of a game board
 */
#ifndef VIEW_BOARD
#define VIEW_BOARD

#include <fstream>
#include <string>
#include <vector>

using namespace std;
/**
 * \brief defines a 2D array
 */
typedef vector<vector<string>> boardArray;

/**
 *  \brief Class defining a function to print a game board.
 */
class viewBoard
{
  public:
      /**
       *  \brief Constructs an object to view game boards
       */
    viewBoard();
    /**
     *  \brief prints a 2D game board
     *  \param game A 2D array representation of a current board
     */
    void printBoard(boardArray game);

  };
#endif
