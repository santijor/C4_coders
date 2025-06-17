//
// Created by cguxt on 12/06/2025.
//
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../cursada.h"
#include "../estudiante.h"
#include "../materia.h"

void test_insertar_al_inicio() {
    Nodo *cabeza = NULL;
    Estudiante* e= crear_estudiante(10, "Matias",20);
    Estudiante* e2= crear_estudiante(20, "Agustina",24);
    insertar_estudiante_al_inicio(&cabeza,e);
    assert(((Estudiante *) cabeza->dato)->edad ==20);
    assert(((Estudiante *) obtenerDato(obtenerNodoCabeza(&cabeza)))->edad==20);
    insertar_estudiante_al_inicio(&cabeza,e2);
    assert(((Estudiante *) obtenerDato(obtenerNodoCabeza(&cabeza)))->edad==24);
    assert(((Estudiante *) obtenerDato(obtenerNodoFinal(&cabeza)))->edad==20);

    printf("test pasado!!!\n");
}

void test_buscar_estudiante() {
    Nodo *cabeza = NULL;
    int codigo = 10;
    Estudiante* e= crear_estudiante(10, "Matias",20);
    Estudiante* e2= crear_estudiante(20, "Agustina",24);
    insertar_estudiante_al_inicio(&cabeza,e);
    insertar_estudiante_al_inicio(&cabeza,e2);
    printf("test de busqueda por codigo!!!\n");
    assert(( (Estudiante *) buscarNodo(&cabeza, buscar_estudiante_por_codigo, &codigo)->dato)->codigo ==10);
    printf("test de busqueda por nombre!!!\n");
    assert(strcmp(( (Estudiante *) buscarNodo(&cabeza, buscar_estudiante_por_nombre, "Matias")->dato)->nombre,"Matias") == 0);
    printf("test pasado!!!\n");
}

void test_agregar_materias() {
    Nodo *cabeza = NULL;
    Materia *m = NULL;
    printf("test de materias!!!\n");
    agregar_materia(&cabeza, 100,"Problemas de historia");
    assert(((Materia *) (cabeza->dato))->codigo == 100);
    agregar_materia(&cabeza, 101,"algoritmos y programacion 3");
    assert(!strcmp(((Materia *) (cabeza->dato))->nombre, "algoritmos y programacion 3") );
    printf("Test de busqueda de materia por nombre\n");
    assert(buscar_materia(&cabeza, buscar_materia_por_nombre, "Problemas de historia")->codigo ==100);
    printf("test pasado!!!\n");
}

void test_cursadas(){
    Nodo *estudiantes = NULL;
    Nodo *cursadas = NULL;
    Nodo *materias = NULL;
    Cursada buscar;

    buscar.estudiante = 10;
    buscar.materia = 100;

    agregar_estudiante(&estudiantes,10, "Matias",20);
    agregar_estudiante(&estudiantes,20, "Agustina",24);
    agregar_materia(&materias, 100,"Problemas de historia");
    agregar_materia(&materias, 101,"algoritmos y programacion 3");

    agregar_cursada(&cursadas, 10,100);
    agregar_cursada(&cursadas, 20,100);
    agregar_cursada(&cursadas, 10,101);

    Cursada *encontrada = buscar_cursada(&cursadas, _buscar_cursada, &buscar);

    assert(encontrada->estudiante == 10 && encontrada->materia == 100);
    printf("Test pasado!!!\n");
}

int main() {
    test_insertar_al_inicio();
    test_buscar_estudiante();
    test_agregar_materias();
    test_cursadas();
}