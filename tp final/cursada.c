//
// Created by cguxt on 17/06/2025.
//

#include "cursada.h"

#include <stdlib.h>

void agregar_cursada(Nodo **cursada, int estudiante, int materia) {

    Cursada *c = malloc(sizeof(Cursada));
    c->materia = materia;
    c->estudiante = estudiante;
    insertarAlInicio(cursada,c);
}

int _buscar_cursada(Cursada *c, Cursada *buscada) {
    return c->materia == buscada->materia && c->estudiante == buscada->estudiante;
}


Cursada *buscar_cursada(Nodo **cursada, funcion_equal igual, Cursada *buscada) {
    return (Cursada *) (buscarNodo(cursada, igual, buscada))->dato;
}

void aprobar_materia(Cursada *c, int estudiante, int materia) {

}
