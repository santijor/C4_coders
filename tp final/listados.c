//
// Created by cguxt on 19/06/2025.
//

#include "estudiante.h"
#include "listado.h"

int seleccionar_estudiantes_por_codigo(Estudiante *actual, const int *codigo) {
    return actual->codigo == *codigo;
}

/*funcion para seleccionar varios nodos de estudiante segun el rango de edad
 Usa el tipo rango_edades que es una estructura conteniendo edad_menor y edad_mayor definida en listado.h*/
int seleccionar_estudiantes_por_rango_de_edad(Estudiante *actual, rango_edades *rango) {
    return actual->edad >= rango->edad_menor && actual->edad <= rango->edad_mayor;
}

