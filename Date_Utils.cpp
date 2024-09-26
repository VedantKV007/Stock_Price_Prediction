#include "date_utils.h"
#include <ctime>
#include <iomanip>
#include <sstream>


double dateToNumber(const std::string& date) {
    std::tm t = {};
    std::istringstream ss(date);
    ss >> std::get_time(&t, "%m/%d/%Y");
    return std::mktime(&t) / (60 * 60 * 24); // Convert to days
}
