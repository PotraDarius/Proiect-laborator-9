cmake_minimum_required(VERSION 3.22)
project(tema_lab_5_6)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} - Wall -Wextra -Werror - Wpedantic")

add_executable(tema_lab_5_6 main.cpp
        domain.cpp
        teste_vector_dinamic.cpp
        vector_dinamic.h
        repository.cpp
        service.cpp
        validator.cpp
        ui.cpp
        domain.h
        repository.h
        service.h
        ui.h
        validator.h
        teste_domain.cpp
        teste_domain.h
        teste_repository.cpp
        teste_repository.h
        teste_service.cpp
        teste_service.h
        teste_validator.cpp
        teste_validator.h
        undo.h
)
