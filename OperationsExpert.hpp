#ifndef HEADER_OPERATIONEXPERT
#define HEADER_OPERATIONEXPERT

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"


namespace pandemic{

    class OperationsExpert : public Player{
        
        public:

        OperationsExpert(Board& board, const City currentCity): Player(board, currentCity){}

        OperationsExpert& build() override;

        std::string role() override;
    };

}

#endif