#include "RepoFile.h"


RepoInFile::RepoInFile() {
}

void RepoInFile::add_entity(Hotel &hotel) {
    Repository::add_entity(hotel);
    save_to_file();
}

void RepoInFile::delete_entity(Hotel &hotel) {
    Repository::delete_entity(hotel);
    save_to_file();
}

void RepoInFile::update_entity(Hotel &old_hotel, Hotel &new_hotel) {
    Repository::update_entity(old_hotel, new_hotel);
    save_to_file();
}

Hotel *RepoInFile::getAll() {
    return Repository::get_all();
}

void RepoInFile::clear_file() {
    ofstream f(this->file_name);
    f << "";
}

void RepoInFile::save_to_file() {

    if (!this->file_name.empty()) {
        ofstream f(this->file_name);
        for (int i = 0; i < this->get_length(); i++) {
            f << this->getAll()[i];
        }
        f.close();
    }
}

void RepoInFile::set_repo(string &filename) {
    this->file_name = filename;
}

void RepoInFile::load_file() {
    if (!this->file_name.empty()) {
        ifstream f(this->file_name);
        string Str_cod_unic;
        int cod_unic;
        string Str_nume_hotel;
        string nume_hotel;
        string Str_nume_oras;
        string nume_oras;
        string Str_inceput;
        Date inceput;
        string Str_final;
        Date final;
        while (!f.eof()) {

            f >> Str_cod_unic;
            f.get();
            f >> cod_unic;
            f >> Str_nume_oras >> nume_oras;
            f >> Str_nume_hotel >> nume_hotel;
            f >> Str_inceput;
            f >> inceput;
            f >> Str_final;
            f >> final;
            bool ok = false;
            for (int i = 0; i < this->get_length(); i++)
                if (this->getAll()[i].get_cod() == cod_unic) { ok = true; }
            if (!ok) {
                Hotel hote(cod_unic, nume_hotel, nume_oras, inceput, final);
                this->add_entity(hote);
            }

        }
        f.close();
    }
}
