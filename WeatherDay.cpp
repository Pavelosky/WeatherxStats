#include "WeatherDay.h"

// WeatherDay constructor
WeatherDay::WeatherDay(std::string date, double firstTemp, double lastTemp, double highTemp, double lowTemp)
    : date(date), firstTemperature(firstTemp), lastTemperature(lastTemp), highestTemperature(highTemp), lowestTemperature(lowTemp) {}
