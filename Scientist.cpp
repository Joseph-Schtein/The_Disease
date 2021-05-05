#include "Scientist.hpp"

using namespace pandemic;

std::string Scientist::role(){
    return "Scientist";
}

Scientist& Scientist::discover_cure(const Color buildInside){
    if(board.haveFacility(currentCity)){
        int counter = 0;
        for(uint i = 0; i < inHand.size(); i++){
            if(buildInside == board.getCityColor(inHand.at(i))){
                counter++;
            }
        }

        if(counter >= neededCards){
            for(uint i = 0; i < inHand.size() && counter > 0; i++){
                if(buildInside == board.getCityColor(inHand.at(i))){
                    inHand.erase(inHand.begin() + i);
                    counter--;
                }
            }
        }
    }
    return *this;
}