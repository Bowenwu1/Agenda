#include "Date.h"

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