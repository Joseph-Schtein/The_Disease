#include "OperationsExpert.hpp"



using namespace pandemic;

std::string OperationsExpert::role(){
    return "OperationsExpert";
}

OperationsExpert& OperationsExpert::build(){
    if(!board.haveFacility(currentCity)){
        board.buildResearchFacility(currentCity);
    }
    

    else{
        throw std::invalid_argument("we build already facility here");
    }



    return *this;
}
