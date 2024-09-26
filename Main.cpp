#include <iostream>
#include "stock_data.h"
#include "linear_regression.h"
#include "date_utils.h"

using namespace std;

// Function to calculate Simple Moving Average (SMA)
vector<double> calculateSMA(const vector<double>& prices, int period) {
    vector<double> sma;
    double sum = 0;
    for (size_t i = 0; i < prices.size(); ++i) {
        sum += prices[i];
        if (i >= period - 1) {
            if (i >= period) {
                sum -= prices[i - period];  
            }
            sma.push_back(sum / period);  
        }
    }
    return sma;
}

int main() {
    // Parse stock data from CSV file
    vector<StockData> data = parseCSV("History_MSFT.csv");  //Use any stock data file

    vector<double> x, y;

    for (const auto& record : data) {
        x.push_back(dateToNumber(record.date));
        y.push_back(record.close);
    }

    
    int smaPeriod = 10;
    vector<double> smaPrices = calculateSMA(y, smaPeriod);

    vector<double> smaDates(x.begin() + (smaPeriod - 1), x.end());


    std::pair<double, double> result = linearRegression(smaDates, smaPrices);
    double m = result.first;
    double c = result.second;

    
    string futureDate = "12/31/2024"; //Use any forthcoming date
    double futureX = dateToNumber(futureDate);
    double predictedPrice = predictPrice(futureX, m, c);

    cout << "Predicted Microsoft stock price on " << futureDate << " using SMA is: $" << predictedPrice << std::endl;

    return 0;
}
