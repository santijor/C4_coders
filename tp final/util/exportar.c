//
// Created by cguxt on 28/06/2025.
//

#include "exportar.h"



#include <stdio.h>
#include <stdlib.h>

void exportar_estudiantes_CSV(Nodo *lista) {
    FILE *archivo = fopen("estudiantes.csv", "w");
    if (!archivo) {
        perror("No se pudo crear el archivo de estudiantes");
        return;
    }

    fprintf(archivo, "Codigo,Nombre,Edad\n");
    Nodo *actual = lista;
    while (actual) {
        Estudiante *e = (Estudiante *)actual->dato;
        fprintf(archivo, "%d,%s,%d\n", e->codigo, e->nombre, e->edad);
        actual = actual->siguiente;
    }

    fclose(archivo);
    printf("Estudiantes exportados correctamente a estudiantes.csv\n");
}

void exportar_materias_CSV(Nodo *lista) {
    FILE *archivo = fopen("materias.csv", "w");
    if (!archivo) {
        perror("No se pudo crear el archivo de materias");
        return;
    }

    fprintf(archivo, "Codigo,Nombre\n");
    Nodo *actual = lista;
    while (actual) {
        Materia *m = (Materia *)actual->dato;
        fprintf(archivo, "%d,%s\n", m->codigo, m->nombre);
        actual = actual->siguiente;
    }

    fclose(archivo);
    printf("Materias exportadas correctamente a materias.csv\n");
}

void exportar_cursadas_CSV(Nodo *lista) {
    FILE *archivo = fopen("C:\\Users\\cguxt\\CLionProjects\\estudiantes\\cursadas.csv", "w");
    if (!archivo) {
        perror("No se pudo crear el archivo de cursadas");
        return;
    }

    fprintf(archivo, "CodigoEstudiante,CodigoMateria,Aprobado\n");
    Nodo *actual = lista;
    while (actual) {
        Cursada *c = (Cursada *)actual->dato;
        fprintf(archivo, "%d,%d,%s\n", c->estudiante, c->materia, c->aprobado ? "Si" : "No");
        actual = actual->siguiente;
    }

    fclose(archivo);
    printf("Cursadas exportadas correctamente a cursadas.csv\n");
}