//
// Created by cguxt on 17/06/2025.
//

#ifndef CURSADA_H
#define CURSADA_H

#include "materia.h"

typedef struct cursada {
    int estudiante;
    int materia;
    int aprobado;
}Cursada;

void agregar_cursada(Nodo **, int , int );

Cursada *buscar_cursada(Nodo **, funcion_equal , Cursada *);

int _buscar_cursada(Cursada *, Cursada *);

void aprobar_materia(Nodo **, int , int);

int materia_aprobada(Nodo **, int , int );

#endif //CURSADA_H
