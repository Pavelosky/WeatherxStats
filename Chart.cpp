#include "Chart.h"

Chart::Chart(const std::vector<WeatherFrame> &weatherFrames)
{
    // Initialize the candlesticks vector with data from weatherFrames
    for (const auto &wf : weatherFrames)
    {
        candlesticks.emplace_back(
            wf.date,
            wf.firstTemp,
            wf.highTemp,
            wf.lowTemp,
            wf.lastTemp);
    }
}

void Chart::printChart() const
{
    // Determine the global range of prices
    double globalMax = -std::numeric_limits<double>::infinity();
    double globalMin = std::numeric_limits<double>::infinity();

    // Find the maximum and minimum values among all candlesticks
    for (const auto &cs : candlesticks)
    {
        globalMax = std::max(globalMax, std::max({cs.open, cs.high, cs.low, cs.close}));
        globalMin = std::min(globalMin, std::min({cs.open, cs.high, cs.low, cs.close}));
    }

    // Normalize temperature levels to integer positions for the chart
    auto normalize = [globalMin, globalMax](double temperature)
    {
        return static_cast<int>(std::round((temperature - globalMin) / (globalMax - globalMin) * 20));
    };

    // Create normalized positions for each candlestick
    std::vector<std::tuple<int, int, int, int>> normalizedPositions;
    for (const auto &cs : candlesticks)
    {
        int openPos = normalize(cs.open);
        int closePos = normalize(cs.close);
        int highPos = normalize(cs.high);
        int lowPos = normalize(cs.low);
        normalizedPositions.emplace_back(openPos, closePos, highPos, lowPos);
    }

    // Print the chart
    for (int i = 20; i >= 0; --i)
    {
        // Print the temperature levels on the left side of the chart
        std::cout << std::setw(2) << (globalMax - globalMin) * i / 20 + globalMin << "\t";

        // Print the candlesticks for each date
        for (size_t j = 0; j < candlesticks.size(); ++j)
        {
            auto [openPos, closePos, highPos, lowPos] = normalizedPositions[j];

            // Print the appropriate symbol for each position in the chart
            if (i == highPos && (highPos == openPos || highPos == closePos))
            {
                std::cout << "-H-";
            }
            else if (i == highPos)
            {
                std::cout << " H ";
            }
            else if (i == lowPos && (lowPos == openPos || lowPos == closePos))
            {
                std::cout << "-L-";
            }
            else if (i == lowPos)
            {
                std::cout << " L ";
            }
            else if (i < highPos && i > lowPos)
            {
                if (i == openPos && openPos == closePos)
                {
                    std::cout << "C-O";
                }
                else if (i == closePos)
                {
                    std::cout << "-C-";
                }
                else if (i == openPos)
                {
                    std::cout << "-O-";
                }
                else if (openPos < closePos)
                {
                    if (i < openPos && i > lowPos)
                    {
                        std::cout << " | ";
                    }
                    else if (i > closePos && i < highPos)
                    {
                        std::cout << " | ";
                    }
                    else
                    {
                        std::cout << "   ";
                    }
                }
                else if (openPos > closePos)
                {
                    if (i < closePos && i > lowPos)
                    {
                        std::cout << " | ";
                    }
                    else if (i > openPos && i < highPos)
                    {
                        std::cout << " | ";
                    }
                    else
                    {
                        std::cout << "   ";
                    }
                }
                else
                {
                    std::cout << " | ";
                }
            }
            else
            {
                std::cout << "   ";
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }

    // Print the dates below the chart
    std::cout << std::setw(6) << " " << "\t";
    for (const auto &cs : candlesticks)
    {
        std::cout << cs.date << "\t";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // Print the dates and values
    for (const auto &cs : candlesticks)
    {
        std::cout << "+++ Date: " << cs.date
                  << " | Open: " << std::fixed << std::setprecision(3) << cs.open
                  << " | High: " << std::fixed << std::setprecision(3) << cs.high
                  << " | Low: " << std::fixed << std::setprecision(3) << cs.low
                  << " | Close: " << std::fixed << std::setprecision(3) << cs.close << " +++";
    }
    std::cout << std::endl;
}
