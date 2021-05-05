#ifndef HEADER_BOARD
#define HEADER_BOARD

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <ostream>

#include "City.hpp"
#include "Color.hpp"


namespace pandemic{

    class Board{    
        std::unordered_map<std::string, unsigned int> cityStatus;
            
        std::unordered_map<std::string, Color> cityColor;
            
        std::unordered_map<std::string, std::vector<std::string>> connection;
            
        std::unordered_map<City, bool> existReasearchFacility;

        std::unordered_map<Color, bool> existCure;

        std::unordered_map<City, std::string> cityToString;
            
        void replaceEnumByString();

        public:
        
            Board();

            unsigned int& operator[](City name);

            friend std::ostream& operator<<(std::ostream& os, const Board& board);

            bool is_clean();

            std::unordered_map<City, std::string>& getMap();

            std::vector<std::string> getNeighbors(std::string cityName);

            bool haveFacility(City cityName);

            void buildResearchFacility(City cityName);

            bool haveCure(Color colorType); 

            Color getCityColor(City cityName);
    };
}

#endif