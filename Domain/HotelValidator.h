#include <string>
#include <iostream>
#include "Hotel.h"
#include <cstring>
#pragma once
#include "Date.h"
#include "DateValidator.h"
#include "Exceptions.h"

using namespace std;

class HotelValidator: public DateValidator {
public:
    HotelValidator();
    ~HotelValidator();

    void validate(const Hotel&);
};
