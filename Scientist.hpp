#ifndef HEADER_SCIENTIST
#define HEADER_SCIENTIST

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic{

    class Scientist : public Player{
        int neededCards;

        public:

        Scientist(Board& board, const City currentCity, int operationCards): 
        Player(board, currentCity), neededCards(operationCards){}

        Scientist& discover_cure(const Color buildInside) override;

        std::string role() override;
    };

}

#endif