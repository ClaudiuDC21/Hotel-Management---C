cmake_minimum_required(VERSION 3.21)
project(Hotel_Management___C)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hotel_Management___C
        main.cpp Domain/Hotel.cpp Domain/Hotel.h Domain/Date.cpp Domain/Date.h Domain/DateValidator.cpp Domain/DateValidator.h Domain/Exceptions.h Domain/HotelValidator.cpp Domain/HotelValidator.h Repository/RepoFile.cpp Repository/RepoFile.h Repository/Repository.cpp Repository/Repository.h Service/Service.cpp Service/Service.h Tests/Tests.cpp Tests/Tests.h UserInterface/UserInterface.cpp UserInterface/UserInterface.h)
