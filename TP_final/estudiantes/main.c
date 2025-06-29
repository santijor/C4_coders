#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"

#include "lista/lista.h"
#include "estudiante.h"
#include "materia.h"
#include "cursada.h"
#include "listado.h"
#include "util/exportar.h"

void mostrar_menu() {
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1. Agregar estudiante\n");
    printf("2. Agregar materia\n");
    printf("3. Buscar estudiante por Codigo\n");
    printf("4. Buscar estudiante por nombre\n");
    printf("5. Buscar materia por nombre\n");
    printf("6. Asociar cursada\n");
    printf("7. Aprobar materia\n");
    printf("8. Verificar si estudiante aprobo materia\n");
    printf("9. Buscar estudiantes por rango de edad\n");
    printf("10. Modificar estudiante  \n");
    printf("11. Eliminar estudiante  \n");
    printf("12. Modificar materia  \n");
    printf("13. Eliminar materia  \n");
    printf("14. Listar estudiante por rango de edad \n");
    printf("15. Listar materias  \n");
    printf("16. Exportar a CSV  \n");
    printf("17. Listar estudiantes  \n");
    printf("18. Listar estudiantes ordenados \n");
    printf("19. Listar materias ordenadas \n");
    printf("0. Salir\n");
    printf("Opcion: ");
}
void imprimirEstudiante(Estudiante *e) {
    if (!e) {
        printf("No encontrado.\n");
    } else {
        printf("Codigo: %d\n", e->codigo);
        printf("Nombre: %s\n", e->nombre);
        printf("Edad: %d\n", e->edad);
    }
}
void imprimirMateria(Materia *m) {
    if (!m) {
        printf("No encontrado.\n");
    } else {
        printf("Codigo: %d\n", m->codigo);
        printf("Nombre: %s\n", m->nombre);
    }
}

void esperar() {
    printf("Presiona una tecla para continuar...\n");
    getch();  // Espera una tecla sin mostrarla
}

void es_error(void *p) {
    if (!p) {
        printf("No se encontro el dato.\n");
    }
}

int main(void) {
    Nodo *estudiantes = NULL;
    Nodo *materias = NULL;
    Nodo *cursadas = NULL;

    int opcion;
    do {
        mostrar_menu();
        scanf("%d", &opcion);
        getchar();

        int cod, edad, cod_mat;
        char nombre[50];
        char nombre_nuevo[50];
        Estudiante *e = NULL;
        Materia *m = NULL;

        switch(opcion) {
            case 1:
                printf("Codigo estudiante: "); scanf("%d", &cod);
                printf("Nombre: "); scanf("%s", nombre);
                printf("Edad: "); scanf("%d", &edad);
                agregar_estudiante(&estudiantes, cod, nombre, edad);
                break;
            case 2:
                printf("Codigo materia: "); scanf("%d", &cod);
                printf("Nombre: "); scanf("%s", nombre);
                agregar_materia(&materias, cod, nombre);
                break;
            case 3:
                printf("Codigo a buscar: "); scanf("%d", &cod);
                Estudiante ref1 = {.codigo = cod};
                Nodo *n1 = buscarNodo(&estudiantes, (funcion_equal)buscar_estudiante_por_codigo, &ref1);
                imprimirEstudiante((Estudiante*)n1->dato);
                break;
            case 4:
                printf("Nombre a buscar: "); scanf("%s", nombre);
                Nodo *n2 = buscarNodo(&estudiantes, (funcion_equal)buscar_estudiante_por_nombre, nombre);
                imprimirEstudiante((Estudiante *)n2->dato);
                break;
            case 5:
                printf("Nombre materia: ");
                scanf("%s", nombre);
                Nodo *n3 = buscarNodo(&materias, (funcion_equal)buscar_materia_por_nombre, nombre);
                if (n3) {
                    imprimirMateria((Materia *)n3->dato);

                }else {
                    printf("No se encontro la materia.\n");
                }
                break;
            case 6:
                printf("Codigo estudiante: "); scanf("%d", &cod);
                printf("Codigo materia: "); scanf("%d", &cod_mat);
                e = (Estudiante *) buscarNodo(&estudiantes, (funcion_equal)buscar_estudiante_por_codigo, &cod);
                m = (Materia *) buscarNodo(&materias, (funcion_equal)buscar_materia_por_codigo, &cod_mat);
                if (e && m) {
                    agregar_cursada(&cursadas, cod, cod_mat);
                }else {
                    printf("No se encontro la materia o el alumno.\n");
                    break;
                }
                break;
            case 7:
                printf("Codigo estudiante: "); scanf("%d", &cod);
                printf("Codigo materia: "); scanf("%d", &cod_mat);
                e = (Estudiante *) buscarNodo(&estudiantes, (funcion_equal)buscar_estudiante_por_codigo, &cod);
                m = (Materia *) buscarNodo(&materias, (funcion_equal)buscar_materia_por_codigo, &cod_mat);
                if (e && m) {
                    agregar_cursada(&cursadas, cod, cod_mat);
                }else {
                    printf("No se encontro la materia o el alumno.\n");
                }
                aprobar_materia(&cursadas, cod, cod_mat);
                printf("Materia aprobada \n");
                break;
            case 8:
                printf("Codigo estudiante: "); scanf("%d", &cod);
                printf("Codigo materia: "); scanf("%d", &cod_mat);
                e = (Estudiante *) buscarNodo(&estudiantes, (funcion_equal)buscar_estudiante_por_codigo, &cod);
                m = (Materia *) buscarNodo(&materias, (funcion_equal)buscar_materia_por_codigo, &cod_mat);
                if (e && m) {
                    if (materia_aprobada(&cursadas, cod, cod_mat))
                        printf("Aprobada\n");
                    else
                        printf("No aprobada\n");
                }else {
                    printf("Codigo inexistente o estudiante no inscripto a la materia");
                }
                break;
            case 9: {
                rango_edades r;
                printf("Edad minima: "); scanf("%d", &r.edad_menor);
                printf("Edad maxima: "); scanf("%d", &r.edad_mayor);
                Nodo *actual = estudiantes;
                while (actual) {
                    if (seleccionar_estudiantes_por_rango_de_edad((Estudiante*)actual->dato, &r))
                        printf("%s (%d)\n", ((Estudiante*)actual->dato)->nombre, ((Estudiante*)actual->dato)->edad);
                    actual = actual->siguiente;
                }
                break;
            }
            case 10:
                printf("Codigo del estudiante a modificar: "); scanf("%d", &cod);
                printf("Nuevo nombre: "); scanf("%s", nombre);
                printf("Nueva edad: "); scanf("%d", &edad);
                Estudiante ref_mod = {.codigo = cod};
                if (modificar_estudiante(estudiantes, (funcion_equal)buscar_estudiante_por_codigo, &ref_mod, nombre, edad))
                    printf("Estudiante modificado correctamente.\n");
                else
                    printf("Estudiante no encontrado.\n");
                break;
            case 11:
                printf("Ingrese codigo estudiante a eliminar: ");
                scanf("%d", &cod);
                if (eliminarNodo(&estudiantes, (funcion_equal)buscar_estudiante_por_codigo, &cod))
                    printf("Estudiante eliminado correctamente.\n");
                else
                    printf("Estudiante no encontrado.\n");
                break;
            case 12:
                printf("Nombre de materia a modificar: "); scanf("%s", nombre);
                printf("Nuevo nombre: "); scanf("%s", nombre_nuevo);
                if (modificar_materia(materias, (funcion_equal)buscar_materia_por_nombre, nombre, nombre_nuevo))
                    printf("Materia modificada correctamente.\n");
                else
                    printf("Materia no encontrada.\n");
                break;
            case 13:
                printf("Nombre de materia a eliminar: ");
                scanf("%s", nombre);
                if (eliminarNodo(&materias, (funcion_equal)buscar_materia_por_nombre, nombre))
                    printf("Materia eliminada correctamente.\n");
                else
                    printf("Materia no encontrada.\n");
                break;
            case 14:
                listar_estudiantes(estudiantes);
                break;
            case 15:
                listar_materias(materias);
                break;
            case 16:
                exportar_cursadas_CSV(cursadas);
                exportar_estudiantes_CSV(estudiantes);
                exportar_materias_CSV(materias);
                break;
            case 17:
                listar_estudiantes(estudiantes);
                break;
            case 18:
                nodo_abb *abb_estudiante = NULL;
                listar_ordenados(ordenar_listados(&abb_estudiante,estudiantes, comparar_estudiantes_por_nombre), imprimir_estudiante);
                break;
            case 19:
                nodo_abb *abb_materia = NULL;
                listar_ordenados(ordenar_listados(&abb_materia,materias, comparar_materias_por_nombre), imprimir_materia);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
        if (opcion != 0) {
            esperar();
        }
    } while (opcion != 0);

    return 0;
}

