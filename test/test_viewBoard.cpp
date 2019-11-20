//Michael Ilao ilaom

#include "catch.h"
#include "viewBoard.h"
#include "in_outReader.h"
#include "GOL_Board.h"



TEST_CASE( "tests for viewBoard" , "[viewBoard]" ) {

    viewBoard view;
    boardArray board;

    SECTION( "exception test for printBoard" ){
        REQUIRE_THROWS_AS( view.printBoard(board), std::out_of_range);
      }



}
