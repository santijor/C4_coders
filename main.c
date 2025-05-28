#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int data;                 
    struct Nodo* next;   
} Nodo;

Nodo* crearNodo(int data) {   
}

void insertarAlInicio(Nodo** head, int data) {
}

void insertarAlFinal(Nodo** head, int data) {
}

void eliminarNodo(Nodo** head, int data) {
}

Nodo* buscarNodo(Nodo* head, int data) {
}

void imprimirLista(Nodo* head) {
}

void liberarLista(Nodo** head) {
}

int menu() {
    int opcion;
    printf("\n MENU \n");
    printf("1- Insertar al inicio\n");
    printf("2- Insertar al final\n");
    printf("3- Eliminar un nodo\n");
    printf("4- Buscar un nodo\n");
    printf("5- Imprimir lista\n");
    printf("6- Salir\n");
    printf("Elige una opcion:");
    scanf("%d", &opcion);
    return opcion;
}

int main() {
    Nodo* lista = NULL; 
    int opcion, valor;

    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                printf("Ingresar el valor");
                scanf("%d", &valor);
                insertarAlInicio(&lista, valor);
                break;
            case 2:
                printf("Ingresar el valor");
                scanf("%d", &valor);
                insertarAlFinal(&lista, valor);
                break;
            case 3:
                printf("Ingresar el valor a eliminar");
                scanf("%d", &valor);
                eliminarNodo(&lista, valor);
                break;
            case 4:
                printf("Ingresar el valor a eliminar");
                scanf("%d", &valor);
                if (buscarNodo(lista, valor)) {
                    printf("Nodo encontrado");
                } else {
                    printf("Nodo no encontrado");
                }
                break;
            case 5:
                imprimirLista(lista);
                break;
            case 6:
                liberarLista(&lista);
                printf("Memoria liberada");
                break;
            default:
                printf("Opcion invalida");
        }
    } while (opcion != 6);

    return 0;
}

