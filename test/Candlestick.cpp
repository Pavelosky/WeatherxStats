#include "Candlestick.h"
#include <sstream>
#include <iostream>

std::vector<WeatherFrame> Candlestick::generateCandlesticks(const std::vector<std::vector<std::string>>& data, int timeFrame) {
    std::vector<WeatherFrame> weatherFrames;
    if (data.empty()) {
        std::cerr << "No data provided." << std::endl;
        return weatherFrames;
    }

    std::map<std::string, WeatherFrame> weatherData;

    // Process the data
    for (size_t i = 1; i < data.size(); ++i) {
        std::string utc_timestamp = data[i][0];
        double at_temp = std::stod(data[i][1]);
        std::string date = utc_timestamp.substr(0, timeFrame);

        if (weatherData.find(date) == weatherData.end()) {
            WeatherFrame wf;
            wf.date = date;
            wf.firstTemp = at_temp;
            wf.addTemperature(at_temp);
            weatherData[date] = wf;
        } else {
            weatherData[date].addTemperature(at_temp);
            weatherData[date].lastTemp = at_temp;
        }
    }

    // Convert map values to vector
    for (const auto& pair : weatherData) {
        weatherFrames.push_back(pair.second);
    }

    return weatherFrames;
}
