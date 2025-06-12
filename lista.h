typedef struct Nodo{
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo* crearNodo(int );

void insertarAlInicio(Nodo** , int );

void insertarAlFinal(Nodo** , int );

int eliminarNodo(Nodo** , int);

Nodo* buscarNodo(Nodo** , int );

void imprimirLista(Nodo** );

void imprimirNodo(Nodo* );

void liberarLista(Nodo** );

Nodo* obtenerNodoFinal(Nodo** );

Nodo* obtenerNodoCabeza(Nodo** );

int obtenerDato(Nodo* );

