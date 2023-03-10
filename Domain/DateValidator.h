#include <string>
#include <iostream>
#include "Hotel.h"
#include <cstring>
#include "Date.h"
#include "vector"
#pragma once
#include "Exceptions.h"

class DateValidator {
public:
    DateValidator();
    ~DateValidator();

    void validate(const Date& date);


};

