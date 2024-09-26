#include "stock_data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

double parseDollarValue(const std::string& value) {
    std::string cleanValue = value;

    size_t pos = value.find_first_not_of("$ \t\n\r");
    if (pos != std::string::npos) {
        cleanValue.erase(0, pos);
    }

    size_t pos2 = cleanValue.find_last_not_of("$ \t\n\r");
    if (pos2 != std::string::npos) {
        cleanValue.erase(pos2 + 1);
    }

    if (cleanValue.empty()) {
        throw std::invalid_argument("Invalid value: Empty string");
    }

    return std::stod(cleanValue);
}

std::vector<StockData> parseCSV(const std::string& filename) {
    std::vector<StockData> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return data;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, close, volume, open, high, low;

        if (std::getline(ss, date, ',') &&
            std::getline(ss, close, ',') &&
            std::getline(ss, volume, ',') &&
            std::getline(ss, open, ',') &&
            std::getline(ss, high, ',') &&
            std::getline(ss, low, ',')) {

            data.push_back({
                date,
                parseDollarValue(close),
                std::stod(volume),
                parseDollarValue(open),
                parseDollarValue(high),
                parseDollarValue(low)
                });
        }
        else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    return data;
}