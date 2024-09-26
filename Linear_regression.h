#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>
#include <utility>

// Function to perform linear regression
std::pair<double, double> linearRegression(const std::vector<double>& x, const std::vector<double>& y);

// Function to predict a future stock price
double predictPrice(double x, double m, double c);

#endif 

