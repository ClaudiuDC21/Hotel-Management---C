#include "Repository.h"
#include <exception>
#include <iostream>
#include "vector"

using namespace std;

Repository::Repository() {
    this->lungime = 0;
    this->capacitate = 20;
    this->hoteluri = new Hotel[20];
}

Repository::Repository(const Repository &repo) {
    this->capacitate = repo.capacitate;
    this->lungime = repo.lungime;
    this->hoteluri = new Hotel[this->capacitate];
    for (int i = 0; i < this->lungime; i++)
        this->hoteluri[i] = repo.hoteluri[i];
}

void Repository::add_entity(Hotel &hotel) {
    if (this->lungime >= capacitate)
        throw Exceptions("Nu se poate crea deoarece nu este suficient spatiu disponibil!");
    this->hoteluri[lungime++] = hotel;

}

void Repository::update_entity(Hotel &old_hotel, Hotel &new_hotel) {
    int ok = 0;
    for (int i = 0; i < lungime; i++)
        if (hoteluri[i] == old_hotel)
            hoteluri[i] = new_hotel, ok++;
    if (ok == 0)
        throw Exceptions("Nu s-a gasit hotelul respectiv pentru a face update! ");
}

void Repository::delete_entity(Hotel &hotel) {
    int i = 0, j = 0;
    Hotel *new_hotel = new Hotel[capacitate];
    while (i < lungime) {
        if (this->hoteluri[i] != hotel)
            new_hotel[j++] = hoteluri[i];
        i++;
    }
    delete[] this->hoteluri;
    this->lungime = j;
    this->hoteluri = new_hotel;
    if (j == i)
        throw Exceptions("Nu exista acest hotel pentru a putea fi sters! ");

}

Hotel *Repository::get_all() {
    return this->hoteluri;
}

int Repository::get_length() {
    return this->lungime;
}


