//
// Created by cguxt on 15/06/2025.
//

#ifndef LISTA_H
#define LISTA_H
typedef struct Nodo{
    void *dato;
    struct Nodo* siguiente;
} Nodo;

typedef int (*funcion_equal)(void *dato, void *dato2);

Nodo* crearNodo(void * );

void insertarAlInicio(Nodo** , void * );

void insertarAlFinal(Nodo** , void * );

int eliminarNodo(Nodo** , funcion_equal, void * );

Nodo* buscarNodo(Nodo** , funcion_equal, void *);

void imprimirLista(Nodo** );

void imprimirNodo(Nodo* );

void liberarLista(Nodo** );

Nodo* obtenerNodoFinal(Nodo** );

Nodo* obtenerNodoCabeza(Nodo** );

void *obtenerDato(Nodo* );

#endif //LISTA_H



