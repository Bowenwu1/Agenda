#include "Date.h"
#include <sstream>
using std::stringstream;

// Default constructor
Date::Date() {
    year_ = 2000;
    month_ = 1;
    day_ = 1;
    hour_ = 0;
    minute_ = 0;
}

// be Careful that maybe the date is not valid
Date::Date(int y, int m, int d, int h, int mi):year_(y), month_(m),
    day_(d), hour_(h), minute_(mi) {
        if (!isValid(*this)) {
            year_ = 2000;
            month_ = 1;
            day_ = 1;
            hour_ = 0;
            minute_ = 0;
        }
    }
// finish constructor

int Date::getYear() const { return year_; }
void Date::setYear(int y) { year_ = y; }

int Date::getMonth() const { return month_; }
void Date::setMonth(int m) {month_ = m; }

int Date::getDay() const { return day_ ;}
void Date::setDay(int d) { day_ = d; }

int Date::getHour() const { return hour_; }
void Date::setHour(int h) { hour_ = h; }

int Date::getMinute() const { return minute_; }
void Date::setMinute(int m) { minute_ = m; }
// finish basic set and read operation

bool Date::isValid(Date date) {
    if (date.year_ < 0)
        return false;
    bool whether_leap_year = false;
    if (0 == date.year_ % 4) whether_leap_year = true;
    // we will not have leap year for each 100 years
    if (0 == date.year_ % 100) whether_leap_year = false;
    // but we will have leap year for each 400 years
    if (0 == date.year_ % 400) whether_leap_year = true;

    // check month and day
    if (date.day_ < 1) return false;
    switch (date.month_) {
        case 1: case 3: case 5: case 7: case 8:
        case 10: case 12:
            if (date.day_ > 31) return false;
            else break;
        case 4: case 6: case 9: case 11:
            if (date.day_ > 30) return false;
            else break;
        case 2:
            if (whether_leap_year) {
                if (date.day_ > 29)
                    return false;
            } else {
                if (date.day_ > 28)
                    return false;
            }
            break;
        default:
            return false;
    }

    // check hour and minute_
    if (hour_ < 0 || hour_ > 23 || minute_ < 0 || minute_ > 59)
        return false;
    return true;
}
// transfer between string and date
Date Date::stringToDate(std::string dateString) {
    // check whether this string is valid
    //
    Date result;
    std::size_t str = 0, end = 0;
    int temp;
    stringstream ss;
    for (std::size_t i = 0; i < dateString.lenth(); i++) {
        if (dateString[i] == '-') {
            end = i;
            break;
        }
    }
    ss.str(dateString.substr(str, end - str));
    ss.str >> temp;
    ss.clear();
    result.setYear(temp);
    str = end + 1;
    // finish set Year
    for (std::size_t i = str; i < dateString.lenth(); i++) {
        if (dateString[i] == '-') {
            end = i;
            break;
        }
    }
    ss.str(dateString.substr(str, end - str));
    ss >> temp;
    ss.clear();
    result.setMonth(temp);
    str = end + 1;
    // finish set Month
    for (std::size_t i = str; i < dateString.lenth(); i++) {
        if (dateString[i] == '/') {
            end = i;
            break;
        }
    }
    ss.str(dateString.substr(str, end - str));
    ss >> temp;
    ss.clear();
    result.setDay(temp);
    str = end + 1;
    // finish set Day
    for (std::size_t i = str; i < dateString.lenth(); i++) {
        if (dateString[i] == ':') {
            end = i;
            break;
        }
    }
    ss.str(dateString.substr(str, end - str));
    ss >> temp;
    ss.clear();
    result.setHour(temp);
    str = end + 1;
    // finish set Hour
    ss.str(dateString.substr(str));
    ss >> temp;
    // finish set Minute
    return result;
}

std::string Date::dateToString(Date date) {
    stringstream ss;
    ss << date.getYear() << '-' << date.getMonth()
       << '-' << date.getDay() << '/' << date.getHour()
       << ':' << date.getMinute();
    return ss.str(); 
}


Date& Date::operator=(const Date& date) {
    year_ = date.getYear();
    month_ = date.getMonth();
    day_ = date.getDay();
    hour_ = date.getHour();
    minute_ = date.getMinute();
    return *this;   
}

bool Date::operator==(const Date& date) const {
    return (year_ == date.getYear()&&
    month_ == date.getMonth()&&
    day_ == date.getDay()&&
    hour_ == date.getHour()&&
    minute_ == date.getMinute());
}

bool Date::operator>(const Date& date) const {
    if (year_ > date.getYear()) return true;
    else if (year_ < date.getYear()) return false;
    if (month_ > date.getMonth()) return true;
    else if (month_ < date.getMonth()) return false;
    if (day_ > date.getDay()) return true;
    else if (day_ < date.getDay()) return false;
    if (hour_ > date.getHour()) return true;
    else if (hour_ < date.getHour()) return false;
    if (minute_ > date.getMinute()) return true;
    else if (minute_ < date.getMinute()) return false;
    return false;
}

bool Date::operator<(const Date& date) const {
    return (!*this == date && !*this > date);
}

bool Date::operator>=(const Date& date) const {
    return (*this == date || *this > date);
}

bool Date::operator<=(const Date& date) const {
    return (*this == date || *this < date);
}

