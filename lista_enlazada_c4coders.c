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

/**Metodo para crear un nodo. 
Reserva memoria dinamica para un nuevo nodo que crea e inicializa a "dato" con un valor pasado por parametro.
Inicializa a siguiente como NULL y devuelve el puntero al nodo recién creado.

*/

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

/**Crea un nuevo nodo y lo conecta al comienzo de la lista (cabeza).
Actualiza a la cabeza para que apunte al nuevo nodo.
*/

void insertarAlInicio(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo1 = crearNodo(dato);
    nuevoNodo1->siguiente = *cabeza;
    *cabeza = nuevoNodo1;
}

/**
Si la lista está vacía, establece el nuevo nodo como cabeza. Sino, recorre la lista hasta el ultimo nodo.
Conecta el nuevo nodo al final de la lista.
*/

void insertarAlFinal(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }
    Nodo* actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevoNodo;
}



void eliminarNodo(Nodo** cabeza, int dato) {
    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;
    while (actual != NULL && actual->dato != dato) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL) {
        printf("Dato no encontrado.\n");
        return;
    }
    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
    printf("Nodo con dato %d eliminado.\n", dato);
}

Nodo* buscarNodo(Nodo* cabeza, int dato) {

}

void imprimirLista(Nodo* cabeza) {

}

void liberarLista(Nodo** cabeza) {
    
}

