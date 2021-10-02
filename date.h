#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>

struct Date
{
    Date() = default;
    Date(unsigned short day, unsigned short month, unsigned short year)
        : day(day), month(month), year(year)
    {}

    unsigned short day, month, year;

    bool operator>(const Date& other)
    {
        if (year < other.year) return false;
        else if (month < other.month) return false;
        else if (day < other.day) return false;
        return true;
    }

    bool operator<(const Date& other)
    {
        if (year > other.year) return false;
        else if (month > other.month) return false;
        else if (day > other.day) return false;
        return true;
    }

    bool operator==(const Date& other)
    {
        return day == other.day && month == other.month && year == other.year;
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << day << "." << month << "." << year;
        return ss.str();
    }
};

#endif // DATE_H
