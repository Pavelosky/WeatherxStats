#pragma once

#include <vector>
#include <string>

class CSVReader
{
    public:
        CSVReader();
        static std::vector<std::vector<std::string>> readCSV(const std::string& filename);
        static std::vector<std::string> tokenize(const std::string& line, char separator);
        
    private: 
        std::vector<std::string> split(const std::string& line, char delimiter);
};