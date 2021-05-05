#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

TEST_CASE("Initilize players"){

    Board board;
    board[City::Istanbul] = 5;
    board[City::Shanghai] = 2;
    board[City::BuenosAires] = 1;
    board[City::Cairo] = 3;
    board[City::NewYork] = 6;
    board[City::SaoPaulo] = 4;
    board[City::Lagos] = 4;
    board[City::Khartoum] = 1;
    Medic someone {board, City::BuenosAires};

    CHECK(board[City::Istanbul] == 5);
    CHECK(board[City::Shanghai] == 2);
    CHECK(board[City::BuenosAires] == 1);
    CHECK(board[City::Cairo] == 3);
    CHECK(board[City::NewYork] == 6);

    CHECK_THROWS(someone.drive(City::Cairo));
    CHECK_NOTHROW(someone.drive(City::SaoPaulo));
    CHECK_NOTHROW(someone.drive(City::Lagos));
    CHECK_THROWS(someone.drive(City::Cairo));
    CHECK_NOTHROW(someone.drive(City::Khartoum));
    CHECK_NOTHROW(someone.drive(City::Cairo));

    CHECK_THROWS(someone.treat(City::Cairo));
    CHECK_NOTHROW(someone.take_card(City::Cairo));
    CHECK(board[City::Cairo] != 0);
    CHECK_NOTHROW(someone.treat(City::Cairo));
    CHECK(board[City::Cairo] == 0);
    
}

TEST_CASE("Check if we throw cards"){

    Board board;
    board[City::Istanbul] = 5;
    board[City::Shanghai] = 2;
    board[City::BuenosAires] = 1;
    board[City::Cairo] = 3;
    board[City::NewYork] = 6;
    board[City::SaoPaulo] = 4;
    board[City::Lagos] = 4;
    board[City::Khartoum] = 1;
    board[City::Kinshasa] = 2;
    board[City::MexicoCity] = 3;
    board[City::HoChiMinhCity] = 1;
    board[City::Chicago] = 1;
    Virologist someone {board, City::Chicago};
    CHECK_NOTHROW(someone.treat(City::Chicago));
    CHECK_NOTHROW(someone.drive(City::Atlanta));
    CHECK_THROWS(someone.treat(City::Atlanta));
    CHECK_THROWS(someone.treat(City::Atlanta));
    CHECK_THROWS(someone.fly_shuttle(City::London));
}

