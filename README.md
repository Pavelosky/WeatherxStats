# WeatherxStats

This repository contains the code for WeatherxStats, a weather statistics application.
It's a project for the OOP module in the Computer Science course in the University of London

## About
This project basic functionalities include reading and parsing data from a CSV file, filtering them according to conditions set by the user, generating candlestick representations of the weather data, and finally displaying them in the form of candlesticks in a text-based chart. Key classes used in the process were adapted and extended with appropriate functionality to meet the requirements of this specific project: CSVReader, WeatherFrame, and Candlestick, among others. It all starts with the user interaction within the file WeatherMain.cpp by selecting a country and timeframe. In the CSVReader class, some new functionalities were added, like data filtration by country and timeframe. Candlestick processes the weather data and creates candlestick objects, which are visualized with the Chart class.

The textual plot is well articulated and informative in explaining weather data to enable a user to figure out temperature trends within a chosen time scale.

It does involve a fair bit of complex tasks, although the program design ensures that all the components used in it are modular and coherent with each other to come out with a strong and maintainable code base. Using prior knowledge and incorporating new techniques, I was able to create a weather visualization tool for general usage—not only to meet the project requirements but also to offer an interface that is easily used by all. 


## Installation

1. Clone the repository: `git clone https://github.com/your-username/WeatherxStats.git`
2. Use the following command to build: g++ .\Candlestick.cpp .\Chart.cpp .\CSVReader.cpp .\main.cpp .\WeatherFrame.cpp .\WeatherMain.cpp -o WeatherX 


## Contributing

Contributions are welcome! If you have any ideas or improvements, please submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.
