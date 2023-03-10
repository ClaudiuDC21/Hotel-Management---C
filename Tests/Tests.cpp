#include "Tests.h"
#include <cassert>
#include <cstring>
#include "../Domain/Hotel.h"
#include "../Service/Service.h"


void repo_tests() {
    Date data_inceput;
    Date data_sfarsit;
    data_inceput.set_date(1, 1, 2020);
    data_sfarsit.set_date(31, 12, 2023);
    Hotel hotel_1(1, "Hotel Continental", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_2(1, "Hotel Traian", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_3(1, "Hotel Belvedere", "Cluj", data_inceput, data_sfarsit);


    RepoInFile repository;
    repository.add_entity(hotel_1);
    repository.add_entity(hotel_2);

    assert(repository.get_all()[0] == hotel_1);
    assert(repository.get_all()[1] == hotel_2);

    repository.update_entity(hotel_1, hotel_3);

    assert(repository.get_all()[0] == hotel_3);

    repository.add_entity(hotel_1);

    assert(repository.get_all()[2] == hotel_1);
    assert(repository.get_length() == 3);

    repository.delete_entity(hotel_1);

    assert(repository.get_length() == 2);
    assert(repository.get_all()[0] == hotel_3);
    assert(repository.get_all()[1] == hotel_2);

    repository.add_entity(hotel_3);
    assert(repository.get_length() == 3);
    assert(repository.get_all()[0] == hotel_3);
    assert(repository.get_all()[1] == hotel_2);
    assert(repository.get_all()[2] == hotel_3);
}

void service_tests() {
    Date data_inceput;
    Date data_sfarsit;
    data_inceput.set_date(1, 1, 2020);
    data_sfarsit.set_date(1, 2, 2023);;
    Hotel hotel_1(1, "Hotel Continental", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_2(2, "Hotel Traian", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_3(3, "Hotel Belvedere", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_4(4, "Hotel Termal", "Oradea", data_inceput, data_sfarsit);
    Hotel hotel_5(5, "Hotel Nufarul", "Oradea", data_inceput, data_sfarsit);

    RepoInFile repo;
    Service service;
    service.set_repository("teste_service");
    repo.clear_file();
    service.create(hotel_1);
    service.create(hotel_2);
    service.create(hotel_3);
    service.create(hotel_4);
    service.create(hotel_5);
    assert(service.read()[0] == hotel_1);
    assert(service.read()[1] == hotel_2);
    assert(service.read()[2] == hotel_3);
    assert(service.read()[3] == hotel_4);

    assert(service.lungime_vector() == 5);
    service.remove(hotel_5);
    assert(service.lungime_vector() == 4);


    service.create(hotel_5);
    service.update(hotel_5, hotel_1);

    assert(service.read()[4] == hotel_1);

}

void teste_functionalitati() {
    RepoInFile repo;
    Service service;
    Date data_inceput;
    Date data_sfarsit;
    service.set_repository("teste_functionalitati");
    repo.clear_file();
    data_inceput.set_date(5, 4, 2022);
    data_sfarsit.set_date(31, 12, 2022);
    Hotel hotel_1(1, "Hotel Continental", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_2(2, "Hotel Traian", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_3(3, "Hotel Belvedere", "Cluj", data_inceput, data_sfarsit);
    Hotel hotel_4(4, "Hotel Termal", "Oradea", data_inceput, data_sfarsit);
    Hotel hotel_5(5, "Hotel Nufarul", "Oradea", data_inceput, data_sfarsit);
    service.create(hotel_1);
    service.create(hotel_2);
    service.create(hotel_3);
    service.create(hotel_4);

    int length;
    Hotel *lst = service.search_hotel_after_city("Cluj", length);
    assert(lst[0] != hotel_5);
    assert(length == 3);
    assert(lst[0] == hotel_1);
    int lungime = 0;

    Hotel *hotel_list = service.rezervare("Cluj", data_inceput, data_sfarsit, lungime);
    assert(lungime == 3);
    data_inceput.set_date(5, 4, 2022);
    data_sfarsit.set_date(13, 4, 2022);
    service.modify_date(hotel_list[0], data_inceput, data_sfarsit);
    assert(hotel_list[0].get_data_inceput().get_day() == 5);
    assert(hotel_list[0].get_data_inceput().get_month() == 4);
    assert(hotel_list[0].get_data_inceput().get_year() == 2022);
    assert(data_sfarsit.get_day() == 13);
    assert(data_sfarsit.get_month() == 4);
    assert(data_sfarsit.get_year() == 2022);
    data_inceput.set_date(13, 4, 2022);
    data_sfarsit.set_date(15, 4, 2022);
    service.modify_date(hotel_list[1], data_inceput, data_sfarsit);
}

void test_all() {
    repo_tests();
    service_tests();
    teste_functionalitati();
}