#pragma once

#include <vector>
#include <string>

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

};