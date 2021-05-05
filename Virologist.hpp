#ifndef HEADER_VIROLOGIST
#define HEADER_VIROLOGIST

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic{

    class Virologist : public Player{
        
        public:

        Virologist(Board& board, const City currentCity): Player(board, currentCity){}

        Player& treat(const City treatCity) override;

        std::string role() override;
    };

}

#endif