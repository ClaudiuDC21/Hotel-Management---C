#include "UserInterface.h"
#include <iostream>
#include "../Domain/Exceptions.h"

using namespace std;

void menu() {
    cout << "------MENU------" << endl;
    cout << "1. Adaugare hotel " << endl;
    cout << "2. Update hotel" << endl;
    cout << "3. Stergere hotel" << endl;
    cout << "4. Afisare hoteluri " << endl;
    cout << "5. Cautare hotel dupa oras" << endl;
    cout << "6. Rezervare dupa disponibilitate" << endl;
    cout << "x. Exit" << endl;
}

void UserInterface::show_menu() {
    menu();
    int optiune;
    cout << "Introduceti optiunea: " << endl;
    cin >> optiune;
    while (optiune) {
        switch (optiune) {
            case 1:
                handle_adaugare();
                break;
            case 2:
                handle_update();
                break;
            case 3:
                handle_stergere();
                break;
            case 4:
                handle_show_all();
                break;
            case 5:
                handle_cautare_hotel_oras();
                break;
            case 6:
                handle_rezervari();
                break;
            default:
                cout << "Comanda incorecta, reincercati !" << endl;
        }
        menu();
        cout << "Introduceti optiunea: " << endl;
        cin >> optiune;
    }
}


UserInterface::UserInterface() {
    RepoInFile repository_1;
    this->repository = repository_1;

    Service service_1;
    service_1.set_repository("first");
    this->service = service_1;
}

UserInterface::UserInterface(RepoInFile &repo, Service &service1) {
    this->repository = repo;
    this->service = service1;
    this->service.set_repository("file.txt");
}


void UserInterface::handle_adaugare() {
    try {
        Hotel hotel_a;
        cin >> hotel_a;
        service.create(hotel_a);
    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }
}

void UserInterface::handle_show_all() {
    try {
        for (int i = 0; i < service.lungime_vector(); i++)
            cout << service.read()[i] << " " << endl;
        cout << endl;
    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }
}

void UserInterface::handle_stergere() {
    try {
        Hotel hotel_a;
        cin >> hotel_a;
        service.remove(hotel_a);
    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }
}

void UserInterface::handle_update() {
    try {
        Hotel hotel_old, hotel_new;
        cout << "Hotelul pe care vreti sa il actualizati: ";
        cin >> hotel_old;
        cout << "Noile date ale hotelului: ";
        cin >> hotel_new;
        service.update(hotel_old, hotel_new);
    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }
}

void UserInterface::handle_cautare_hotel_oras() {
    try {
        cout << endl;
        string oras;
        cout << "Introduceti numele orasului : ";
        cin >> oras;
        service.cautare_hotel_oras(oras);
    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }
}


void UserInterface::handle_rezervari() {
    try {
        string oras;
        Date data_inceputt, data_finall;
        cout << "Introduceti numele orasului in care doriti sa rezervati un hotel:";
        cin >> oras;
        cout << "Introduceti data de inceput: ";
        cin >> data_inceputt;
        cout << "Introduceti data de sfarsit: ";
        cin >> data_finall;
        int lungime = 0;
        Hotel *lst = service.rezervare(oras, data_inceputt, data_finall, lungime);
        if (lungime == 0)
            throw Exceptions("Nu exista rezervari in aceasta perioada!");
        else {
            int option = -1;
            int ok = 0;
            while (option != lungime && ok == 0) {
                for (int i = 0; i < lungime; i++)
                    cout << lst[i].get_nume() << endl << " Data inceput: " << lst[i].get_data_inceput()
                         << " Data final : "
                         << lst[i].get_data_sfarsit() << endl;
                cin >> option;
                if (option > lungime)
                    cout << "Hotel invalid!";
                else
                    for (int i = 0; i < lungime; i++)
                        if (option == i) {
                            service.modify_date(lst[i], data_inceputt, data_finall);
                            ok = 1;
                        }
            }


        }
    }
    catch (exception &e) {
        cout << e.what() << '\n';
    }

}

