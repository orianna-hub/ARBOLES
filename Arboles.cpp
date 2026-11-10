#include <iostream>
using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

// Crear nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();

    nuevo->dato = valor;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;

    return nuevo;
}

// Insertar en el arbol
Nodo* insertar(Nodo* raiz, int valor) {

    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    }
    else {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

// Recorrido preorden
void preorden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

// Recorrido inorden
void inorden(Nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierda);
        cout << raiz->dato << " ";
        inorden(raiz->derecha);
    }
}

// Recorrido postorden
void postorden(Nodo* raiz) {
    if (raiz != NULL) {
        postorden(raiz->izquierda);
        postorden(raiz->derecha);
        cout << raiz->dato << " ";
    }
}

// Funcion principal
int main() {

    Nodo* raiz = NULL;

    // Numeros establecidos
    int numeros[] = {50, 30, 70, 20, 40, 60, 80};

    int cantidad = 7;

    // Insertar los numeros
    for (int i = 0; i < cantidad; i++) {
        raiz = insertar(raiz, numeros[i]);
    }

    cout << "RECORRIDO PREORDEN: ";
    preorden(raiz);

    cout << "\nRECORRIDO INORDEN: ";
    inorden(raiz);

    cout << "\nRECORRIDO POSTORDEN: ";
    postorden(raiz);

    cout << endl;

    return 0;
}