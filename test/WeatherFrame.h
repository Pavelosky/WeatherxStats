#pragma once

#include <string>
#include <vector>

class WeatherFrame {
public:
    std::string date;
    double firstTemp;
    double lastTemp;
    double highTemp;
    double lowTemp;
    std::vector<double> temperatures;

    WeatherFrame();
    void addTemperature(double temp);
};