#pragma once

#include <string>
#include <vector>

class WeatherFrame {
public:
    std::string date; // The date of the weather frame
    double firstTemp; // The temperature at the beginning of the day
    double lastTemp; // The temperature at the end of the day
    double highTemp; // The highest temperature recorded during the day
    double lowTemp; // The lowest temperature recorded during the day
    std::vector<double> temperatures; // A vector to store all the temperature readings

    WeatherFrame(); // Default constructor
    void addTemperature(double temp); // Method to add a temperature reading to the vector
};