#pragma once

#include <vector>

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

};