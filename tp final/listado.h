//
// Created by cguxt on 21/06/2025.
//

#ifndef LISTADO_H
#define LISTADO_H

typedef struct {
    int edad_menor;
    int edad_mayor;
}rango_edades;

int seleccionar_estudiantes_por_rango_de_edad(Estudiante *, rango_edades *);
int seleccionar_estudiantes_por_codigo(Estudiante *, const int *);
#endif //LISTADO_H
