#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

//Las explicaciones se harán por separado en cada sección del código.

/**Estructura del nodo. La variable dato de tipo int almacena el valor del nodo.
Se crea un puntero hacia el siguiente nodo.
**/

Nodo* crearNodo(void *dato) {
    Nodo* nuevoNodo1 = malloc(sizeof(Nodo));
    if (nuevoNodo1 == NULL) {
        printf("Error al asignar memoria, el nodo es null.\n");
        exit(1);
    }
    nuevoNodo1->dato = dato;
    nuevoNodo1->siguiente = NULL;
    return nuevoNodo1;
}

void insertarAlInicio(Nodo** cabeza, void *dato) {
    Nodo* nuevoNodo1 = crearNodo(dato);
    Nodo* actual;
    if (cabeza == NULL) {
        *cabeza = nuevoNodo1;
    }else {
        actual = *cabeza;
        *cabeza = nuevoNodo1;
        nuevoNodo1->siguiente = actual;
    }
}

void imprimirNodo(Nodo* nodo) {
    if (nodo == NULL) {
        printf("Lista vacia\n");
    }
    printf("Dato: %d\n", nodo->dato);
}

Nodo *obtenerNodoFinal(Nodo** cabeza) {
    Nodo *cursor = *cabeza;
    if (cursor != NULL) {
        while (cursor->siguiente != NULL) {
            cursor = cursor->siguiente;
        }
    }
    return cursor;
}

void insertarAlFinal(Nodo** cabeza, void *dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    Nodo* nodoFinal = obtenerNodoFinal(cabeza);
    if (nodoFinal == NULL) {
        *cabeza = nuevoNodo;
    }else {
        nodoFinal->siguiente = nuevoNodo;
    }
}

void *obtenerDato(Nodo* nodo) {
    void *dato = NULL;
    if (nodo != NULL) {
        dato =  nodo->dato;
    }
    return dato;
}

Nodo* obtenerNodoCabeza(Nodo** cabeza) {
    if (cabeza != NULL) {
        return *cabeza;
    }
}

Nodo* buscarNodo(Nodo** cabeza, funcion_equal igual, void *dato) {
    Nodo* cursor = *cabeza;
    if (cursor != NULL) {
        int encontrado = 0;
        do {
            if (igual(cursor->dato, dato)) {
                encontrado = 1;
            }else {
                cursor = cursor->siguiente;
            }
        }while (!encontrado && cursor != NULL);
    }
    return cursor;
}

int eliminarNodo(Nodo** cabeza, funcion_equal igual, void *dato) {
    int error = -1;
    Nodo* cursor = *cabeza;
    Nodo* antecesor = cursor;
    while (cursor != NULL) {
        if (!igual(cursor->dato, dato )) {
            antecesor = cursor;
            cursor = cursor->siguiente;
        }else {
            if (cursor == *cabeza) {
                printf("Es cabeza\n");
                free(*cabeza);
                *cabeza = NULL;
                cabeza = NULL;
            }else {
                antecesor->siguiente = cursor->siguiente;
                free(cursor);
                cursor = NULL;
            }
            error = 0;
            break;
        }
    }
    return error;
}

void printList(Nodo* nodo) {
    if (nodo != NULL) {
        printf("Dato: %d\n", nodo->dato);
        printList(nodo->siguiente);
    }
}
void imprimirLista(Nodo** cabeza) {
    Nodo* cursor = *cabeza;
    printf("inicio %d\n",*cabeza);
    if (cursor != NULL) {
        printList(cursor);
    }
}
