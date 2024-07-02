#pragma once

#include <string>
#include <vector>
#include <map>
#include "WeatherFrame.h"

class Candlestick {
public:
    static std::vector<WeatherFrame> generateCandlesticks(const std::vector<std::vector<std::string>>& data, int timeFrame);
};


