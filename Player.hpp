#ifndef HEADER_PLAYER
#define HEADER_PLAYER

#include <vector>
#include <unordered_map>

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"


namespace pandemic{

    class Player{
        protected:
            City currentCity;
            Board board;
            std::vector<City> cards;
            std::vector<City> inHand;

        public:

            Player(Board& board, const City name);

            Player& drive(City passTo);

            virtual Player& fly_direct(const City passTo);

            Player& fly_charter(const City passTo);

            Player& fly_shuttle(const City passTo);

            virtual Player& build();

            virtual Player& discover_cure(Color buildInside);

            virtual Player& treat(City treatCity);

            virtual std::string role() = 0;

            Player& take_card(City newCard);
    };

}

#endif