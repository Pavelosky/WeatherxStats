#include "WeatherMain.h"
#include "WeatherDay.h"
#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <climits> // for INT_MAX and INT_MIN

WeatherMain::WeatherMain() : selectedCountry(""), selectedTimeFrame(0) {}

void WeatherMain::init()
{
    int input;

    while (true) {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void WeatherMain::printMenu()
{
    std::cout << "1: Print help " << std::endl;
    std::cout << "2: Choose a country " << std::endl;
    std::cout << "3: Print all countries " << std::endl;
    std::cout << "4: Choose time frame (day, month, year) " << std::endl;
    std::cout << "5: Show data " << std::endl;
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
    std::cout << "| Type in 1-6 |" << std::endl; // Ensure users can select option 6 to exit
    std::cout << "===============" << std::endl;
    std::getline(std::cin, line);
    try {
        userOption = std::stoi(line);
    } catch (const std::exception& e) {
        // Handle invalid input
    }
    std::cout << "================" << std::endl;
    std::cout << "| You chose: " << userOption << " |" << std::endl;
    std::cout << "================" << std::endl;
    return userOption;
}

void WeatherMain::processUserOption(int option)
{
    switch (option) {
        case 1:
            printHelp();
            break;
        case 2:
            selectedCountry = chooseCountry();
            break;
        case 3:
            // print all countries
            break;
        case 4:
            selectedTimeFrame = chooseTimeFrame();
            break;
        case 5:
            showData(selectedCountry, selectedTimeFrame);
            break;
        case 6:
            exit(0);
            break;
        default:
            std::cout << "==========================================" << std::endl;
            std::cout << "| Invalid option                         |" << std::endl;
            std::cout << "| Please choose a number between 1 and 6 |" << std::endl;
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

    if (timeFrame == "day") {
        return timeFrameMap["day"];
    } else if (timeFrame == "month") {
        return timeFrameMap["month"];
    } else if (timeFrame == "year") {
        return timeFrameMap["year"];
    } else {
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

    // Debug print to check function execution
    std::cout << "Processing data for country: " << country << " and time frame: " << timeFrame << std::endl;

    std::map<std::string, WeatherDay> weatherData = parseCSV(filename, country, timeFrame);

    if (weatherData.empty()) {
        std::cout << "No data available for the selected country and time frame." << std::endl;
    } else {
        displayCandlestickChart(weatherData);
    }
}

void WeatherMain::displayCandlestickChart(const std::map<std::string, WeatherDay>& weatherData)
{
    if (weatherData.empty()) {
        std::cout << "No data available to display." << std::endl;
        return;
    }

    // Determine the range of temperatures
    double minTemp = std::numeric_limits<double>::max();
    double maxTemp = std::numeric_limits<double>::min();

    for (const auto& wd : weatherData) {
        minTemp = std::min(minTemp, wd.second.lowestTemp);
        maxTemp = std::max(maxTemp, wd.second.highestTemp);
    }

    // Set the chart height (number of rows)
    int chartHeight = 20;
    double scale = chartHeight / (maxTemp - minTemp);

    std::vector<std::string> chart(chartHeight, std::string(weatherData.size() * 2, ' '));

    int col = 0;
    for (const auto& wd : weatherData) {
        int openPos = static_cast<int>((wd.second.firstTemp - minTemp) * scale);
        int highPos = static_cast<int>((wd.second.highestTemp - minTemp) * scale);
        int lowPos = static_cast<int>((wd.second.lowestTemp - minTemp) * scale);
        int closePos = static_cast<int>((wd.second.lastTemp - minTemp) * scale);

        for (int i = std::min(openPos, closePos); i <= std::max(openPos, closePos); ++i) {
            chart[chartHeight - i - 1][col * 2 + 1] = '=';
        }

        for (int i = highPos; i > lowPos; --i) {
            if (chart[chartHeight - i - 1][col * 2 + 1] != '=') {
                chart[chartHeight - i - 1][col * 2 + 1] = '|';
            }
        }

        ++col;
    }

    // Print the chart
    std::cout << "Candlestick Chart:" << std::endl;
    for (const auto& row : chart) {
        std::cout << row << std::endl;
    }
}
