#include "../headers/Utilities.h"

int multiplyNumbers(int a, int b)
{
    return a * b;
}

std::chrono::year_month_day convertDate(std::string dateStr)
{
    unsigned int day, month;
    int year;

    std::sscanf(dateStr.c_str(), "%d-%d-%d", &day, &month, &year);

    std::chrono::day chronoDay{day};
    std::chrono::month chronoMonth{month};
    std::chrono::year chronoYear{year};

    std::chrono::year_month_day chronoDate(chronoYear, chronoMonth, chronoDay);

    return chronoDate;
}

std::string convertDateToString(std::chrono::year_month_day chronoDate)
{
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << static_cast<unsigned>(chronoDate.day()) << '-'
        << std::setw(2) << std::setfill('0') << static_cast<unsigned>(chronoDate.month()) << '-'
        << static_cast<int>(chronoDate.year());

    std::string dateStr = oss.str();
    return dateStr;
}