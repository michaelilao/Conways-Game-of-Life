//Michael Ilao ilaom

/**
 *  \file in_outReader.h
 *  \author Michael Ilao
 *  \brief Module that reads and writes data
 */

#ifndef IN_OUT_READER
#define IN_OUT_READER

#include <fstream>
using namespace std;

/**
 *  \brief Class defining input and output Functions
 *  \details Reads an input game into a string and outputs a string into a text file
 */
class in_outReader
{
  public:
   /**
    *  \brief constructs an input/output reader
    */
    in_outReader();

    /**
     *  \brief reads a file into a string
     *  \param path Path to the file
     *  \return a string representation on the file
     */
    string readInput(string path);

    /**
     *  \brief outputs a string into a text file
     *  \param fileName name/destination file to be written to
     *  \param data data to be written to the file
     */
    void writeOutput(string fileName, string data);

};
#endif
