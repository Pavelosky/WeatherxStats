#pragma once

#include <vector>
#include <string>

class WeatherMain
{
    public:
        WeatherMain();
        /** Call this to start the sim */
        void init();
    private: 
        void printMenu();
        void printHelp();
        int getUserOption();
        void processUserOption(int option);
        std::string chooseCountry();
        int chooseTimeFrame();
        void showData();

};