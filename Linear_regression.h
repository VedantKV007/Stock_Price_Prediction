#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>
#include <utility>
using namespace std;


pair<double, double> linearRegression(const vector<double>& x, const vector<double>& y);

double predictPrice(double x, double m, double c);

#endif 

