#include <iostream>
using namespace std;

// Estructura de un nodo del árbol
struct Nodo {
    int valor;
    Nodo *izquierda;
    Nodo *derecha;

    Nodo(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};

// Función para insertar un nodo en el árbol
Nodo* insertarNodo(Nodo* nodo, int valor) {
    if (nodo == nullptr) return new Nodo(valor);
    if (valor < nodo->valor)
        nodo->izquierda = insertarNodo(nodo->izquierda, valor);
    else
        nodo->derecha = insertarNodo(nodo->derecha, valor);
    return nodo;
}

// Función para buscar un valor en el árbol
bool buscarValor(Nodo* nodo, int valor) {
    if (nodo == nullptr) return false;
    if (nodo->valor == valor) return true;
    if (valor < nodo->valor)
        return buscarValor(nodo->izquierda, valor);
    else
        return buscarValor(nodo->derecha, valor);
}

// Función principal
int main() {
    int n, valorABuscar;
    cin >> n;

    Nodo* arbol = nullptr;

    // Insertar los valores en el árbol
    for (int i = 0; i < n; ++i) {
        int valor;
        cin >> valor;
        arbol = insertarNodo(arbol, valor);
    }

    // Leer el valor a buscar
    cin >> valorABuscar;

    // Buscar el valor en el árbol
    if (buscarValor(arbol, valorABuscar))
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}
