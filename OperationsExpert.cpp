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
        std::cout << "we build already facility here";
    }



    return *this;
}
