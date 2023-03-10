#include "../Domain/Hotel.h"
#include "../Domain/Exceptions.h"
#include "../Domain/DateValidator.h"
#include "../Domain/HotelValidator.h"

#pragma once

class Repository {
private:
    int lungime;
    int capacitate;
    Hotel *hoteluri;
public:
    Repository();

    Repository(const Repository &);

    void add_entity(Hotel &);

    virtual void update_entity(Hotel &old, Hotel &);

    virtual void delete_entity(Hotel &);

    Hotel *get_all();

    int get_length();
};
