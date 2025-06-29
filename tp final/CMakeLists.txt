cmake_minimum_required(VERSION 3.30)
project(Estudiantes C)

set(CMAKE_C_STANDARD 11)

add_executable(estudiantes
        estudiante.c
        estudiante.h
        lista/lista.c
        lista/lista.h
        materia.c
        materia.h
        cursada.c
        cursada.h
        listados.c
        listado.h
        util/abb.c
        util/abb.h
        main.c
        util/exportar.c
        util/exportar.h)
