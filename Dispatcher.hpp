#ifndef HEADER_DISPATCHER
#define HEADER_DISPATCHER

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic{

    class Dispatcher : public Player{
        
        public:

        Dispatcher(Board& board, const City currentCity): Player(board, currentCity){}

        Dispatcher& fly_direct(const City passTo) override;

        std::string role() override;
    };

}

#endif