#include "DateValidator.h"

DateValidator::DateValidator() {
    ;
}

DateValidator::~DateValidator() {
    ;
}

void DateValidator::validate(const Date &date) {
    if (date.get_year() <= 0 or date.get_year() > 9999) {
        throw Exceptions("Anul trebuie sa fie un numar pozitiv! ");
    }

    if (date.get_month() <= 0 or date.get_month() > 12) {
        throw Exceptions("Lunile unui an trebuie sa fie cuprinse intre 1 si 12! ");
    }
    vector<int> luni_cu_31_zile = {1, 3, 5, 7, 8, 10, 12};
    for (int i: luni_cu_31_zile) {
        if (date.get_month() == i) {
            if (date.get_day() <= 0 or date.get_day() > 31) {
                throw Exceptions("Ziua lunii acesteia trebuie sa fie cuprinsa intre 0 si 31! ");
            }
        }
    }

    vector<int> luni_cu_30_zile = {4, 6, 9, 11};
    for (int i: luni_cu_30_zile) {
        if (date.get_month() == i) {
            if (date.get_day() <= 0 or date.get_day() > 30) {
                throw Exceptions("Ziua lunii acesteia trebuie sa fie cuprinsa intre 0 si 30! ");
            }
        }
    }
    if (date.get_year() % 4 == 0)
        if (date.get_month() == 2) {
            if (date.get_day() <= 0 or date.get_day() > 28) {
                throw Exceptions("Ziua lunii acesteia trebuie sa fie cuprinsa intre 0 si 28! ");
            }
            else throw Exceptions("Ziua lunii acesteia trebuie sa fie cuprinsa intre 0 si 29! ");
        }

}
