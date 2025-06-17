//
// Created by cguxt on 12/06/2025.
//

#include "estudiante.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Estudiante* crear_estudiante(int codigo, char *nombre, int edad) {
    Estudiante* e = malloc(sizeof(Estudiante));
    if (e != NULL) {
        e->codigo = codigo;
        strcpy(e->nombre, nombre);
        e->edad = edad;
    }
    return e;
}
void insertar_estudiante_al_inicio(Nodo** cabeza, Estudiante* e) {

    insertarAlInicio(cabeza, (Estudiante *)e);
}

int buscar_estudiante_por_codigo(Estudiante *actual, int *codigo) {
    return actual->codigo == *codigo;
}

int buscar_estudiante_por_nombre(Estudiante *e, char  *nombre) {
    return strcmp(e->nombre, nombre) == 0;
}

void agregar_estudiante(Nodo **cabeza, int codigo, char *nombre, int edad) {
    insertar_estudiante_al_inicio(cabeza, crear_estudiante(codigo, nombre, edad));
}