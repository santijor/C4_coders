//
// Created by cguxt on 24/06/2025.
//

#include <stdlib.h>
#include "abb.h"

#include <stdio.h>


nodo_abb *crear_nodo_abb(void *dato) {
    nodo_abb *nodo = malloc(sizeof(nodo_abb));
    nodo->dato = dato;
    nodo->izquierdo = NULL;
    nodo->derecho = NULL;
    return nodo;
}

int insertar_abb(nodo_abb **abb, void *dato, comparable_abb comparar) {

    if (*abb == NULL) {
        *abb = crear_nodo_abb(dato);
        if (*abb == NULL) {
            return -1;
        }
    }else {
        if (comparar(dato, (*abb)->dato) < 0) {
            if ((*abb)->izquierdo)
                insertar_abb(&(*abb)->izquierdo, dato, comparar);
            else {
                (*abb)->izquierdo = crear_nodo_abb(dato);
            }
        }else if (comparar(dato, (*abb)->dato) > 0) {
            if ((*abb)->derecho)
                insertar_abb(&(*abb)->derecho, dato, comparar);
            else
                (*abb)->derecho = crear_nodo_abb(dato);
        }
    }
    return 0;
}

int comparar_int(const int *pa, const int *pb) {
    int a = *pa;
    int b = *pb;
    return a-b;
}

void preorder(nodo_abb **nodo, hacer_con_nodo hacer) {
    if (nodo != NULL) {
        if ((*nodo)->izquierdo != NULL) {
            preorder(&(*nodo)->izquierdo,hacer);
        }
        hacer((*nodo)->dato);
        if ((*nodo)->derecho != NULL) {
            preorder(&(*nodo)->derecho, hacer);
        }
    }

}

void imprimir_entero(void *d) {
    printf("%d\n", (*( int *)d));
}