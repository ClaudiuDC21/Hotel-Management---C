#include "Hotel.h"
#include <string.h>
#include <limits>
#include <iostream>
#include "Exceptions.h"

using namespace std;

Hotel::Hotel() {
    this->cod_unic = 0;
    this->nume = "a";
    this->oras = "a";
    this->data_inceput.set_date(1, 1, 1);
    this->data_inceput.set_date(1, 1, 1);
}

Hotel::Hotel(int cod, string name, string Oras, Date dataInceput, Date dataSfarsit) {
    this->cod_unic = cod;
    this->nume = name;
    this->oras = Oras;
    this->data_inceput = dataInceput;
    this->data_sfarsit = dataSfarsit;
}


Hotel &Hotel::operator=(const Hotel &S) {
    if (this != &S) {
        this->oras = S.oras;
        this->nume = S.nume;
        this->cod_unic = S.cod_unic;
        this->data_inceput = S.data_inceput;
        this->data_sfarsit = S.data_sfarsit;
    }
}

bool Hotel::operator==(const Hotel &S) const {
    return (this->cod_unic == S.cod_unic);
}

bool Hotel::operator!=(const Hotel &S) {
    return ((this->cod_unic != S.cod_unic) || (this->nume != S.nume)
            || (this->oras != S.oras) || (this->data_inceput != S.data_inceput)
            || (this->data_sfarsit != S.data_sfarsit));
}


int Hotel::get_cod() const {
    return this->cod_unic;
}

string Hotel::get_nume() const {
    return this->nume;
}

string Hotel::get_oras() const{
    return this->oras;
}

Date Hotel::get_data_inceput() const {
    return this->data_inceput;
}

Date Hotel::get_data_sfarsit() const{
    return this->data_sfarsit;
}

void Hotel::set_day_inceput(int zi) {
    this->data_inceput.set_day(zi);
}

void Hotel::set_day_sfarsit(int zi) {
    this->data_sfarsit.set_day(zi);
}

istream &operator>>(istream &is, Hotel &hotel) {
    try {
        cout << "Introduceti nume oras: ";
        is >> hotel.oras;
        cout << "Introduceti numele hotel: ";
        is >> hotel.nume;
        is.get();
        cout << "Introduceti cod unic: ";
        is >> hotel.cod_unic;
        cout << "Introduceti data de inceput : ";
        is >> hotel.data_inceput;
        cout << "Introduceti data de sfarsit : ";
        is >> hotel.data_sfarsit;
        return is;
    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }
}

ostream &operator<<(ostream &os, const Hotel &hotel) {
    os << "Codul unic:" << hotel.cod_unic << endl;
    os << "Oras: " << hotel.oras << endl;
    os << "Nume Hotel: " << hotel.nume << endl;
    os << "Data de Inceput: " << hotel.data_inceput << endl;
    os << "Data de Sfarsit: " << hotel.data_sfarsit << endl;
    return os;
}

