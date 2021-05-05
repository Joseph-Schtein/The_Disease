#ifndef HEADER_MEDIC
#define HEADER_MEDIC

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic{

    class Medic : public Player{
        
        public:

        Medic(Board& board, const City currentCity): Player(board, currentCity){}

        Player& treat(const City treatCity) override;

        std::string role() override;
    };

}

#endif