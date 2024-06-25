#include "CSVReader.h"
#include <iostream>

int main() {
    std::string filename = "temperature_data.csv"; // Replace with your actual CSV file path
    CSVReader csvReader;
    std::vector<std::vector<std::string>> data = csvReader.readCSV(filename);

    // Display the read CSV data
    for (const auto& row : data) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}