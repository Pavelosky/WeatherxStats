#include "WeatherFrame.h"
#include <limits>

WeatherFrame::WeatherFrame()
    : firstTemp(0.0), lastTemp(0.0), highTemp(std::numeric_limits<double>::lowest()), lowTemp(std::numeric_limits<double>::max()) {}

void WeatherFrame::addTemperature(double temp) {
    temperatures.push_back(temp);
    if (temp > highTemp) {
        highTemp = temp;
    }
    if (temp < lowTemp) {
        lowTemp = temp;
    }
}
