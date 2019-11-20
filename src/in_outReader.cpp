//Michael Ilao ilaom
#include "in_outReader.h"
#include <fstream>
using namespace std;
#include <iostream>


in_outReader::in_outReader()
{
}

string in_outReader::readInput(string path)
{
  string line ="";
  string array = "";
  ifstream myfile(path);
  if (myfile.is_open())
  {
    while (getline (myfile,line))
      array = array+ line +'\n';
    myfile.close();
  }
  else
  throw std::invalid_argument("Invalid path argument");

  return array;
}

void in_outReader::writeOutput(string fileName, string data)
{
    ofstream myfile;
    myfile.open (fileName);
    myfile << data;
    myfile.close();
}
