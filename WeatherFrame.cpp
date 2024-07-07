#include "WeatherFrame.h"
#include <limits>


WeatherFrame::WeatherFrame()
    : firstTemp(0.0), lastTemp(0.0), highTemp(std::numeric_limits<double>::lowest()), lowTemp(std::numeric_limits<double>::max()) {}

// Start of the personally written code without assistance
void WeatherFrame::addTemperature(double temp)
{
    temperatures.push_back(temp); // Add the temperature to the vector

    if (temp > highTemp)
    {                    // Check if the temperature is higher than the current highest temperature
        highTemp = temp; // If so, update the highest temperature
    }

    if (temp < lowTemp)
    {                   // Check if the temperature is lower than the current lowest temperature
        lowTemp = temp; // If so, update the lowest temperature
    }
}
// End of the personally written code without assistance