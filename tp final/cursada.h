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

void agregar_cursada(Nodo **cursada, int estudiante, int materia);

Cursada *buscar_cursada(Nodo **cursada, funcion_equal igual, Cursada *buscada);

int _buscar_cursada(Cursada *c, Cursada *buscada);

#endif //CURSADA_H
