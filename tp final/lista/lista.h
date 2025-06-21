//
// Created by cguxt on 15/06/2025.
//

#ifndef LISTA_H
#define LISTA_H
typedef struct Nodo{
    void *dato;
    struct Nodo* siguiente;
} Nodo;

// puntero a funcion que recibe dos parametros punteros a void y devuelve un int
// Compara los 2 parametros y devuelve 0 o 1 como resultado
typedef int (*funcion_equal)(void *dato, void *dato2);

Nodo* crearNodo(void * );

void insertarAlInicio(Nodo** , void * );

void insertarAlFinal(Nodo** , void * );

int eliminarNodo(Nodo** , funcion_equal, void * );

// función buscarNodo: Busca en toda la lista.
// Parametros:
// tipo funcion_equal: funcion que realiza la comparacion entre los struct, devuelve 1 si son iguales, 0 en caso contrario
// void *: dato para realizar la comparacion
Nodo* buscarNodo(Nodo** , funcion_equal, void *);

void imprimirLista(Nodo** );

void imprimirNodo(Nodo* );

void liberarLista(Nodo** );

Nodo* obtenerNodoFinal(Nodo** );

Nodo* obtenerNodoCabeza(Nodo** );

void *obtenerDato(Nodo* );

/*Permite copiar nodos desde una lista a otra utilizando un criterio pasado en la funcion_equal
 * y un dato en el puntero void que deberia ser una estructura con el rango a comparar
 * Devuelve un puntero al Nodo inicial de la lista con los objetos encontrados
 */
Nodo *seleccionarNodos(Nodo**, funcion_equal, void *);
#endif //LISTA_H



