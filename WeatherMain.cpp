#include "WeatherMain.h"
#include "Candlestick.h"
#include "WeatherFrame.h"
#include "Chart.h"
#include "CSVReader.h"
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>



WeatherMain::WeatherMain()
{
}

void WeatherMain::init()
{
    // Initialize variables
    int input;
    int selectedTimeFrame = 0;
    std::string selectedCountry = "";

    // Main loop
    while (true)
    {
        // Print menu options
        printMenu();

        // Get user input
        input = getUserOption();

        // Process user option
        processUserOption(input);
    }
}

void WeatherMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 choose a country
    std::cout << "2: Print all countries " << std::endl;
    // 3 print all countries
    std::cout << "3: Choose a country " << std::endl;
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
    try
    {
        userOption = std::stoi(line);
    }
    catch (const std::exception &e)
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
    switch (option)
    {
    case 1:
        printHelp();
        break;
    case 2:
        // print all countries
        printAllCountries(filename);
        break;
    case 3:
        // choose a country
        selectedCountry = chooseCountry();
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

// Function to choose a time frame
int WeatherMain::chooseTimeFrame()
{
    // Map to store time frame options
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

    // Check the chosen time frame and return the corresponding value
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
        // Invalid option, display error message and return 0
        std::cout << "==========================================" << std::endl;
        std::cout << "| Invalid option                         |" << std::endl;
        std::cout << "| Please choose a day, month or year     |" << std::endl;
        std::cout << "==========================================" << std::endl;
        return 0; // or any other appropriate value
    }
}

// Function to print all countries from the CSV file
void WeatherMain::printAllCountries(const std::string& filename) {
    CSVReader reader;
    std::ifstream file(filename);

    // Check if the file can be opened
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    // Read the first line of the file
    if (std::getline(file, line)) {
        // Tokenize the line using comma as the delimiter
        std::vector<std::string> headers = reader.tokenize(line, ',');
        // Iterate through the headers starting from index 1
        for (size_t i = 1; i < headers.size(); ++i) {
            // Print the column number and the header value
            std::cout << "Column " << i << ": " << headers[i] << std::endl;
        }
    } else {
        std::cerr << "Error: File is empty or could not read the first line." << std::endl;
    }

    file.close();
}
    

void WeatherMain::showData(const std::string &country, int timeFrame)
{

    if (country.empty() || timeFrame == 0)
    {
        std::cout << "==========================================" << std::endl;
        std::cout << "| Invalid country or time frame          |" << std::endl;
        std::cout << "==========================================" << std::endl;
        return;
    }

    CSVReader reader;
    std::vector<std::vector<std::string>> data = reader.readCSV(filename, country);

    if (!data.empty())
    {
        std::vector<WeatherFrame> candlesticks = Candlestick::generateCandlesticks(data, timeFrame);

        // Create a Chart object with the weather frames
        Chart chart(candlesticks);

        // Print the combined candlestick chart
        chart.printChart();
    }
}
