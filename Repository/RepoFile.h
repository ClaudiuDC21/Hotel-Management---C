#include "Repository.h"
#include <bits/stdc++.h>
#include <fstream>
#include "Repository.h"
#include <cstring>
#include "../Domain/DateValidator.h"
#include "../Domain/HotelValidator.h"
#pragma once

using namespace std;


class RepoInFile: public Repository{
private:
    string file_name;
public:
    explicit RepoInFile();
    void set_repo(string& filename);
    void add_entity(Hotel &hot);
    void delete_entity(Hotel&);
    void update_entity(Hotel &old_hotel, Hotel &new_hotel);
    Hotel * getAll();
    void load_file();
    void save_to_file();
    void clear_file();
};
