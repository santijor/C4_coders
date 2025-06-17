//
// Created by cguxt on 12/06/2025.
//

#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#endif //ESTUDIANTES_H

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

void agregar_estudiante(Nodo **cabeza, int codigo, char *nombre, int edad);