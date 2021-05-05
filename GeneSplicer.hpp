#ifndef HEADER_GENESPLICER
#define HEADER_GENESPLICER

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic{

    class GeneSplicer : public Player{
        
        public:

        GeneSplicer(Board& board, const City currentCity): Player(board, currentCity){}

        Player& discover_cure(const Color buildInside) override;

        std::string role() override;
    };

}

#endif