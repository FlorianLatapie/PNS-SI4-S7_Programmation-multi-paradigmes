//
// Created by Florian on 23/09/2022.
//

#ifndef INC_2_DATE_DATE_H
#define INC_2_DATE_DATE_H


#include <ostream>

class Date {
    int year;
    int month;
    int day;
public:

    Date();
    explicit Date (int nbSeconds);
    Date (int year, int month, int day);

    static std::string monthName(int m);
    static int daysInThisMonth(int month, int year);
    static bool isLeapYear(int i);

    int dateToDays() const;
    Date daysToDate(int days) const;


    friend std::ostream &operator<<(std::ostream &os, const Date &date);
    friend std::istream &operator>>(std::istream &is, Date &date);

    Date operator+(int days);
    Date operator-(int days);
    Date operator+=(int days);
    Date operator-=(int days);

    Date operator+(const Date &date);
    Date operator-(const Date &date);

    Date operator++(int i);
    Date operator--(int i);

    Date & operator++();
    Date & operator--();

    bool operator==(const Date &rhs) const;
    bool operator!=(const Date &rhs) const;

    bool operator==(int days) const;
    bool operator!=(int days) const;

    friend bool operator==(int days, const Date &rhs);
    friend bool operator!=(int days, const Date &rhs);

    bool operator<(const Date &rhs) const;
    bool operator>(const Date &rhs) const;
    bool operator<=(const Date &rhs) const;
    bool operator>=(const Date &rhs) const;
};


#endif //INC_2_DATE_DATE_H
