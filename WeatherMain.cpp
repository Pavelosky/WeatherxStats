#include "WeatherMain.h"
#include <iostream>


WeatherMain::WeatherMain()
{

}

void WeatherMain::init()
{
    int input;

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
    // 5 exit
    std::cout << "5: Exit " << std::endl;

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
            break;
        case 3:
            // print all countries
            break;
        case 4:
            // choose time frame
            break;
        case 5:
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