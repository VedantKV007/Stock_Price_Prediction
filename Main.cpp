#include <iostream>
#include "stock_data.h"
#include "linear_regression.h"
#include "date_utils.h"

// Function to calculate Simple Moving Average (SMA)
std::vector<double> calculateSMA(const std::vector<double>& prices, int period) {
    std::vector<double> sma;
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
    std::vector<StockData> data = parseCSV("History_MSFT.csv");

    std::vector<double> x, y;

    for (const auto& record : data) {
        x.push_back(dateToNumber(record.date));
        y.push_back(record.close);
    }

    
    int smaPeriod = 10;
    std::vector<double> smaPrices = calculateSMA(y, smaPeriod);

    std::vector<double> smaDates(x.begin() + (smaPeriod - 1), x.end());


    std::pair<double, double> result = linearRegression(smaDates, smaPrices);
    double m = result.first;
    double c = result.second;

    
    std::string futureDate = "12/31/2024";
    double futureX = dateToNumber(futureDate);
    double predictedPrice = predictPrice(futureX, m, c);

    std::cout << "Predicted stock price on " << futureDate << " using SMA is: $" << predictedPrice << std::endl;

    return 0;
}
