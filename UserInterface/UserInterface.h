#include "../Repository/Repository.h"
#include "../Service/Service.h"
#include "../Repository/RepoFile.h"

#pragma once

class UserInterface {
private:
    Service service;
    RepoInFile repository;

    void handle_adaugare();

    void handle_show_all();

    void handle_stergere();

    void handle_update();

    void handle_cautare_hotel_oras();

    void handle_rezervari();

public:
    UserInterface();

    UserInterface(RepoInFile &, Service &);

    void show_menu();
};

