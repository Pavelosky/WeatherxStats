#include "CSVReader.h"
#include "Candlestick.h"
#include "WeatherFrame.h"
#include "Chart.h"
#include <iostream>
#include <vector>

int main()
{
    CSVReader reader;
    std::vector<std::vector<std::string>> data = reader.readCSV("temperature_data.csv", "BE_temperature");

    if (!data.empty()) {
        std::vector<WeatherFrame> candlesticks = Candlestick::generateCandlesticks(data, 4);

    // Create a Chart object with the weather frames
    Chart chart(candlesticks);

    // Print the combined candlestick chart
    chart.printChart();

    //     for (const auto& candlestick : candlesticks) {
    //         WeatherFrame cs = candlestick;
    //         std::cout << "Date: " << cs.date << " | "
    //                   << "Open: " << cs.firstTemp << " | "
    //                   << "High: " << cs.highTemp << " | "
    //                   << "Low: " << cs.lowTemp << " | "
    //                   << "Close: " << cs.lastTemp << std::endl;
    //     }
    }
    return 0;
}
