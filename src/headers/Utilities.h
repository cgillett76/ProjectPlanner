#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "picosha2.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>

std::chrono::year_month_day convertDate(std::string dateStr);
std::string convertDateToString(std::chrono::year_month_day chronoDate);
void printChronoDate(std::chrono::year_month_day chronoDate);

#endif