#include <iostream>
using namespace std;
#include <iomanip>
#include "date.h"

const int M = 12;	//number of months
const int dl[M] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //number of consequtive months
const char* months[M] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

int char_to_int(char c) {
    return c - '0';
}

bool Date::ifLeap() const {
	return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

Date::Date(int d, int m, int y) : day(9), month(3), year(2021), format(true)
{
    if (y < 2001 || y > 2100) {
        cout << "invalid input";
        return;
    }
    else {
        year = y;
    }

    if (m < 1 || m > 12) {
        cout << "Invalid month";
        year = 2021;
        return;
    }
    else {
        month = m;
    }

    if (d < 1 || d > dl[m - 1]) {
        cout << "Invalid input";
        year = 2021;
        month = 3;
        return;
    }
    else {
        day = d;
    }
}

Date::Date(const char* str) : day(9), month(3), year(2021), format(true)
{
    int y = char_to_int(str[6]) * 1000 + char_to_int(str[7]) * 100 + char_to_int(str[8]) * 10 + char_to_int(str[9]);
    if (y < 2001 || y > 2100) {
        cout << "invalid input";
        return;
    }
    else {
        year = y;
    }

    int m = char_to_int(str[3]) * 10 + char_to_int(str[4]);
    if (m < 1 || m > 12) {
        cout << "Invalid month";
        year = 2021;
        return;
    }
    else {
        month = m;
    }

    int d = char_to_int(str[0]) * 10 + char_to_int(str[1]);
    if (d < 1 || d > dl[m - 1]) {
        cout << "Invalid input";
        year = 2021;
        month = 3;
        return;
    }
    else {
        day = d;
    }
    
}

bool& Date::SetFormat()
{
    return format;
}

void Date::NextDay()
{
    int daysInMonth = dl[month - 1];
    if (month == 2 && this->ifLeap()) {
        daysInMonth = 29;
    }
    if (day == daysInMonth) {
        day = 1;
        if (month == 12) {
            month = 1;
            year++;
        }
        else {
            month++;
        }
    }
    else {
        day++;
    }
}

void Date::PrevDay()
{
	if (day == 1) {
        if (month == 1) {
            --year;
            month = 12;
            day = 31;
        }
        --month;
        if (month == 2 && this->ifLeap()) {
            day = 29;
        }
        else {
            day = dl[month - 1];
        }
    }
    else {
        day--;
    }
}

void Date::SelectedDay(int n)
{
    if (n > 0) {
        for (int i = 0; i < n; ++i) {
            NextDay();
        }
    }
    else if (n < 0) {
        for (int i = 0; i < -n; ++i) {
            PrevDay();
        }
    }
}

bool Date::ifEqual(const Date& date) const
{
    return this->day == date.day && this->month == date.month && this->year == date.year;
}

ostream& operator<<(ostream& out, const Date& date)
{
    if (date.format) {
        out << date.day << "." << date.month << "." << date.year << endl;
    }
    else {
        out << months[date.month - 1] << " " << date.day << ", " << date.year;
    }

    return out;
}

istream& operator>>(istream& in, Date& date)
{
    cout << "Day:";
    in >> date.day;

    cout << "Month:";
    in >> date.month;

    cout << "Year:";
    in >> date.year;

    return in;
}

bool ifLess(const Date& a, const Date& b)
{
    if (a.year == b.year)
    {
        if (a.month == b.month)
        {
            return a.day < b.day;
        }
        return a.month < b.month;
    }
    return a.year < b.year;
}

int CountDays(const Date& a, const Date& b)
{
    if (a.ifEqual(b)) {
        return 0;
    }
    int days = 0;
    if (ifLess(a, b)) {
        Date i = a;
        while (ifLess(i, b)) {
            i.NextDay();
            days++;
        }
        return days;
    }
    else {
        Date i = b;
        while (ifLess(i, a)) {
            i.NextDay();
            days++;
        }
        return days;
    }
}



