#include <iostream>
#include "stock_data.h"
#include "linear_regression.h"
#include "date_utils.h"

using namespace std;

vector<double> calculateSMA(const vector<double>& prices, int period) {
    vector<double> sma(prices.size() - period + 1);
    double sum = 0;

    for (int i = 0; i < period; ++i) {
        sum += prices[i];
    }

    sma[0] = sum / period;

    for (int i = period; i < prices.size(); ++i) {
        sum += prices[i] - prices[i - period];
        sma[i - period + 1] = sum / period;
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


    pair<double, double> result = linearRegression(smaDates, smaPrices);
    double m = result.first;
    double c = result.second;

    
    string futureDate = "12/31/2024"; //Use any forthcoming date
    double futureX = dateToNumber(futureDate);
    double predictedPrice = predictPrice(futureX, m, c);

    cout << "Predicted Microsoft stock price on " << futureDate << " using SMA is: $" << predictedPrice << std::endl;

    return 0;
}
