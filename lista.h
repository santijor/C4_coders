typedef struct Nodo{
    int data;
    struct Nodo* next;
} Nodo;

Nodo* crearNodo(int );

void insertarAlInicio(Nodo** , int );

void insertarAlFinal(Nodo** , int );

void eliminarNodo(Nodo** , int);

Nodo* buscarNodo(Nodo* , int );

void imprimirLista(Nodo* );

void liberarLista(Nodo** )
