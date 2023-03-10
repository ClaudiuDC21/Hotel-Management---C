#include "HotelValidator.h"
#include <iostream>


using namespace std;


void HotelValidator::validate(const Hotel &hotel) {
    DateValidator::validate(hotel.get_data_inceput());
    DateValidator::validate(hotel.get_data_sfarsit());

    if (hotel.get_nume() == "") {
        throw Exceptions("Hotelul nu are un nume! ");
    }

    if (hotel.get_oras() == "") {
        throw Exceptions("Hotelul nu are un oras caruia sa ii apartina! ");
    }

    if (hotel.get_cod() <= 0) {
        throw Exceptions("ID-ul hotelului trebuie sa fie pozitiv! ");
    }

    for (int i = 0; i < hotel.get_nume().size(); i++) {
        if (isdigit(hotel.get_nume()[i])) {
            throw Exceptions("Hotelul are in nume caractere incorecte! ");
        }
    }

    for (int i = 0; i < hotel.get_oras().size(); i++) {
        if (!isalpha(hotel.get_oras()[i])) {
            throw Exceptions("Orasul are in nume caractere incorecte! ");
        }
    }

    if (isalpha(hotel.get_cod())) {
        throw Exceptions("ID-ul trebuie sa fie de tip int, adica sa contina doar cifre! ");
    }

}

HotelValidator::~HotelValidator() {
    ;
}

HotelValidator::HotelValidator() = default;


