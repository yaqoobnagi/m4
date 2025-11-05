#include "Date.h"
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <limits>

using std::ostream;
using std::istream;

// ----------------- helpers -----------------

bool Date::isLeapYear(int y) const {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    return (y % 4 == 0);
}

int Date::daysInMonth(int m, int y) const {
    static int mdays[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && isLeapYear(y)) return 29;
    return mdays[m];
}

bool Date::isValid(int m, int d, int y) const {
    if (y < 1) return false;
    if (m < 1 || m > 12) return false;
    int dim = daysInMonth(m, y);
    if (d < 1 || d > dim) return false;
    return true;
}

// We convert a date to a serial day count using a proleptic Gregorian algorithm.
// Based on algorithm mapping (days since a fixed epoch), valid for wide ranges.
long Date::toSerial() const {
    // convert Y,M,D to days since 0001-03-01 (so March is month 1 in this shifted year)
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    long serial = day + (153 * m + 2) / 5 + 365L * y + y / 4 - y / 100 + y / 400 - 32045;
    // serial is the Julian Day Number; use it directly
    return serial;
}

void Date::fromSerial(long serial) {
    // inverse of above (JDN -> Gregorian date)
    long a = serial + 32044;
    long b = (4 * a + 3) / 146097;
    long c = a - (146097 * b) / 4;
    long d = (4 * c + 3) / 1461;
    long e = c - (1461 * d) / 4;
    long m = (5 * e + 2) / 153;
    day = (int)(e - (153 * m + 2) / 5 + 1);
    month = (int)(m + 3 - 12 * (m / 10));
    year = (int)(100 * b + d - 4800 + (m / 10));
}

// ----------------- constructors & set -----------------

Date::Date() : month(1), day(1), year(2000) {}

Date::Date(int m, int d, int y) {
    setDate(m, d, y);
}

void Date::setDate(int m, int d, int y) {
    if (!isValid(m, d, y)) {
        throw std::invalid_argument("Invalid date");
    }
    month = m; day = d; year = y;
}

// ----------------- increment / decrement -----------------

Date& Date::operator++() { // prefix ++ : add one day
    long s = toSerial();
    fromSerial(s + 1);
    return *this;
}

Date Date::operator++(int) { // postfix ++ : return old value, then increment
    Date old = *this;
    ++(*this);
    return old;
}

Date& Date::operator--() { // prefix --
    long s = toSerial();
    fromSerial(s - 1);
    return *this;
}

Date Date::operator--(int) { // postfix --
    Date old = *this;
    --(*this);
    return old;
}

// ----------------- subtraction -----------------

long Date::operator-(const Date& other) const {
    long s1 = toSerial();
    long s2 = other.toSerial();
    return s1 - s2; // can be negative; tests expect positive differences - handle in test
}

// ----------------- stream operators -----------------

static const char* monthNames[] = {
    "", "January","February","March","April","May","June",
    "July","August","September","October","November","December"
};

ostream& operator<<(ostream& out, const Date& d) {
    // Format: April 18, 2018
    out << monthNames[d.month] << " " << d.day << ", " << d.year;
    return out;
}

istream& operator>>(istream& in, Date& d) {
    // Prompt-based input per spec. Accepts format mm dd yyyy or mm/dd/yyyy.
    // We'll prompt for numeric month, day, year separately for simplicity.
    std::cout << "Enter month (1-12): ";
    int m; in >> m;
    std::cout << "Enter day: ";
    int day; in >> day;
    std::cout << "Enter year: ";
    int yr; in >> yr;

    if (!d.isValid(m, day, yr)) {
        // Clear bad input if stream state is bad
        std::cin.clear();
        // ignore leftover input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid date entered.");
    }
    d.setDate(m, day, yr);
    return in;
}
