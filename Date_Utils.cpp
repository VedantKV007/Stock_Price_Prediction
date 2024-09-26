#include "date_utils.h"
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

double dateToNumber(const string& date) {
    tm t = {};
    istringstream ss(date);
    ss >> get_time(&t, "%m/%d/%Y");
    return mktime(&t) / (60 * 60 * 24); // Convert to days
}
