#pragma once
#include "WeatherDay.h"
#include <string>
#include <vector>

class WeatherBook
{
public:
    WeatherBook(std::string filename);
    std::vector<WeatherDay> getWeatherDays();
    void printWeatherDays();

private:
    std::vector<std::vector<std::string>> readCSV(std::string filename);
    std::vector<WeatherDay> weatherDays;
    void parseWeatherData(std::vector<std::vector<std::string>> csvData);
};
