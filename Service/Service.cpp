#include "Service.h"
#include <string>
#include <iostream>

using namespace std;

Service::Service() {
    ;
}

void Service::set_repository(string filename) {
    this->repository.set_repo(filename);
}

Hotel *Service::read() {
    return repository.get_all();
}

void Service::create(Hotel &hotel) {
    HotelValidator *validator = nullptr;
    validator->validate(hotel);
    repository.add_entity(hotel);
}

void Service::remove(Hotel &hotel) {
    repository.delete_entity(hotel);
}

int Service::lungime_vector() {
    return repository.get_length();
}

void Service::update(Hotel &old_hotel, Hotel &new_hotel) {
    HotelValidator *validator = nullptr;
    validator->validate(new_hotel);
    repository.update_entity(old_hotel, new_hotel);
}

void Service::cautare_hotel_oras(string Oras) {
    try {
        int ok = 0;
        for (int i = 0; i < repository.get_length(); i++)
            if (repository.getAll()[i].get_oras() == Oras)
                cout << repository.getAll()[i] << endl, ok++;

    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }
}

Hotel *Service::search_hotel_after_city(const string &Oras, int &lungime) {
    Hotel *lst = new Hotel[20];
    int j = 0;
    for (int i = 0; i < repository.get_length(); i++)
        if (repository.getAll()[i].get_oras() == Oras)
            lst[j] = repository.getAll()[i], j++;
    lungime = j;
    return lst;
}



void Service::modify_date(Hotel &hotel, Date data_inceput, Date data_final) {
    Hotel rezervare;
    rezervare = hotel;
    if (hotel.get_data_inceput() == data_inceput && data_final <= hotel.get_data_sfarsit())
        rezervare.set_day_inceput(data_final.get_day() + 1), repository.update_entity(hotel, rezervare);
    else if (hotel.get_data_inceput() <= data_inceput && data_final == hotel.get_data_sfarsit())
        rezervare.set_day_inceput(data_inceput.get_day() - 1), repository.update_entity(hotel, rezervare);
    else if (hotel.get_data_inceput() <= data_inceput && data_final <= hotel.get_data_sfarsit())
        rezervare.set_day_sfarsit(data_inceput.get_day()), repository.update_entity(hotel, rezervare);
    else if (data_final.get_day() <= hotel.get_data_inceput().get_day())
        rezervare.set_day_inceput(hotel.get_data_inceput().get_day() + (data_final.get_day() - data_inceput.get_day()) +
                                  1), repository.update_entity(
                hotel, rezervare);
    else if (data_inceput.get_day() >= hotel.get_data_sfarsit().get_day())
        rezervare.set_day_sfarsit(hotel.get_data_sfarsit().get_day() - (data_final.get_day() - data_inceput.get_day()) -
                                  1), repository.update_entity(
                hotel, rezervare);
    else if (data_inceput.get_day() <= hotel.get_data_inceput().get_day() && data_final.get_day() >=
                                                                             hotel.get_data_inceput().get_day())
        rezervare.set_day_inceput(hotel.get_data_inceput().get_day() + (data_final.get_day() - data_inceput.get_day()) +
                                  1), repository.update_entity(
                hotel, rezervare);
    else if (data_inceput.get_day() <= hotel.get_data_sfarsit().get_day() && data_final.get_day() >=
                                                                             hotel.get_data_sfarsit().get_day())
        rezervare.set_day_sfarsit(hotel.get_data_sfarsit().get_day() - (data_final.get_day() - data_inceput.get_day()) -
                                  1), repository.update_entity(
                hotel, rezervare);
}


Hotel *Service::rezervare(string oras, Date data_inceput, Date data_sfarist, int &lungime) {
    Hotel *lst = new Hotel[25];
    Hotel *lst_2 = new Hotel[25];
    Hotel *lst_3 = new Hotel[25];
    int interval_user = data_sfarist.get_day() - data_inceput.get_day();
    int x = 0;
    int y = 0;
    int z = 0;
    for (int i = 0; i < repository.get_length(); i++) {
        int interval_hotel =
                repository.getAll()[i].get_data_sfarsit().get_day() -
                repository.getAll()[i].get_data_inceput().get_day();
        if (repository.getAll()[i].get_oras() == oras && repository.getAll()[i].get_data_sfarsit() >= data_inceput &&
            repository.getAll()[i].get_data_inceput() <= data_sfarist &&
            interval_user <= interval_hotel
                ) {
            lst[x] = repository.getAll()[i];
            x++;
        } else if (repository.getAll()[i].get_oras() == oras &&
                   interval_user <= interval_hotel &&
                   (abs(repository.getAll()[i].get_data_inceput().get_day() - data_inceput.get_day()) <= 3)
                ) {
            lst_2[y] = repository.getAll()[i];
            y++;
        } else if (repository.getAll()[i].get_oras() == oras &&
                   interval_user <= interval_hotel &&
                   (abs(data_sfarist.get_day() - repository.getAll()[i].get_data_sfarsit().get_day()) <= 3)) {
            lst_3[z] = repository.getAll()[i];
            z++;
        }
    }
    if (x != 0) {
        lungime = x;
        return lst;
    } else if (y != 0) {
        lungime = y;
        return lst_2;
    } else if (z != 0) {
        lungime = z;
        return lst_3;
    } else
        lungime = 0;
    return lst;
}
