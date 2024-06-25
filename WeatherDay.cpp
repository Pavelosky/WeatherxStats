#include "WeatherDay.h"

std::map<std::string, WeatherDay> parseCSV(const std::string& filename, const std::string& temperatureColumn) {
    std::ifstream file(filename);
    std::string line;
    std::map<std::string, WeatherDay> weatherData;

    int tempColumnIndex = -1;

    if (file.is_open()) {
        std::getline(file, line); // Read header line
        std::stringstream headerStream(line);
        std::string header;
        int columnIndex = 0;

        // Find the index of the temperature column
        while (std::getline(headerStream, header, ',')) {
            if (header == temperatureColumn) {
                tempColumnIndex = columnIndex;
                break;
            }
            columnIndex++;
        }

        if (tempColumnIndex == -1) {
            std::cerr << "Temperature column not found: " << temperatureColumn << std::endl;
            return weatherData;
        }

        // Read and process each line of the file
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::vector<std::string> tokens;
            std::string token;

            while (std::getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() > tempColumnIndex) {
                std::string utc_timestamp = tokens[0];
                double at_temp = std::stod(tokens[tempColumnIndex]);
                std::string date = utc_timestamp.substr(0, 4);

                if (weatherData.find(date) == weatherData.end()) {
                    WeatherDay wd;
                    wd.date = date;
                    wd.firstTemp = at_temp;
                    wd.addTemperature(at_temp);
                    weatherData[date] = wd;
                } else {
                    weatherData[date].addTemperature(at_temp);
                    weatherData[date].lastTemp = at_temp;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    return weatherData;
}