//
// Created by cguxt on 17/06/2025.
//

#include "materia.h"

#include <stdlib.h>
#include <string.h>

#include "lista/lista.h"

void agregar_materia(Nodo **materias, int codigo, char* nombre) {
    Materia *materia = (Materia *)malloc(sizeof(Materia));
    materia->codigo = codigo;
    strcpy(materia->nombre, nombre);
    insertarAlInicio(materias, materia);
}

int buscar_materia_por_nombre(Materia *m, char  *nombre) {
    return strcmp(m->nombre, nombre) == 0;
}

Materia *buscar_materia(Nodo **materias, funcion_equal equal, void *dato ) {
    return (Materia *)buscarNodo(materias, equal, dato)->dato;
}
int buscar_materia_por_codigo(Materia *m, int *codigo) {
    return m->codigo==*codigo;
}

int modificar_materia(Nodo* materias, funcion_equal equal, void* dato, char* nuevo_nombre) {
    while (materias != NULL) {
        if (equal(materias->dato, dato)) {
            Materia* m = (Materia*) materias->dato;
            strncpy(m->nombre, nuevo_nombre, sizeof(m->nombre) - 1);
            m->nombre[sizeof(m->nombre) - 1] = '\0';
            return 1;
        }
        materias = materias->siguiente;
    }
    return 0;
}
