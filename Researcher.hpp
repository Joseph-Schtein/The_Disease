#ifndef HEADER_RESEARCHER
#define HEADER_RESEARCHER

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic{

    class Researcher : public Player{
        
        public:

        Researcher(Board& board, const City currentCity): Player(board, currentCity){}

        Researcher& discover_cure(const Color buildInside) override;

        std::string role() override;
    };

}

#endif