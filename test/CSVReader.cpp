#include "CSVReader.h"
#include <iostream>
#include <fstream>
#include <sstream>

CSVReader::CSVReader()
{
}

std::vector<std::vector<std::string>> CSVReader::readCSV(const std::string& filename)
{
    std::vector<std::vector<std::string>> data;
    std::ifstream csvFile(filename);
    std::string line;

    if (csvFile.is_open())
    {
        while (std::getline(csvFile, line))
        {
            data.push_back(tokenize(line, ','));
        }
        csvFile.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return data;
}

std::vector<std::string> CSVReader::tokenize(const std::string& line, char separator)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(line);

    while (std::getline(tokenStream, token, separator))
    {
        tokens.push_back(token);
    }

    return tokens;
}
