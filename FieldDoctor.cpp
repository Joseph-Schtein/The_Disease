#include "FieldDoctor.hpp"
#include <string>

using namespace pandemic;

std::string FieldDoctor::role(){
    return "FieldDoctor";
}


FieldDoctor& FieldDoctor::treat(City treatCity){
    std::unordered_map<City, std::string> tmp = board.getMap();
    std::vector<std::string> neighbors = board.getNeighbors(tmp.at(treatCity));
    bool neig = false;
    std::string treatCityToStr = tmp.at(treatCity);
    for(unsigned int i = 0; i < neighbors.size(); i++){
        if(neighbors.at(i) == treatCityToStr){
            this->board[treatCity]--;
        }

        else{
            throw "that city isn't can be reach";
        }
    }

    return *this;
}