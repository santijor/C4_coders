#include <stdio.h>
#include <stdlib.h>

//Las explicaciones se harán por separado en cada sección del código.

/**Estructura del nodo. La variable dato de tipo int almacena el valor del nodo.
Se crea un puntero hacia el siguiente nodo.
**/

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo2 = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo2 == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevoNodo2->dato = dato;
    nuevoNodo2->siguiente = NULL;
    return nuevoNodo2;
}

void insertarAlInicio(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo2 = crearNodo(dato);
    nuevoNodo2->siguiente = *cabeza;
    *cabeza = nuevoNodo2;
}
