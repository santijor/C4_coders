#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

//Las explicaciones se harán por separado en cada sección del código.

/**Estructura del nodo. La variable dato de tipo int almacena el valor del nodo.
Se crea un puntero hacia el siguiente nodo.
**/

Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo1 = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo1 == NULL) {
        printf("Error al asignar memoria, el nodo es null.\n");
        exit(1);
    }
    nuevoNodo1->dato = dato;
    nuevoNodo1->siguiente = NULL;
    return nuevoNodo1;
}

void insertarAlInicio(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo1 = crearNodo(dato);
    nuevoNodo1->siguiente = *cabeza;
    *cabeza = nuevoNodo1;
}

void imprimirNodo(Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacia\n");
    }
    printf("Dato: %d\n", cabeza->data);
}

Nodo *obtenerNodoFinal(Nodo** cabeza) {
    Nodo *cursor = *cabeza;
    while (cursor->siguiente != NULL) {
        cursor = cursor->siguiente;
    }
    return cursor;
}
void insertarAlFinal(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo1 = crearNodo(dato);
    Nodo* nodoFinal = obtenerNodoFinal(cabeza);
    nodoFinal->siguiente = nuevoNodo1;
}




