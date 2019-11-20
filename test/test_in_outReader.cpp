//Michael Ilao ilaom

#include "catch.h"
#include "in_outReader.h"



TEST_CASE( "tests for in_outReader" , "[in_outReader]" ) {

    in_outReader io;

  SECTION( "general tests for readInput" ){
    string correct = "0000011111\n";
    string test = io.readInput("test//testfiles//testdata1.txt");
    REQUIRE(test == correct);
    }

  SECTION( "exception tests for readInput" ){
      REQUIRE_THROWS_AS( io.readInput("test//testfiles//invalidfile.txt"), std::invalid_argument);
    }

  SECTION( "general tests for writeOutput" ){
    string correct = "testforwriteOutput\n";
    io.writeOutput("test//testfiles//testoutdata2.txt", correct);
    string test = io.readInput("test//testfiles//testoutdata2.txt");
    REQUIRE(test == correct);
  }

}
