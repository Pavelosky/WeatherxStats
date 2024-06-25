#pragma once
#include <string>

class WeatherDay
{
public:
    std::string date;
    double firstTemperature;
    double lastTemperature;
    double highestTemperature;
    double lowestTemperature;

    WeatherDay(std::string date, double firstTemp, double lastTemp, double highTemp, double lowTemp);
};
