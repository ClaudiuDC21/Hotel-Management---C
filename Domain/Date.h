#include <iostream>
#pragma once
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date();

    Date(int day, int month, int year);

    void set_date(int ziua, int luna, int anul);

    Date &operator=(const Date &);

    bool operator==(const Date &);

    bool operator!=(const Date &);

    int get_day() const;

    void set_day(int);

    int get_year() const;

    void set_year(int);

    int get_month() const;

    void set_month(int);

    bool operator>=(const Date &);

    bool operator>(const Date &);

    bool operator<=(const Date &);

    friend istream &operator>>(istream &is, Date &);

    friend ostream &operator<<(ostream &os, const Date &);
};


