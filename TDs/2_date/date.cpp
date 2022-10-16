//
// Created by Florian on 23/09/2022.
//

#include "date.h"
#include <iostream>

Date::Date() {
    year = 2016;
    month = 11;
    day = 21;
}

Date::Date(int nbSeconds) {
    time_t t = nbSeconds;
    struct tm *tm = localtime(&t);
    year = tm->tm_year + 1900;
    month = tm->tm_mon + 1;
    day = tm->tm_mday;
}

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

std::string Date::monthName(int m) {
    switch (m) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid month";
    }
}

// format : November 21, 2016
std::ostream &operator<<(std::ostream &os, const Date &date) {
    if (date.month == 1 && date.year == 1) {
        os << date.day;
    } else {
        os << date.monthName(date.month) << " " << date.day << ", " << date.year;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Date &date) {
    char c;
    is >>date.year >> c >> date.month >> c >> date.day;
    return is;
}

Date Date::operator+(int days) {
    return daysToDate(dateToDays() + days);
}

Date Date::operator-(int days) {
    return daysToDate(dateToDays() - days);
}

Date Date::operator+=(int days) {
    day += days;
    return *this;
}

Date Date::operator-=(int days) {
    day -= days;
    return *this;
}

Date Date::operator+(const Date &date) {
    return daysToDate(dateToDays() + date.dateToDays());
}

Date Date::operator-(const Date &date) {
    return daysToDate(dateToDays() - date.dateToDays());
}


Date Date::operator++(int) {
    Date temp = *this;
    day++;
    return temp;
}

Date Date::operator--(int) {
    Date temp = *this;
    day--;
    return temp;
}

Date &Date::operator++() {
    day++;
    return *this;
}

Date &Date::operator--() {
    day--;
    return *this;
}

bool Date::operator==(const Date &rhs) const {
    return year == rhs.year &&
           month == rhs.month &&
           day == rhs.day;
}

bool Date::operator!=(const Date &rhs) const {
    return !(rhs == *this);
}

bool operator==(int days, const Date &date) {
    return days == date.dateToDays();
}


bool Date::operator<(const Date &rhs) const {
    return dateToDays() < rhs.dateToDays();
}

bool Date::operator>(const Date &rhs) const {
    return dateToDays() > rhs.dateToDays();
}

bool Date::operator<=(const Date &rhs) const {
    return dateToDays() <= rhs.dateToDays();
}

bool Date::operator>=(const Date &rhs) const {
    return dateToDays() >= rhs.dateToDays();
}

bool Date::operator==(int days) const {
    return dateToDays() == days;
}

Date Date::daysToDate(int days) const {
    int year = 1;
    while (days > 365) {
        days -= isLeapYear(year) ? 366 : 365;
        year++;
    }
    int month = 1;
    while (days > daysInThisMonth(month, year)) {
        days -= daysInThisMonth(month, year);
        month++;
    }
    int day = days;

    return Date(year, month, day);
}

bool Date::isLeapYear(int i) {
    return (i % 4 == 0 && i % 100 != 0) || i % 400 == 0;
}

int Date::daysInThisMonth(int month, int year) {
    if (month == 2)
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ? 29 : 28;
    else return month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31;
}

int Date::dateToDays() const {
    int days = 0;
    for (int i = 1; i < year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }
    for (int i = 1; i < month; i++) {
        days += daysInThisMonth(i, year);
    }
    days += day;
    return days;
}

bool Date::operator!=(int days) const {
    return dateToDays() != days;
}

bool operator!=(int days, const Date &rhs) {
    return days != rhs.dateToDays();
}

