#include "Medic.hpp"

using namespace pandemic;

std::string Medic::role(){
    return "Medic";
}

Medic& Medic::treat(const City treatCity){

  bool findCure = board.haveCure(board.getCityColor(treatCity));
    uint pandStatus = board[treatCity];
    if(pandStatus > 0 && treatCity == currentCity){
        board[treatCity] = 0;
    }

    else{
        throw "the disease is died already";
    }    

    return *this;
}