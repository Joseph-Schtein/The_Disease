#include <fstream>
#include <iterator>
#include <sstream>
#include <algorithm>

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
    myfile.open("cities_map.txt");
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
            }

            else{
                neigbors.push_back(word);
            }
        } 
        
        cityStatus[cityName] = 0;
        
        if(currentCityColor == "Black")
            cityColor[cityName] = Color::Black;

        else if(currentCityColor == "Blue")
            cityColor[cityName] = Color::Blue;
        
        else if(currentCityColor == "Yellow")
            cityColor[cityName] = Color::Yellow;

        else if(currentCityColor == "Red")
            cityColor[cityName] = Color::Red;

        connection[cityName] = neigbors;

        neigbors.clear();

    }

}

std::unordered_map<City, std::string>& Board::getMap(){
    return cityToString;
}


unsigned int& Board::operator[](City name) {
    return this->cityStatus.at(this->cityToString.at(name));
}

void Board::operator=(int value){
    
}

std::ostream& operator<<(std::ostream& os, Board& board){
    
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
    std::string tmp = cityToString.at(cityName);
    return cityColor.at(tmp);
}

bool Board::haveCure(Color colorType){
    return existCure.at(colorType);
} 


void Board::replaceEnumByString(){
    cityToString[City::Algiers] = "Algiers";
    cityToString[City::Atlanta] = "Atlanta";
    cityToString[City::Bogota] = "Bogota";
    cityToString[City::BuenosAires] = "BuenosAires";
    cityToString[City::Baghdad] = "Baghdad";
    cityToString[City::Beijing] = "Beijing";
    cityToString[City::Cairo] = "Cairo";
    cityToString[City::Chennai] = "Chennai";
    cityToString[City::Chicago] = "Chicago";
    cityToString[City::Delhi] = "Delhi";
    cityToString[City::Essen] = "Essen";
    cityToString[City::HongKong] = "HongKong";
    cityToString[City::Istanbul] = "Istanbul";
    cityToString[City::Jakarta] = "Jakarta";
    cityToString[City::Kinshasa] = "Kinshasa";
    cityToString[City::Kolkata] = "Kolkata";
    cityToString[City::Lagos] = "Lagos";
    cityToString[City::London] = "London";
    cityToString[City::MexicoCity] = "MexicoCity";
    cityToString[City::Manila] = "Manila";
    cityToString[City::Miami] = "Miami";
    cityToString[City::Montreal] = "Montreal";
    cityToString[City::Moscow] = "Moscow";
    cityToString[City::Mumbai] = "Mumbai";
    cityToString[City::NewYork] = "NewYork";
    cityToString[City::Osaka] = "Osaka";
    cityToString[City::Paris] = "Paris";
    cityToString[City::Riyadh] = "Riyadh";
    cityToString[City::SanFrancisco] = "SanFrancisco";
    cityToString[City::Santiago] = "Santiago";
    cityToString[City::Shanghai] = "Shanghai";
    cityToString[City::Sydney] = "Sydney";
    cityToString[City::Taipei] = "Taipei";
    cityToString[City::Tehran] = "Tehran";
    cityToString[City::Tokyo] = "Tokyo";
    cityToString[City::StPetersburg] = "StPetersburg";
    cityToString[City::HoChiMinhCity] = "HoChiMinhCity";
    cityToString[City::Johannesburg] = "Johannesburg";
    cityToString[City::Karachi] = "Karachi";
    cityToString[City::Khartoum] = "Khartoum";
    cityToString[City::SaoPaulo] = "SaoPaulo";
    cityToString[City::Washington] = "Washington";
    cityToString[City::Madrid] = "Madrid";
    cityToString[City::Seoul] = "Seoul";
    cityToString[City::LosAngeles] = "LosAngeles";
    cityToString[City::Milan] = "Milan";
    cityToString[City::Lima] = "Lima";

    existReasearchFacility[City::Algiers] = false;
    existReasearchFacility[City::Atlanta] = false;
    existReasearchFacility[City::Bogota] = false;
    existReasearchFacility[City::BuenosAires] = false;
    existReasearchFacility[City::Baghdad] = false;
    existReasearchFacility[City::Beijing] = false;
    existReasearchFacility[City::Cairo] = false;
    existReasearchFacility[City::Chennai] = false;
    existReasearchFacility[City::Chicago] = false;
    existReasearchFacility[City::Delhi] = false;
    existReasearchFacility[City::Essen] = false;
    existReasearchFacility[City::HongKong] = false;
    existReasearchFacility[City::Istanbul] = false;
    existReasearchFacility[City::Jakarta] = false;
    existReasearchFacility[City::Kinshasa] = false;
    existReasearchFacility[City::Kolkata] = false;
    existReasearchFacility[City::Lagos] = false;
    existReasearchFacility[City::London] = false;
    existReasearchFacility[City::MexicoCity] = false;
    existReasearchFacility[City::Manila] = false;
    existReasearchFacility[City::Miami] = false;
    existReasearchFacility[City::Montreal] = false;
    existReasearchFacility[City::Moscow] = false;
    existReasearchFacility[City::Mumbai] = false;
    existReasearchFacility[City::NewYork] = false;
    existReasearchFacility[City::Osaka] = false;
    existReasearchFacility[City::Paris] = false;
    existReasearchFacility[City::Riyadh] = false;
    existReasearchFacility[City::SanFrancisco] = false;
    existReasearchFacility[City::Santiago] = false;
    existReasearchFacility[City::Shanghai] = false;
    existReasearchFacility[City::Sydney] = false;
    existReasearchFacility[City::Taipei] = false;
    existReasearchFacility[City::Tehran] = false;
    existReasearchFacility[City::Tokyo] = false;
    existReasearchFacility[City::StPetersburg] = false;
    existReasearchFacility[City::HoChiMinhCity] = false;
    existReasearchFacility[City::Johannesburg] = false;
    existReasearchFacility[City::Karachi] = false;
    existReasearchFacility[City::Khartoum] = false;
    existReasearchFacility[City::SaoPaulo] = false;
    existReasearchFacility[City::Washington] = false;
    existReasearchFacility[City::Madrid] = false;
    existReasearchFacility[City::Seoul] = false;
    existReasearchFacility[City::LosAngeles] = false;
    existReasearchFacility[City::Milan] = false;
    existReasearchFacility[City::Lima] = false;    
}