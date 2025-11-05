#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
private:
    int month;
    int day;
    int year;

    bool isValid(int m, int d, int y) const;
    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;
    // Convert to/from a day count (Julian-like) for easy arithmetic
    long toSerial() const;
    void fromSerial(long serial);

public:
    // ctors
    Date();                     // default (1/1/2000)
    Date(int m, int d, int y);  // param

    // mutators & accessors
    void setDate(int m, int d, int y);
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Operator overloads requested
    // prefix
    Date& operator++();    // ++d
    Date& operator--();    // --d
    // postfix
    Date operator++(int);  // d++
    Date operator--(int);  // d--

    // difference in days (absolute difference)
    long operator-(const Date& other) const;

    // Stream operators
    friend std::ostream& operator<<(std::ostream& out, const Date& d);
    friend std::istream& operator>>(std::istream& in, Date& d);
};

#endif // DATE_H
