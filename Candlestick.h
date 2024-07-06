#pragma once

#include <string>
#include <vector>
#include <map>
#include "WeatherFrame.h"

class Candlestick {
public:
    Candlestick();

    // Generate candlesticks from data for a given time frame
    static std::vector<WeatherFrame> generateCandlesticks(const std::vector<std::vector<std::string>>& data, int timeFrame);
};
