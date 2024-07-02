#pragma once

#include <vector>
#include <string>


class CSVReader
{
    public:
        CSVReader();
        static std::vector<std::vector<std::string>> readCSV(const std::string& filename, const std::string& columnName);
        static std::vector<std::string> tokenize(const std::string& line, char separator);
        
    private: 
        static int getColumnIndex(const std::string& headerLine, const std::string& columnName);
};