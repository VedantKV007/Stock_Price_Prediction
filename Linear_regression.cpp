#include "linear_regression.h"
#include <numeric>
#include <cmath>

// Linear regression to compute slope (m) and intercept (c)
std::pair<double, double> linearRegression(const std::vector<double>& x, const std::vector<double>& y) {
    double n = x.size();
    double sum_x = std::accumulate(x.begin(), x.end(), 0.0);
    double sum_y = std::accumulate(y.begin(), y.end(), 0.0);
    double sum_xx = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
    double sum_xy = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);

    double m = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    double c = (sum_y - m * sum_x) / n;

    return { m, c };
}

// Function to predict future stock price based on x (date) using m (slope) and c (intercept)
double predictPrice(double x, double m, double c) {
    return m * x + c;
}
