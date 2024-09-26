#include "linear_regression.h"
#include <numeric>
#include <cmath>
#include <stdexcept>

using namespace std;

// Calculates the linear regression model parameters 
std::pair<double, double> linearRegression(const std::vector<double>& x, const std::vector<double>& y) {
    
    if (x.size() != y.size()) {
        throw runtime_error("Input vectors must have the same size.");
    }

    if (x.empty()) {
        throw runtime_error("Input vectors cannot be empty.");
    }

    // Calculate necessary sums
    double n = x.size();
    double sum_x = accumulate(x.begin(), x.end(), 0.0);
    double sum_y = accumulate(y.begin(), y.end(), 0.0);
    double sum_xx = inner_product(x.begin(), x.end(), x.begin(), 0.0);
    double sum_xy = inner_product(x.begin(), x.end(), y.begin(), 0.0);

    // Calculate slope m and intercept c
    double m = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    double c = (sum_y - m * sum_x) / n;

    return { m, c };
}

// Predicts the y value for a given x value using the calculated regression model
double predictPrice(double x, double m, double c) {
    return m * x + c;
}