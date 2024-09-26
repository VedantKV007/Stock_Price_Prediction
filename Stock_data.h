#ifndef STOCK_DATA_H
#define STOCK_DATA_H

#include <string>
#include <vector>
using namespace std;

struct StockData {
    string date;
    double close;
    double volume;
    double open;
    double high;
    double low;
};

vector<StockData> parseCSV(const string& filename);

double parseDollarValue(const string& value);

#endif 
