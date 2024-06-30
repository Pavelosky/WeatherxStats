#pragma once

#include "WeatherDay.h"
#include <vector>
#include <string>
#include <map>

class WeatherMain
{
    public:
        WeatherMain();
        /** Call this to start the sim */
        void init();
        void printMenu();
        void printHelp();
        int getUserOption();
        void processUserOption(int option);
        std::string chooseCountry();
        int chooseTimeFrame();
        void showData(const std::string& country, int timeFrame);
        
    private: 
        std::string selectedCountry; // Member variable to store the selected country
        int selectedTimeFrame; // Member variable to store the selected time frame
        void displayCandlestickChart(const std::map<std::string, WeatherDay>& weatherData);
};