//
// Created by cguxt on 24/06/2025.
//

#ifndef ABB_H
#define ABB_H
#include <stdlib.h>

typedef struct nodo_abb {
    void *dato;
    struct nodo_abb *derecho;
    struct nodo_abb *izquierdo;
}nodo_abb;

typedef int (*comparable_abb) (void *dato1, void *dato2);
typedef void (*hacer_con_nodo) (void *dato);

nodo_abb *crear_nodo_abb( void *);

int insertar_abb(nodo_abb **, void *, comparable_abb);

int comparar_int(const int *, const int *);

void preorder(nodo_abb **, hacer_con_nodo);

void imprimir_entero(void *);
#endif //ABB_H

