//Michael Ilao ilaom
#include "catch.h"
#include "GOL_Board.h"
#include "in_outReader.h"
#include "viewBoard.h"



TEST_CASE( "tests for GOL_Board" , "[GOL_Board]" ) {

   in_outReader io;
   string test = io.readInput("test//testfiles//testdata2.txt");

   vector<string> line;
   boardArray correctGame;
   for(int i = 0; i<test.length(); i++)
   {
       string element = test.substr(i,1);
       if(test.substr(i,1) == "1" || test.substr(i,1)=="0")
           line.push_back(element);
       if(line.size() == 4)
       {
           correctGame.push_back(line);
           line.clear();
       }
   }
   SECTION( "general tests for GOL_Board functionality" ){
       string test = io.readInput("test//testfiles//testdata4.txt");
       GOL_Board game(test);
       game.nextMove();
       game.nextMove();
       game.nextMove();
       io.writeOutput("test//testfiles//testoutdata1.txt",game.toString());
       GOL_Board contGame(game.toString());
       REQUIRE(contGame.getBoardArray() == game.getBoardArray());
    }

  SECTION( "general tests for GOL_Board constructor" ){
      GOL_Board game(test);
       boardArray test = game.getBoardArray();
       REQUIRE(test == correctGame);
    }

    SECTION( "general tests for nextMove" ){
        string test = io.readInput("test//testfiles//testdata4.txt");
        GOL_Board game(test);
         game.nextMove();
         game.nextMove();
         game.nextMove();
         REQUIRE(game.getBoardArray()== GOL_Board(io.readInput("test//testfiles//testdata3.txt")).getBoardArray());
      }


      SECTION( "general tests for toString" ){
          string data = io.readInput("test//testfiles//testdata4.txt");
          GOL_Board game(data);
          string test = game.toString();
          GOL_Board testing(test);
          REQUIRE(game.getBoardArray() == game.getBoardArray());
        }
 SECTION("general tests for getBoardArray"){
     REQUIRE(correctGame == GOL_Board(test).getBoardArray());
 }



}
