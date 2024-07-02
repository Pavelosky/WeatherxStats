#include "CSVReader.h"
#include "Candlestick.h"
#include "WeatherFrame.h"
#include <iostream>
#include <vector>

int main()
{
    CSVReader reader;
    std::vector<std::vector<std::string>> data = reader.readCSV("temperature_data.csv", "BE_temperature");

    if (!data.empty()) {
        std::vector<WeatherFrame> candlesticks = Candlestick::generateCandlesticks(data, 7);

        for (const auto& candlestick : candlesticks) {
            WeatherFrame cs = candlestick;
            std::cout << "Date: " << cs.date << " | "
                      << "Open: " << cs.firstTemp << " | "
                      << "High: " << cs.highTemp << " | "
                      << "Low: " << cs.lowTemp << " | "
                      << "Close: " << cs.lastTemp << std::endl;
        }
    }
    return 0;
}