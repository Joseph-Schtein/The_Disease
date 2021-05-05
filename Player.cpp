#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include <stdlib.h> 
#include <algorithm> 
#include <vector> 
#include <string>      

using namespace pandemic;

Player::Player(Board& board, const City name): board(board), currentCity(name){

    std::unordered_map<City, std::string> tmp = board.getMap();
                
    for(auto& x: tmp) {
        cards.push_back(x.first);
    }

    while(inHand.size() > 7){
        uint take = (uint)rand() % 47;
        City tmp = cards.at(take);
        take_card(tmp);
    }
}



Player& Player::fly_direct(City passTo){

    auto index = std::find(this->inHand.begin(), this->inHand.end(), passTo);
    if(index != inHand.end()){
        this->currentCity = passTo;
        int i = index - inHand.begin(); 
        inHand.erase(index);
    }

   else if(std::find(this->cards.begin(), this->cards.end(), passTo) != this->cards.end()){
        std::cout << "the needed card is not in the player hand" << std::endl;
    }

    return *this;
}

Player& Player::drive(City passTo){
    std::unordered_map<City, std::string> tmp = board.getMap();
    std::vector<std::string> neighbors = board.getNeighbors(tmp.at(currentCity));
    bool neig = false;
    std::string passToStr = tmp.at(passTo);
    for(unsigned int i = 0; i < neighbors.size(); i++){
        if(neighbors.at(i) == passToStr){
            currentCity = passTo;
        }

        else{
            throw "that city isn't can be reach";
        }
    }
    return *this;
}

Player& Player::fly_charter(City passTo){

    auto index = std::find(this->inHand.begin(), this->inHand.end(), currentCity);
    if(index != inHand.end()){
        this->currentCity = passTo;
        int i = index - inHand.begin(); 
        inHand.erase(index);
    }

    else if(std::find(this->cards.begin(), this->cards.end(), currentCity) != this->cards.end()){
        std::cout << "the needed card is not in the player hand" << std::endl;
    }

    return *this;
}

Player& Player::fly_shuttle(const City passTo){
    if(board.haveFacility(currentCity) && board.haveFacility(passTo)){
        currentCity = passTo;
    }

    else{
        std::cout << "We can not fly there because we can't" << std::endl;
    }

    return *this;
}

Player& Player::build(){
    auto index = std::find(this->inHand.begin(), this->inHand.end(), currentCity);
    if(index != inHand.end() && !board.haveFacility(currentCity)){
        board.buildResearchFacility(currentCity);
        int i = index - inHand.begin(); 
        inHand.erase(index);
    }

    else if(board.haveFacility(currentCity)){
        std::cout << "we build already facility here";
    }

    else if(std::find(this->cards.begin(), this->cards.end(), currentCity) != this->cards.end()){
        std::cout << "the needed card is not in the player hand" << std::endl;
    }


    return *this;
}

Player& Player::discover_cure(Color buildInside){
    if(board.haveFacility(currentCity)){
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
    }
    return *this;
}

Player& Player::treat(City treatCity){
    bool findCure = board.haveCure(board.getCityColor(treatCity));
    uint pandStatus = board[treatCity];
    if(pandStatus > 0 && treatCity == currentCity){
        if(!findCure){
            board[treatCity]--; 
        }

        else if(findCure){
            board[treatCity] = 0;
        }
    }

    else{
        throw "the disease is died already";
    }    

    return *this;
}

Player& Player::take_card(City newCard){     
    if(std::find(this->cards.begin(), this->cards.end(), newCard) != this->cards.end()){
        auto index = std::find(this->cards.begin(), this->cards.end(), newCard);
        uint tmp = index - cards.begin();
        inHand.push_back(cards.at(tmp));
        cards.erase(cards.begin() + tmp);  
    }
    return *this;
}