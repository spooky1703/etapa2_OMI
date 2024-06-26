#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura de un nodo del árbol
struct Nodo {
    int peso;
    Nodo *izquierda;
    Nodo *derecha;

    Nodo(int p) : peso(p), izquierda(nullptr), derecha(nullptr) {}
};

// Función para insertar un nodo en el árbol
Nodo* insertarNodo(Nodo* nodo, int peso) {
    if (nodo == nullptr) return new Nodo(peso);
    if (peso < nodo->peso)
        nodo->izquierda = insertarNodo(nodo->izquierda, peso);
    else
        nodo->derecha = insertarNodo(nodo->derecha, peso);
    return nodo;
}

// Función para contar las hojas del árbol
int contarHojas(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    if (nodo->izquierda == nullptr && nodo->derecha == nullptr) return 1;
    return contarHojas(nodo->izquierda) + contarHojas(nodo->derecha);
}

// Función para recolectar los pesos de los frutos en las hojas en orden ascendente
void recolectarPesosHojas(Nodo* nodo, vector<int>& pesos) {
    if (nodo == nullptr) return;
    if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
        pesos.push_back(nodo->peso);
    }
    recolectarPesosHojas(nodo->izquierda, pesos);
    recolectarPesosHojas(nodo->derecha, pesos);
}

// Función principal
int main() {
    int F;
    cin >> F;
    vector<int> pesos(F);

    for (int i = 0; i < F; ++i) {
        cin >> pesos[i];
    }

    Nodo* arbol = nullptr;
    for (int peso : pesos) {
        arbol = insertarNodo(arbol, peso);
    }

    int hojas = contarHojas(arbol);
    vector<int> pesosHojas;
    recolectarPesosHojas(arbol, pesosHojas);
    sort(pesosHojas.begin(), pesosHojas.end());

    cout << hojas << endl;
    for (int peso : pesosHojas) {
        cout << peso << " ";
    }
    cout << endl;

    return 0;
}
