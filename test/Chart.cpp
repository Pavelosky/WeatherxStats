#include "Chart.h"

Chart::Chart(const std::vector<WeatherFrame>& weatherFrames) {
    for (const auto& wf : weatherFrames) {
        candlesticks.emplace_back(
            wf.date,
            wf.firstTemp,
            wf.highTemp,
            wf.lowTemp,
            wf.lastTemp
        );
    }
}

void Chart::printChart() const {
    // Determine the global range of prices
    double globalMax = -std::numeric_limits<double>::infinity();
    double globalMin = std::numeric_limits<double>::infinity();

    for (const auto& cs : candlesticks) {
        globalMax = std::max(globalMax, std::max({cs.open, cs.high, cs.low, cs.close}));
        globalMin = std::min(globalMin, std::min({cs.open, cs.high, cs.low, cs.close}));
    }

    // Normalize price levels to integer positions for the chart
    auto normalize = [globalMin, globalMax](double price) {
        return static_cast<int>(std::round((price - globalMin) / (globalMax - globalMin) * 20));
    };

    // Create normalized positions for each candlestick
    std::vector<std::tuple<int, int, int, int>> normalizedPositions;
    for (const auto& cs : candlesticks) {
        int openPos = normalize(cs.open);
        int closePos = normalize(cs.close);
        int highPos = normalize(cs.high);
        int lowPos = normalize(cs.low);
        normalizedPositions.emplace_back(openPos, closePos, highPos, lowPos);
    }

    // Print the chart
    for (int i = 20; i >= 0; --i) {
        std::cout << std::setw(4) << (globalMax - globalMin) * i / 20 + globalMin << "\t";
        for (size_t j = 0; j < candlesticks.size(); ++j) {
            auto [openPos, closePos, highPos, lowPos] = normalizedPositions[j];
            if (i == highPos) {
                std::cout << "| H |";
            } else if (i == lowPos) {
                std::cout << "| L |";
            } else if (i <= highPos && i >= lowPos) {
                if (i == openPos) {
                    std::cout << "|-O-|";
                } else if (i == closePos) {
                    std::cout << "|-C-|";
                } else {
                    std::cout << "|   |";
                }
            } else {
                std::cout << "     ";
            }
            std::cout << "\t";
        }
        std::cout << std::endl;
    }

    // Print the dates and values
    for (const auto& cs : candlesticks) {
        std::cout << "Date: " << cs.date << " | Open: " << std::fixed << std::setprecision(3) << cs.open
                  << " | High: " << std::fixed << std::setprecision(3) << cs.high
                  << " | Low: " << std::fixed << std::setprecision(3) << cs.low
                  << " | Close: " << std::fixed << std::setprecision(3) << cs.close << "\t";
    }
    std::cout << std::endl;
}
