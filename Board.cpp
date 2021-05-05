#include <fstream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <ostream>
#include <string>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"


using namespace pandemic;



Board::Board(){
    replaceEnumByString();
    std::string line;
    std::string cityName;
    std::string currentCityColor;
    std::string word;
    std::vector<std::string> neigbors;
    std::ifstream myfile;
    myfile.open("cities_map");
    while (std::getline(myfile, line)){
        bool newLine = true;
        bool insertColor = true;
        std::istringstream ss(line);
        while (ss >> word){
            if(newLine){
                cityName = word;
                newLine = false;
            }

            else if(insertColor){
                currentCityColor = word;
                insertColor = false;
            }

            else{
                neigbors.push_back(word);
            }
        } 
        
        cityStatus[cityName] = 0;
        
        
        if(currentCityColor == "Black"){
            cityColor.insert(std::make_pair(cityName, Color::Black));
        }

        else if(currentCityColor == "Blue"){
            cityColor.insert(std::make_pair(cityName, Color::Blue));;
        }

        else if(currentCityColor == "Yellow"){
            cityColor.insert(std::make_pair(cityName, Color::Yellow));;
        }

        else if(currentCityColor == "Red"){
            cityColor.insert(std::make_pair(cityName, Color::Red));;
        }

        connection.insert(std::make_pair(cityName, neigbors));

        neigbors.clear();
    }
}

std::unordered_map<City, std::string>& Board::getMap(){
    return cityToString;
}


unsigned int& Board::operator[](City name) {
    return this->cityStatus.at(this->cityToString.at(name));
}

std::ostream& pandemic::operator<<(std::ostream& os, const Board& board){
    return os;
}

bool Board::is_clean(){
    return true;
}

std::vector<std::string> Board::getNeighbors(std::string cityName){
    return connection.at(cityName);
}

bool Board::haveFacility(City cityName){
    return existReasearchFacility.at(cityName);
}

void Board::buildResearchFacility(City cityName){
    existReasearchFacility.at(cityName) = true;
}

Color Board::getCityColor(City cityName){
    return this->cityColor.at(cityToString.at(cityName));
}

bool Board::haveCure(Color colorType){
    return this->existCure.at(colorType);
} 


void Board::replaceEnumByString(){
    cityToString = {{City::Algiers, "Algiers"},
                    {City::Atlanta, "Atlanta"},
                    {City::Baghdad, "Baghdad"},
                    {City::Bangkok, "Bangkok"},
                    {City::Beijing, "Beijing"},
                    {City::Bogota, "Bogota"},
                    {City::BuenosAires, "BuenosAires"},
                    {City::Cairo, "Cairo"},
                    {City::Chennai, "Chennai"},
                    {City::Chicago, "Chicago"},
                    {City::Delhi, "Delhi"},
                    {City::Essen, "Essen"},
                    {City::HoChiMinhCity,"HoChiMinhCity"},
                    {City::HongKong, "HongKong"},
                    {City::Istanbul, "Istanbul"},
                    {City::Jakarta, "Jakarta"},
                    {City::Johannesburg, "Johannesburg"},
                    {City::Karachi, "Karachi"},
                    {City::Khartoum, "Khartoum"},
                    {City::Kinshasa, "Kinshasa"},
                    {City::Kolkata, "Kolkata"},
                    {City::Lagos, "Lagos"},
                    {City::Lima, "Lima"},
                    {City::London, "London"},
                    {City::LosAngeles, "LosAngeles"},
                    {City::Madrid, "Madrid"},
                    {City::Manila, "Manila"},
                    {City::MexicoCity, "MexicoCity"},
                    {City::Miami, "Miami"},
                    {City::Milan, "Milan"},
                    {City::Montreal, "Montreal"},
                    {City::Moscow, "Moscow"},
                    {City::Mumbai, "Mumbai"},
                    {City::NewYork, "NewYork"},
                    {City::Osaka, "Osaka"},
                    {City::Paris, "Paris"},
                    {City::Riyadh, "Riyadh"},
                    {City::SanFrancisco, "SanFrancisco"},
                    {City::Santiago, "Santiago"},
                    {City::SaoPaulo, "SaoPaulo"},
                    {City::Seoul,"Seoul"},
                    {City::Shanghai, "Shanghai"},
                    {City::StPetersburg, "StPetersburg"},
                    {City::Sydney, "Sydney"},
                    {City::Taipei, "Taipei"},
                    {City::Tehran, "Tehran"},
                    {City::Tokyo, "Tokyo"},
                    {City::Washington, "Washington"}};


    existReasearchFacility = {  {City::Algiers, false},
                                {City::Atlanta, false},
                                {City::Baghdad, false},
                                {City::Bangkok, false},
                                {City::Beijing, false},
                                {City::Bogota, false},
                                {City::BuenosAires, false},
                                {City::Cairo, false},
                                {City::Chennai, false},
                                {City::Chicago, false},
                                {City::Delhi, false},
                                {City::Essen, false},
                                {City::HoChiMinhCity,false},
                                {City::HongKong, false},
                                {City::Istanbul, false},
                                {City::Jakarta, false},
                                {City::Johannesburg, false},
                                {City::Karachi, false},
                                {City::Khartoum, false},
                                {City::Kinshasa, false},
                                {City::Kolkata, false},
                                {City::Lagos, false},
                                {City::Lima, false},
                                {City::London, false},
                                {City::LosAngeles, false},
                                {City::Madrid, false},
                                {City::Manila, false},
                                {City::MexicoCity, false},
                                {City::Miami, false},
                                {City::Milan, false},
                                {City::Montreal, false},
                                {City::Moscow, false},
                                {City::Mumbai, false},
                                {City::NewYork, false},
                                {City::Osaka, false},
                                {City::Paris, false},
                                {City::Riyadh, false},
                                {City::SanFrancisco, false},
                                {City::Santiago, false},
                                {City::SaoPaulo, false},
                                {City::Seoul,false},
                                {City::Shanghai, false},
                                {City::StPetersburg, false},
                                {City::Sydney, false},
                                {City::Taipei, false},
                                {City::Tehran, false},
                                {City::Tokyo, false},
                                {City::Washington, false}};  

    existCure = {{Color::Black, false},
                 {Color::Blue, false},
                 {Color::Yellow, false},
                 {Color::Red, false}};
         
}