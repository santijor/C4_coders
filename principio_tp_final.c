// Estructura que representa una materia
typedef struct Materia {
    int codigo;
    char nombre[50];
    struct Materia* siguiente; // siguiente materia en la lista
} Materia;

// Estructura que representa un estudiante
typedef struct Estudiante {
    int codigo;
    char nombre[50];
    int edad;
    struct Estudiante* siguiente; // siguiente estudiante en la lista
} Estudiante;

// Estructura que representa una cursada (relación estudiante-materia)
typedef struct Cursada {
    int codigoEstudiante;
    int codigoMateria;
    int rendida; // 0: no rendida, 1: rendida/aprobada
    struct Cursada* siguiente; // siguiente cursada en la lista
} Cursada;

int main() {
    Estudiante* listaEstudiantes = NULL;
    Materia* listaMaterias = NULL;

    int opcion;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Registrar nuevo estudiante\n");
        printf("2. Modificar datos de estudiante\n");
        printf("3. Eliminar estudiante\n");
        printf("4. Mostrar todos los estudiantes\n");
        printf("5. Buscar estudiante por nombre\n");
        printf("6. Buscar estudiantes por rango de edad\n");
        printf("7. Registrar nueva materia\n");
        printf("8. Mostrar todas las materias\n");
        printf("9. Inscribir estudiante en materia\n");
        printf("10. Registrar rendicion de materia\n");
        printf("0. Salir del sistema\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        int id;
        char nombre[50];
        int edad;
        int minEdad, maxEdad;
        Estudiante* estudiante;
        Materia* materia;

        switch (opcion) {
            case 1:
                registrarNuevoEstudiante(&listaEstudiantes);
                break;
            case 2:
                modificarDatosEstudiante(listaEstudiantes);
                break;
            case 3:
                printf("Ingrese ID del estudiante a eliminar: ");
                scanf("%d", &id);
                eliminarEstudiantePorID(&listaEstudiantes, id);
                break;
            case 4:
                mostrarTodosLosEstudiantes(listaEstudiantes);
                break;
            case 5:
                printf("Ingrese el nombre del estudiante a buscar: ");
                scanf(" %[^"]", nombre);
                estudiante = buscarEstudiantePorNombre(listaEstudiantes, nombre);
                if (estudiante)
                    printf("Estudiante encontrado: %s (ID: %d)\n", estudiante->nombre, estudiante->id);
                else
                    printf("Estudiante no encontrado.\n");
                break;
    
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }

    } while (opcion != 0);

    return 0;
}
