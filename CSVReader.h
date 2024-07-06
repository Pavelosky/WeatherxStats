#pragma once

#include <vector>
#include <string>

// CSVReader class for reading and parsing CSV files
class CSVReader
{
    public:
        CSVReader();

        // Reads the CSV file and returns a vector of vectors containing the data
        static std::vector<std::vector<std::string>> readCSV(const std::string& filename, const std::string& columnName);

        // Tokenizes a line of CSV data based on the separator character
        static std::vector<std::string> tokenize(const std::string& line, char separator);
        
    private: 
        // Gets the index of a column in the CSV header line
        static int getColumnIndex(const std::string& headerLine, const std::string& columnName);
};