#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <limits>
#include "WeatherFrame.h"  // Include the WeatherFrame definition

class Chart {
public:
    struct Candlestick {
        std::string date;   // Date of the candlestick
        double open;        // Opening price
        double high;        // Highest price
        double low;         // Lowest price
        double close;       // Closing price

        Candlestick(const std::string& date, double open, double high, double low, double close)
            : date(date), open(open), high(high), low(low), close(close) {}
    };

    Chart(const std::vector<WeatherFrame>& weatherFrames);

    void printChart() const;

private:
    std::vector<Candlestick> candlesticks;   // Vector to store the candlesticks
};
