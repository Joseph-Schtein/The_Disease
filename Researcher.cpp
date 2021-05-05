#include "Researcher.hpp"

using namespace pandemic;

std::string Researcher::role(){
    return "Researcher";
}

Researcher& Researcher::discover_cure(const Color buildInside){
    int counter = 0;
    for(uint i = 0; i < inHand.size(); i++){
        if(buildInside == board.getCityColor(inHand.at(i))){
            counter++;
        }
    }

    if(counter >= 5){
        for(uint i = 0; i < inHand.size() && counter > 0; i++){
            if(buildInside == board.getCityColor(inHand.at(i))){
                inHand.erase(inHand.begin() + i);
                counter--;
            }
        }
    }
    return *this;
}