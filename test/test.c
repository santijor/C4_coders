//
// Created by cguxt on 07/06/2025.
//
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../lista.h"

void test_InsertarNodoAlInicio() {
    Nodo *head = NULL;
    printf("Insert a nodo al inicio\n");
    insertarAlInicio(&head, 10);
    assert(obtenerDato(obtenerNodoCabeza(&head)) == 10);
    insertarAlInicio(&head, 20);
    assert(obtenerDato(obtenerNodoCabeza(&head)) == 20);
    assert(obtenerDato(obtenerNodoFinal(&head)) == 10);
    insertarAlInicio(&head, 30);
    assert(obtenerDato(obtenerNodoCabeza(&head)) == 30);
    assert(obtenerDato(obtenerNodoFinal(&head)) == 10);
    printf("Test passed!\n");
}

void test_InsertarNodoAlFinal() {
    Nodo *head = NULL;
    printf("iniciando test de insercion al final...\n");
    insertarAlFinal(&head, 10);
    assert(obtenerDato(obtenerNodoFinal(&head)) == 10);
    printf("Una insercion pasada!\n");
    insertarAlFinal(&head, 20);
    insertarAlFinal(&head, 30);
    assert(obtenerDato(obtenerNodoFinal(&head)) == 30);
    printf("Test passed!\n");
}

void test_buscarNodo() {
    Nodo *head = NULL;
    printf("Iniciando test de busqueda...\n");
    insertarAlInicio(&head, 10);
    insertarAlFinal(&head, 20);
    insertarAlFinal(&head, 30);
    assert(obtenerDato(buscarNodo(&head, 20)) == 20);
    assert(obtenerDato(buscarNodo(&head, 10)) == 10);
    assert(buscarNodo(&head, 40) == NULL);
    printf("Test passed!\n");
}

void test_eliminarNodo() {
    Nodo *head = NULL;
    printf("Iniciando test de eliminar nodo...\n");
    printf("Agregando nodos..\n");
    insertarAlInicio(&head, 10);
    insertarAlFinal(&head, 20);
    insertarAlFinal(&head, 30);
    printf("Eliminando nodo con dato 20\n");
    eliminarNodo(&head, 20);
    assert(buscarNodo(&head, 20) == NULL);
    assert(buscarNodo(&head, 30) != NULL);
    assert(buscarNodo(&head, 30)->dato == 30);
    printf("nodo con dato 30 existe!\n");
    imprimirLista(&head);
    eliminarNodo(&head, 30);
    printf("Eliminado nodo con dato 30\n");
    assert(buscarNodo(&head, 30) == NULL);
    imprimirLista(&head);
    assert(eliminarNodo(&head,30)==-1); //Nodo inexistente
    printf("Eliminando nodo con dato 10\n");
    assert(eliminarNodo(&head,10)==0); //Nodo inexistente
    imprimirLista(&head);

    printf("Test passed!\n");
}

int main() {
    test_InsertarNodoAlInicio();
    test_InsertarNodoAlFinal();
    test_buscarNodo();
    test_eliminarNodo();
    return 0;
}