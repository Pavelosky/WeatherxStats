#ifndef WEATHERDAY_H
#define WEATHERDAY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <map>

class WeatherDay {
public:
    std::string date;
    double firstTemp;
    double lastTemp;
    double highestTemp;
    double lowestTemp;

    WeatherDay()
        : firstTemp(0), lastTemp(0), highestTemp(std::numeric_limits<double>::min()), lowestTemp(std::numeric_limits<double>::max()) {}

    void addTemperature(double temp) {
        if (highestTemp < temp) highestTemp = temp;
        if (lowestTemp > temp) lowestTemp = temp;
    }
};

std::map<std::string, WeatherDay> parseCSV(const std::string& filename, const std::string& temperatureColumn);

#endif // WEATHERDAY_H
