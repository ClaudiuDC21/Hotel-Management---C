#include "../Domain/Hotel.h"
#include "../Repository/RepoFile.h"
#include <string>

#pragma once

class Service {
private:
    RepoInFile repository;
public:
    Service();

    void set_repository(string);

    Hotel *read();

    void create(Hotel &);

    void update(Hotel &old, Hotel &new_hotel);

    void remove(Hotel &);

    void cautare_hotel_oras(string Oras);

    Hotel *search_hotel_after_city(const string &Oras, int &lungime);

    Hotel *rezervare(string, Date, Date, int &);

    void modify_date(Hotel &hotel, Date data_inceput, Date data_final);

    int lungime_vector();
};
