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

#endif //MATERIA_H



