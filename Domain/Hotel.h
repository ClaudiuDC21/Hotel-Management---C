#include "Date.h"
#include <iostream>
#pragma once
using namespace std;

class Hotel {
private:
    int cod_unic;
    string nume;
    string oras;
    Date data_inceput;
    Date data_sfarsit;
public:
    Hotel();

    Hotel(int cod, string name, string Oras, Date data_start, Date data_end);

    Hotel &operator=(const Hotel &);

    bool operator==(const Hotel &) const;

    bool operator!=(const Hotel &);

    int get_cod() const;

    void set_day_inceput(int);

    void set_day_sfarsit(int);

    string get_nume() const;

    string get_oras() const;

    Date get_data_inceput() const;

    Date get_data_sfarsit() const;

    friend istream &operator>>(istream &is, Hotel &);

    friend ostream &operator<<(ostream &os, const Hotel &);
};

