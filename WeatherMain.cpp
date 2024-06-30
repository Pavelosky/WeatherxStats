#include "WeatherMain.h"
#include "WeatherDay.h"
#include <iostream>
#include <map>
#include <iomanip>

WeatherMain::WeatherMain()
{

}

void WeatherMain::init()
{

    int input;
    int selectedTimeFrame = 0;
    std::string selectedCountry = "";

    while(true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void WeatherMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 choose a country
    std::cout << "2: Choose a country " << std::endl;
    // 3 print all countries
    std::cout << "3: Print all countries " << std::endl;
    // 4 chose time frame (day, month, year)
    std::cout << "4: Choose time frame (day, month, year) " << std::endl;
    // 5 show data
    std::cout << "5: Show data " << std::endl;
    // 6 exit
    std::cout << "6: Exit " << std::endl;

}

void WeatherMain::printHelp()
{
    std::cout << "========================================================================================================================" << std::endl;
    std::cout << "| This is a weather program. It will allow you to choose a country and then display the weather data for that country. |" << std::endl;
    std::cout << "========================================================================================================================" << std::endl;
}

int WeatherMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "===============" << std::endl;
    std::cout << "| Type in 1-5 |" << std::endl;
    std::cout << "===============" << std::endl;
    std::getline(std::cin, line);
    try{
        userOption = std::stoi(line);
    }catch(const std::exception& e)
    {
        // 
    }
    std::cout << "================" << std::endl;
    std::cout << "| You chose: " << userOption << " |" << std::endl;
    std::cout << "================" << std::endl;
    return userOption;
}

void WeatherMain::processUserOption(int option)
{
    switch(option)
    {
        case 1:
            printHelp();
            break;
        case 2:
            // choose a country
            selectedCountry = chooseCountry();
            break;
        case 3:
            // print all countries
            break;
        case 4:
            // choose time frame
            selectedTimeFrame = chooseTimeFrame();
            break;
        case 5:
            // show data
            showData(selectedCountry, selectedTimeFrame);
            break;        
        case 6:
            exit(0);
            break;
        default:
            std::cout << "==========================================" << std::endl;
            std::cout << "| Invalid option                         |" << std::endl;
            std::cout << "| Please choose a number between 1 and 5 |" << std::endl;
            std::cout << "==========================================" << std::endl;
            break;
    }
}

std::string WeatherMain::chooseCountry()
{
    std::string country;
    std::cout << "======================" << std::endl;
    std::cout << "| Choose a country: |" << std::endl;
    std::cout << "| for eg. NL_temperature, BG_temperature |" << std::endl;
    std::cout << "======================" << std::endl;
    std::getline(std::cin, country);
    std::cout << "======================" << std::endl;
    std::cout << "| You chose: " << country << " |" << std::endl;
    std::cout << "======================" << std::endl;

    return country;

}

int WeatherMain::chooseTimeFrame()
{
    std::map<std::string, int> timeFrameMap;
    timeFrameMap["day"] = 9;
    timeFrameMap["month"] = 7;
    timeFrameMap["year"] = 4;

    std::string timeFrame;
    std::cout << "==========================" << std::endl;
    std::cout << "| Choose a time frame:   |" << std::endl;
    std::cout << "| for eg. day, month, year |" << std::endl;
    std::cout << "==========================" << std::endl;
    std::getline(std::cin, timeFrame);
    std::cout << "==========================" << std::endl;
    std::cout << "| You chose: " << timeFrame << " |" << std::endl;
    std::cout << "==========================" << std::endl;

    if (timeFrame == "day")
    {
        return timeFrameMap["day"];
    }
    else if (timeFrame == "month")
    {
        return timeFrameMap["month"];
    }
    else if (timeFrame == "year")
    {
        return timeFrameMap["year"];
    }
    else
    {
        std::cout << "==========================================" << std::endl;
        std::cout << "| Invalid option                         |" << std::endl;
        std::cout << "| Please choose a day, month or year     |" << std::endl;
        std::cout << "==========================================" << std::endl;
        return 0; // or any other appropriate value
    }
}

void WeatherMain::showData(const std::string& country, int timeFrame)
{       
    std::string filename = "temperature_data.csv";

    if (country.empty() || timeFrame == 0) {
        std::cout << "==========================================" << std::endl;
        std::cout << "| Invalid country or time frame          |" << std::endl;
        std::cout << "==========================================" << std::endl;
        return;
    }

    std::map<std::string, WeatherDay> weatherData = parseCSV(filename, country, timeFrame);

    // for (const auto& wd : weatherData) {
    //     std::cout << "Date: " << wd.second.date << "\n";
    //     std::cout << "First Temperature: " << wd.second.firstTemp << "\n";
    //     std::cout << "Last Temperature: " << wd.second.lastTemp << "\n";
    //     std::cout << "Highest Temperature: " << wd.second.highestTemp << "\n";
    //     std::cout << "Lowest Temperature: " << wd.second.lowestTemp << "\n\n";
    // }
    displayCandlestickChart(weatherData);
} 

void WeatherMain::displayCandlestickChart(const std::map<std::string, WeatherDay>& weatherData)
{
    std::cout << "Candlestick Chart:" << std::endl;
    std::cout << "Date       | O   H   L   C" << std::endl;
    std::cout << "-----------|----------------" << std::endl;

    for (const auto& wd : weatherData) {
        std::cout << wd.first << " | ";
        std::cout << std::setw(3) << wd.second.firstTemp << " ";
        std::cout << std::setw(3) << wd.second.highestTemp << " ";
        std::cout << std::setw(3) << wd.second.lowestTemp << " ";
        std::cout << std::setw(3) << wd.second.lastTemp << std::endl;
    }
}