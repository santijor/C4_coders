//
// Created by cguxt on 17/06/2025.
//

#include "cursada.h"

#include <stdio.h>
#include <stdlib.h>

void agregar_cursada(Nodo **cursada, int estudiante, int materia) {

    Cursada *c = malloc(sizeof(Cursada));
    c->materia = materia;
    c->estudiante = estudiante;
    c->aprobado = 0;
    insertarAlInicio(cursada,c);
}

//Funcion preparada para pasar como parmetro en la funcion Nodo *buscarNodo(Nodo **, funcion_equal, void *)
int _buscar_cursada(Cursada *c, Cursada *buscada) {
    return c->materia == buscada->materia && c->estudiante == buscada->estudiante;
}

//buscar_cursada:
//Busca en la lista por una cursada
Cursada *buscar_cursada(Nodo **cursada, funcion_equal igual, Cursada *buscada) {
    return (Cursada *) (buscarNodo(cursada, igual, buscada))->dato;
}

void aprobar_materia(Nodo **c, int estudiante, int materia) {
    Cursada buscar = {estudiante, materia};
    Cursada *hallada = buscar_cursada(c, _buscar_cursada, &buscar);
    if (hallada != NULL) {
        hallada->aprobado = 1;
    }

}

void desaprobar_materia(Nodo **c, int estudiante, int materia) {

}

int materia_aprobada(Nodo **c, int estudiante, int materia) {
    int aprobado = 0;
    Cursada buscar = {estudiante, materia};
    Cursada *hallada = buscar_cursada(c, _buscar_cursada, &buscar);
    if (hallada != NULL) {
        aprobado = hallada->aprobado;
    }else {
        exit(1);
    }
    return aprobado;
}