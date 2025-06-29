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

Estudiante *buscar_estudiante(Nodo **cabeza, funcion_equal equal, void *dato) {
    return (Estudiante *) buscarNodo(cabeza, equal, dato)->dato;
}

void agregar_estudiante(Nodo **cabeza, int codigo, char *nombre, int edad) {
    insertar_estudiante_al_inicio(cabeza, crear_estudiante(codigo, nombre, edad));
}

int modificar_estudiante(Nodo* cabeza, funcion_equal equal, void* dato, char* nuevo_nombre, int nueva_edad) {
    while (cabeza != NULL) {
        if (equal(cabeza->dato, dato)) {
            Estudiante* e = (Estudiante*) cabeza->dato;
            strncpy(e->nombre, nuevo_nombre, sizeof(e->nombre) - 1);
            e->nombre[sizeof(e->nombre) - 1] = '\0';
            e->edad = nueva_edad;
            return 1;
        }
        cabeza = cabeza->siguiente;
    }
    return 0;
}