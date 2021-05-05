#include "Virologist.hpp"
#include <algorithm>

using namespace pandemic;

std::string Virologist::role(){
    return "Virologist";
} 

Virologist& Virologist::treat(City treatCity){
    bool findCure = board.haveCure(board.getCityColor(treatCity));
    uint pandStatus = board[treatCity];

    if(pandStatus > 0){
        if(treatCity == currentCity){    
            if(!findCure){
                board[treatCity]--; 
            }

            else if(findCure){
                board[treatCity] = 0;
            }
        }

        else{
            auto index = std::find(inHand.begin(), inHand.end(), treatCity);
            if(index != inHand.end()){
                uint i = index -inHand.begin();
                if(!findCure){
                    inHand.erase(inHand.begin()+i);
                    board[treatCity]--;
                }

                else{
                    board[treatCity] = 0;
                }
            }
        }
    }

    else{
        throw "the disease is died already";
    }    

    return *this;
}