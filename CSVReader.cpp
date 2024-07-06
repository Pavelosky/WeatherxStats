#include "CSVReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

CSVReader::CSVReader()
{
}

// Read the CSV file and return the data in a vector of vectors of strings
std::vector<std::vector<std::string>> CSVReader::readCSV(const std::string& filename, const std::string& columnName)
{
    std::vector<std::vector<std::string>> data;
    std::ifstream csvFile(filename);
    std::string line;

    int targetColumnIndex = -1;

    if (csvFile.is_open())
    {
        bool isFirstLine = true;
        while (std::getline(csvFile, line))
        {
            // Read the first line to get the column index
            if (isFirstLine)
            {
                targetColumnIndex = getColumnIndex(line, columnName);

                if (targetColumnIndex == -1)
                {
                    std::cerr << "Column name \"" << columnName << "\" not found in CSV header." << std::endl;
                    return {};
                }
                isFirstLine = false;
            }
            // Read the rest of the lines
            else
            {
                std::vector<std::string> tokens = tokenize(line, ',');
                if (tokens.size() > targetColumnIndex)
                {
                    data.push_back({tokens[0], tokens[targetColumnIndex]});
                }
                else
                {
                    std::cerr << "Row size mismatch. Row: " << line << std::endl;
                }
            }
        }
        csvFile.close();
    }
    else
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    return data;
}

// Tokenize a line of text based on a separator character and return the tokens as a vector of strings
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

// Get the index of a column in the CSV header line based on its name
int CSVReader::getColumnIndex(const std::string& headerLine, const std::string& columnName)
{
    std::vector<std::string> headers = tokenize(headerLine, ',');
    for (int i = 0; i < headers.size(); ++i)
    {
        if (headers[i] == columnName)
        {
            return i;
        }
    }
    return -1; // Column not found
}