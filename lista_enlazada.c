#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

Nodo* cabeza = NULL;

// Crear un nuevo nodo
Nodo* crearNodo(int dato) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Insertar al final
void insertar(int nuevoDato) {
    Nodo* nuevoNodo = crearNodo(nuevoDato);

    if (cabeza == NULL) {
        cabeza = nuevoNodo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
    printf("Se insertó el dato: %d\n", nuevoDato);
}

// Imprimir la lista
void imprimirLista() {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    Nodo* actual = cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Buscar un valor
int buscar(int valorBuscado) {
    if (cabeza == NULL) {
        printf("La lista está vacía. El valor %d no fue encontrado.\n", valorBuscado);
        return 0;
    }

    Nodo* actual = cabeza;
    while (actual != NULL) {
        if (actual->dato == valorBuscado) {
            printf("El valor %d fue encontrado en la lista.\n", valorBuscado);
            return 1;
        }
        actual = actual->siguiente;
    }

    printf("El valor %d no fue encontrado en la lista.\n", valorBuscado);
    return 0;
}

// Eliminar un nodo
int eliminar(int valorEliminar) {
    if (cabeza == NULL) {
        printf("La lista está vacía. No se puede eliminar %d.\n", valorEliminar);
        return 0;
    }

    if (cabeza->dato == valorEliminar) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
        printf("Se eliminó el dato: %d\n", valorEliminar);
        return 1;
    }

    Nodo* actual = cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->dato != valorEliminar) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("El valor %d no fue encontrado para eliminarse.\n", valorEliminar);
        return 0;
    }

    anterior->siguiente = actual->siguiente;
    free(actual);
    printf("Se eliminó el dato: %d\n", valorEliminar);
    return 1;
}

// Función principal con menú interactivo
int main() {
    int R = 0;
    do {
        int tamaño;
        printf("\nIngresa el tamaño de la lista: ");
        scanf("%d", &tamaño);

        for (int i = 0; i < tamaño; i++) {
            int valor;
            printf("Inserta el valor #%d: ", i + 1);
            scanf("%d", &valor);
            insertar(valor);
        }

        imprimirLista();

        int eliminarValor;
        printf("¿Cuál dato deseas eliminar? ");
        scanf("%d", &eliminarValor);
        eliminar(eliminarValor);

        int buscarValor;
        printf("¿Qué dato deseas buscar? ");
        scanf("%d", &buscarValor);
        buscar(buscarValor);

        imprimirLista();

        printf("¿Quieres volver a intentarlo?\nSI (1)\nNO (0)\n");
        scanf("%d", &R);

    } while (R == 1);

    return 0;
}