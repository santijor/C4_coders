#include <stdio.h>
#include <stdlib.h>

//Las explicaciones se harán por separado en cada sección del código.

/**Estructura del nodo. La variable dato de tipo int almacena el valor del nodo.
Se crea un puntero hacia el siguiente nodo.
**/

typedef struct Nodo1 {
    int dato;
    struct Nodo1* siguiente;
} Nodo1;

Nodo1* crearNodo(int dato) {
    Nodo1* nuevoNodo2 = (Nodo1*)malloc(sizeof(Nodo1));
    if (nuevoNodo2 == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevoNodo2->dato = dato;
    nuevoNodo2->siguiente = NULL;
    return nuevoNodo2;
}
