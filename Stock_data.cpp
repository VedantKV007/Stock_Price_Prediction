#include "stock_data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Convert a string with a dollar sign to a double
double parseDollarValue(const string& value) {
    // Removing the dollar sign 
    string numericValue = value;
    if (!value.empty() && value[0] == '$') {
        numericValue = value.substr(1);
    }
    // Convert to double
    return stod(numericValue);
}

// Read file
vector<StockData> parseCSV(const string& filename) {
    vector<StockData> data;
    ifstream file(filename);

    // Check if file opened successfully
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return data;
    }

    string line;
    getline(file, line); // Skip the header line

    // Read file line by line
    while (getline(file, line)) {
        stringstream ss(line);
        string date, close, volume, open, high, low;

        
        getline(ss, date, ',');
        getline(ss, close, ',');
        getline(ss, volume, ',');
        getline(ss, open, ',');
        getline(ss, high, ',');
        getline(ss, low, ',');

        // Create a StockData object fo our vector
        try {
            StockData stock;
            stock.date = date;
            stock.close = parseDollarValue(close);
            stock.volume = stod(volume);
            stock.open = parseDollarValue(open);
            stock.high = parseDollarValue(high);
            stock.low = parseDollarValue(low);

            data.push_back(stock);
        }
        catch (const exception& e) {
            cout << "Error parsing line: " << line <<"\n";
            cout << "Error details: " << e.what() <<"\n";
        }
    }

    return data;
}