#include "WeatherDay.h"
#include "WeatherMain.h"

int main() {
    
    WeatherMain app{};
    app.init();
    
    // std::string filename = "weather_data_EU_1980-2019_temp_only.csv";
    // std::string temperatureColumn;

    // std::cout << "Enter the temperature column name (e.g., AT_temperature, BE_temperature): ";
    // std::cin >> temperatureColumn;

    // std::map<std::string, WeatherDay> weatherData = parseCSV(filename, temperatureColumn);

    // for (const auto& wd : weatherData) {
    //     std::cout << "Date: " << wd.second.date << "\n";
    //     std::cout << "First Temperature: " << wd.second.firstTemp << "\n";
    //     std::cout << "Last Temperature: " << wd.second.lastTemp << "\n";
    //     std::cout << "Highest Temperature: " << wd.second.highestTemp << "\n";
    //     std::cout << "Lowest Temperature: " << wd.second.lowestTemp << "\n\n";
    // }

    // return 0;
}