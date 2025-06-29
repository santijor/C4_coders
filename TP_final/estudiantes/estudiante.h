//
// Created by cguxt on 12/06/2025.
//

#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H



#include "lista/lista.h"

typedef struct registro {
    int codigo;
    char nombre[50];
    int edad;
}Estudiante;

Estudiante* crear_estudiante(int ,char *, int);

void insertar_estudiante_al_inicio(Nodo**, Estudiante*);

int buscar_estudiante_por_codigo(Estudiante *, int  *);

int buscar_estudiante_por_nombre(Estudiante *, char  *);

Estudiante *buscar_estudiante(Nodo **, funcion_equal , void *);

void agregar_estudiante(Nodo **cabeza, int codigo, char *nombre, int edad);

int modificar_estudiante(Nodo* cabeza, funcion_equal equal, void* dato, char* nuevo_nombre, int nueva_edad);

#endif //ESTUDIANTES_H