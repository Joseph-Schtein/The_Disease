#include "GeneSplicer.hpp"

using namespace pandemic; 

GeneSplicer& GeneSplicer::discover_cure(Color buildInside){
    if(board.haveFacility(currentCity)){
        int counter = 0;
        for(uint i = 0; i < inHand.size(); i++){
            counter++;   
        }

        if(counter >= 5){
            while(counter > 0){
                inHand.pop_back();
                counter--;
            
            }
        }
    }
    return *this;
}

std::string GeneSplicer::role(){
    return "GeneSplicer";
}

