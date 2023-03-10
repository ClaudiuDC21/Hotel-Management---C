#include <exception>
#include <iostream>

#pragma once
using namespace std;

class Exceptions : public exception {
private:
    const char *mesaj;
public:

    Exceptions(const char *message) : mesaj(message) {}

    const char *what() const noexcept override {
        return mesaj;
    }
};
