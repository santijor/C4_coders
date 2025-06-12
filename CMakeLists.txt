cmake_minimum_required(VERSION 3.30)
project(lista C)

set(CMAKE_C_STANDARD 11)

add_executable(lista lista_enlazada_c4coders.c
        test/test.c)
