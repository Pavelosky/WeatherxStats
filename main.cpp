#include <iostream>
#include "WeatherDay.h"
#include "WeatherBook.h"

int main()
{
    // Replace "weather_data.csv" with the path to your CSV file
    std::string filename = "temperature_data.csv";
    WeatherBook weatherBook(filename);

    std::vector<WeatherDay> weatherDays = weatherBook.getWeatherDays();
    
    for (const WeatherDay& day : weatherDays)
    {
        std::cout << "Date: " << day.date
                  << ", First Temp: " << day.firstTemperature
                  << ", Last Temp: " << day.lastTemperature
                  << ", High Temp: " << day.highestTemperature
                  << ", Low Temp: " << day.lowestTemperature
                  << std::endl;
    }

    return 0;
}
