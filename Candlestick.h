#pragma once

#include <string>
#include <vector>
#include <map>
#include "WeatherFrame.h"

class Candlestick {
public:
    Candlestick();

    // Generate candlesticks from data for a given time frame
    // Parameters:
    //   data: A 2D vector containing the weather data
    //   timeFrame: The time frame for generating the candlesticks
    // Returns:
    //   A vector of WeatherFrame objects representing the generated candlesticks
    static std::vector<WeatherFrame> generateCandlesticks(const std::vector<std::vector<std::string>>& data, int timeFrame);
};
