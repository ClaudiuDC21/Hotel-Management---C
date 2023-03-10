#include "Date.h"

Date::Date() {}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

void Date::set_date(int ziua, int luna, int anul) {
    this->year = anul;
    this->month = luna;
    this->day = ziua;
}

Date &Date::operator=(const Date &date) {
    if (this != &date) {
        this->year = date.year;
        this->month = date.month;
        this->day = date.day;
    }
}

bool Date::operator==(const Date &date) {
    return ((this->day == date.day) && (this->month == date.month) && (this->year == date.year));
}

bool Date::operator!=(const Date &date) {
    return ((this->day != date.day) || (this->month != date.month) || (this->year != date.year));
}

bool Date::operator>=(const Date &date) {
    return ((this->day >= date.day) && (this->month >= date.month) && (this->year >= date.year));
}

bool Date::operator<=(const Date &date) {
    return ((this->day <= date.day) && (this->month <= date.month) && (this->year <= date.year));
}

istream &operator>>(istream &is, Date &date) {
    cout<<endl;
    cout << "Introduceti anul: ";
    is >> date.year;
    cout << "Introduceti luna: ";
    is >> date.month;
    cout << "Introduceti ziua: ";
    is >> date.day;
    return is;
}

ostream &operator<<(ostream &os, const Date &date) {
    os << date.day << "." << date.month << "." << date.year << endl;
    return os;
}

int Date::get_year() const {
    return year;
}

void Date::set_year(int an) {
    this->year = an;
}

int Date::get_month() const {
    return month;
}

void Date::set_month(int luna) {
    this->month = luna;
}

int Date::get_day() const {
    return day;
}

void Date::set_day(int zi) {
    this->day = zi;
}

bool Date::operator>(const Date &date) {
    return ((this->day > date.day) && (this->month > date.month) && (this->year > date.year));
}



