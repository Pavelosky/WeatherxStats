#pragma once

#include <vector>
#include "OrderBookEntry.h"

class WeatherMain
{
    public:
        MerkelMain();
        /** Call this to start the sim */
        void init();
    private: 
        void printMenu();
        void printHelp();

        std::string currentTime;

};