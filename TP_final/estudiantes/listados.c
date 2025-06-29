//
// Created by cguxt on 19/06/2025.
//

#include <stdio.h>
#include <string.h>

#include "estudiante.h"
#include "listado.h"
#include "util/abb.h"
#include "lista/lista.h"
#include "materia.h"

int seleccionar_estudiantes_por_codigo(Estudiante *actual, const int *codigo) {
    return actual->codigo == *codigo;
}

/*funcion para seleccionar varios nodos de estudiante segun el rango de edad
 Usa el tipo rango_edades que es una estructura conteniendo edad_menor y edad_mayor definida en listado.h*/
int seleccionar_estudiantes_por_rango_de_edad(Estudiante *actual, rango_edades *rango) {
    return actual->edad >= rango->edad_menor && actual->edad <= rango->edad_mayor;
}

int comparar_edades(void *p1, void *p2) {
    int e1 = ((Estudiante *)p1)->edad;
    int e2 = ((Estudiante *)p2)->edad;

    return e1 - e2;
}

int comparar_estudiantes_por_codigo(void *p1, void *p2) {
    int e1 = ((Estudiante *)p1)->codigo;
    int e2 = ((Estudiante *)p2)->codigo;
    return e1 - e2;
}

int comparar_estudiantes_por_nombre(void *p1, void *p2) {
    char *e1 = ((Estudiante *)p1)->nombre;
    char *e2 = ((Estudiante *)p2)->nombre;
    //printf("%s, %s\n", e1, e2);
    return strcmp (e1, e2);

}
int comparar_materias_por_nombre(void *p1, void *p2) {
    char *e1 = ((Materia *)p1)->nombre;
    char *e2 = ((Materia *)p2)->nombre;
    //printf("%s, %s\n", e1, e2);
    return strcmp (e1, e2);

}

nodo_abb *ordenar_estudiantes_seleccionados(Nodo **listado) {
    Nodo *cursor = *listado;
    nodo_abb  *ab_estudiante;

    while (cursor != NULL) {
        insertar_abb(&ab_estudiante, cursor->dato, comparar_edades);
        cursor = cursor->siguiente;
    }
    return ab_estudiante;
}

nodo_abb *ordenar_listados( nodo_abb **ab, Nodo *listado, comparable_abb comparar) {
    Nodo *cursor = listado;
    printf("Ordenando...\n");
    while (cursor != NULL) {
        //printf("%s \n", ((Estudiante *)cursor->dato)->nombre);
        insertar_abb(ab, cursor->dato, comparar);
        cursor = cursor->siguiente;
    }
    return *ab;
}

void imprimir_estudiante(void *dato) {
    Estudiante *actual = dato;
    printf("Estudiante: %d, %s, %d\n",actual->codigo, actual->nombre, actual->edad);

}

void imprimir_materia(void *dato) {
    Materia *actual = dato;
    printf("Materia: %d, %s\n",actual->codigo, actual->nombre);

}

void listar_estudiantes_ordenados(nodo_abb *ab_ordenados) {
    preorder(&ab_ordenados, imprimir_estudiante);
}

void listar_ordenados(nodo_abb *ab_ordenados, hacer_con_nodo imprimir_ordenados) {
    preorder(&ab_ordenados, imprimir_ordenados);
}

void listar_estudiantes(Nodo *lista) {
    printf("\nListado de estudiantes:\n");
    printf("\tCodigo\tNombre\tEdad\n");
    while (lista != NULL) {
        Estudiante *e = (Estudiante *) lista->dato;
        formatear_estudiantes(e);
        //printf("Código: %d | Nombre: %s | Edad: %d\n", e->codigo, e->nombre, e->edad);
        lista = lista->siguiente;
    }
}

void listar_materias(Nodo *lista) {
    printf("\nListado de materias:\n");
    printf("\tCodigo\tNombre\n");
    while (lista != NULL) {
        Materia *m = (Materia *) lista->dato;
        formatear_materias(m);
        //printf("Código: %d | Nombre: %s\n", m->codigo, m->nombre);
        lista = lista->siguiente;
    }
}

void formatear_estudiantes(Estudiante *actual) {
    printf("\t%d\t%s\t%d\n",actual->codigo, actual->nombre, actual->edad);
}

void formatear_materias(Materia *actual) {
    printf("\t%d\t%s\n",actual->codigo, actual->nombre);
}