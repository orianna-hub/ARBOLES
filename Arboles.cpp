#include <iostream>
using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

// Crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();

    nuevo->dato = valor;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;

    return nuevo;
}

// Insertar elementos
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

// RECORRIDO PREORDEN
void preorden(Nodo* raiz) {

    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

// RECORRIDO INORDEN
void inorden(Nodo* raiz) {

    if (raiz != NULL) {
        inorden(raiz->izquierda);
        cout << raiz->dato << " ";
        inorden(raiz->derecha);
    }
}

// RECORRIDO POSTORDEN
void postorden(Nodo* raiz) {

    if (raiz != NULL) {
        postorden(raiz->izquierda);
        postorden(raiz->derecha);
        cout << raiz->dato << " ";
    }
}

// PROGRAMA PRINCIPAL
int main() {

    Nodo* raiz = NULL;
    int cantidad, valor;

    cout << "Cuantos numeros desea ingresar? ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++) {

        cout << "Ingrese un numero: ";
        cin >> valor;

        raiz = insertar(raiz, valor);
    }

    cout << "\nRECORRIDO PREORDEN: ";
    preorden(raiz);

    cout << "\nRECORRIDO INORDEN: ";
    inorden(raiz);

    cout << "\nRECORRIDO POSTORDEN: ";
    postorden(raiz);

    cout << endl;

    return 0;
}