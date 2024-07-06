#pragma once

#include "CSVReader.h"
#include "Candlestick.h"
#include "Chart.h"
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
        void printAllCountries(const std::string& filename);
        void processUserOption(int option);
        std::string chooseCountry();
        int chooseTimeFrame();
        void showData(const std::string& country, int timeFrame);
        std::string filename = "weather_data_EU_1980-2019_temp_only.csv";
        
    private: 
        std::string selectedCountry; // Member variable to store the selected country
        int selectedTimeFrame; // Member variable to store the selected time frame
};