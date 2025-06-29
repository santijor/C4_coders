//
// Created by cguxt on 17/06/2025.
//

#ifndef MATERIA_H
#define MATERIA_H
#include "lista/lista.h"

typedef struct materia {
    int codigo;
    char nombre[50];
}Materia;

void agregar_materia(Nodo **, int , char* );

int buscar_materia_por_nombre(Materia *, char  *);

Materia *buscar_materia(Nodo **, funcion_equal, void * );

int modificar_materia(Nodo* materias, funcion_equal equal, void* dato, char* nuevo_nombre);
int buscar_materia_por_codigo(Materia *m, int *codigo);

#endif //MATERIA_H



