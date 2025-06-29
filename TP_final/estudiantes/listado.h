//
// Created by cguxt on 21/06/2025.
//

#ifndef LISTADO_H
#define LISTADO_H
#include "util/abb.h"
#include "materia.h"

typedef struct {
    int edad_menor;
    int edad_mayor;
}rango_edades;

int seleccionar_estudiantes_por_rango_de_edad(Estudiante *, rango_edades *);
int seleccionar_estudiantes_por_codigo(Estudiante *, const int *);
void imprimir_estudiante(void *);
void listar_estudiantes_ordenados(nodo_abb *);
nodo_abb *ordenar_estudiantes_seleccionados(Nodo **);
void listar_materias(Nodo *lista);
void listar_estudiantes(Nodo *lista);
void formatear_estudiantes(Estudiante *);
void formatear_materias(Materia *actual);
void listar_ordenados(nodo_abb *, hacer_con_nodo );
nodo_abb *ordenar_listados(nodo_abb **, Nodo *listado, comparable_abb );
int comparar_estudiantes_por_nombre(void *p1, void *p2);
int comparar_materias_por_nombre(void *p1, void *p2);
void imprimir_materia(void *dato);
#endif //LISTADO_H
