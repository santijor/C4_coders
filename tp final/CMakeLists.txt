cmake_minimum_required(VERSION 3.30)
project(Estudiantes C)

set(CMAKE_C_STANDARD 11)

add_executable(estudiantes
        estudiante.c
        estudiante.h
        test/test_estudiante.c
        lista/lista.c
        lista/lista.h
        materia.c
        materia.h
        cursada.c
        cursada.h)
