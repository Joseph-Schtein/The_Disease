#ifndef HEADER_FIELDDOCTOR
#define HEADER_FIELDDOCTOR

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic{

    class FieldDoctor : public Player{
        
        public:

        FieldDoctor(Board& board, const City currentCity): Player(board, currentCity){}

        FieldDoctor& treat(City treatCity) override;

        std::string role() override;
    };

}

#endif
