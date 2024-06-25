#include "WeatherBook.h"
#include <fstream>
#include <sstream>
#include <iostream>

// WeatherBook constructor
WeatherBook::WeatherBook(std::string filename)
{
    std::vector<std::vector<std::string>> csvData = readCSV(filename);
    parseWeatherData(csvData);
}

// Read CSV file
std::vector<std::vector<std::string>> WeatherBook::readCSV(std::string filename)
{
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);
    std::string line;
    
    while (std::getline(file, line))
    {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;
        
        while (std::getline(ss, cell, ','))
        {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    
    return data;
}

// Parse weather data from CSV
void WeatherBook::parseWeatherData(std::vector<std::vector<std::string>> csvData)
{
    std::string currentDate = "";
    double firstTemp = 0, lastTemp = 0, highTemp = -9999, lowTemp = 9999;

    for (size_t i = 1; i < csvData.size(); ++i) // start from 1 to skip header
    {
        std::string date = csvData[i][0];
        double temp = std::stod(csvData[i][1]);
        
        if (currentDate == "")
        {
            currentDate = date;
            firstTemp = temp;
        }
        
        if (date != currentDate)
        {
            weatherDays.push_back(WeatherDay(currentDate, firstTemp, lastTemp, highTemp, lowTemp));
            currentDate = date;
            firstTemp = temp;
            highTemp = -9999;
            lowTemp = 9999;
        }
        
        lastTemp = temp;
        if (temp > highTemp) highTemp = temp;
        if (temp < lowTemp) lowTemp = temp;
    }

    // Add the last day's data
    weatherDays.push_back(WeatherDay(currentDate, firstTemp, lastTemp, highTemp, lowTemp));
}

// Get weather days
std::vector<WeatherDay> WeatherBook::getWeatherDays()
{
    return weatherDays;
}

// Print weather days
void WeatherBook::printWeatherDays()
{
    for (WeatherDay& day : weatherDays)
    {
        std::cout << "Date: " << day.date
                  << ", First Temp: " << day.firstTemperature
                  << ", Last Temp: " << day.lastTemperature
                  << ", High Temp: " << day.highestTemperature
                  << ", Low Temp: " << day.lowestTemperature
                  << std::endl;
    }
}
