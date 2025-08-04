#ifndef _UTILITIES_H_
#define _UTILITIES_H

#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "picosha2.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

int multiplyNumbers(int a, int b);
std::chrono::year_month_day convertDate(std::string dateStr);
std::string convertDateToString(std::chrono::year_month_day chronoDate);

#endif