#include <iostream>
#include <vector>
using namespace std;

// Estructura de un nodo del árbol
struct Nodo {
    int valor;
    Nodo *izquierda;
    Nodo *derecha;

    Nodo(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};

// Función para insertar un nodo en el árbol T (inserción estándar)
Nodo* insertarNodoT(Nodo* nodo, int valor) {
    if (nodo == nullptr) return new Nodo(valor);
    if (valor < nodo->valor)
        nodo->izquierda = insertarNodoT(nodo->izquierda, valor);
    else
        nodo->derecha = insertarNodoT(nodo->derecha, valor);
    return nodo;
}

// Función para insertar un nodo en el árbol S (inserción invertida)
Nodo* insertarNodoS(Nodo* nodo, int valor) {
    if (nodo == nullptr) return new Nodo(valor);
    if (valor > nodo->valor)
        nodo->izquierda = insertarNodoS(nodo->izquierda, valor);
    else
        nodo->derecha = insertarNodoS(nodo->derecha, valor);
    return nodo;
}

// Función para recorrer el árbol en inorden
void inOrden(Nodo* nodo, vector<int> &valores) {
    if (nodo == nullptr) return;
    inOrden(nodo->izquierda, valores);
    valores.push_back(nodo->valor);
    inOrden(nodo->derecha, valores);
}

// Función para verificar si dos árboles son espejo
bool esEspejo(Nodo* t, Nodo* s) {
    if (t == nullptr && s == nullptr) return true;
    if (t == nullptr || s == nullptr) return false;
    return (t->valor == s->valor) &&
           esEspejo(t->izquierda, s->derecha) &&
           esEspejo(t->derecha, s->izquierda);
}

// Función principal
int main() {
    int n;
    cin >> n;

    Nodo* arbolT = nullptr;
    Nodo* arbolS = nullptr;

    // Leer los valores y construir el árbol T
    for (int i = 0; i < n; ++i) {
        int valor;
        cin >> valor;
        arbolT = insertarNodoT(arbolT, valor);
    }

    // Leer los valores y construir el árbol S
    for (int i = 0; i < n; ++i) {
        int valor;
        cin >> valor;
        arbolS = insertarNodoS(arbolS, valor);
    }

    // Verificar si los árboles son espejo
    if (esEspejo(arbolT, arbolS))
        cout << "es espejo" << endl;
    else
        cout << "no es espejo" << endl;

    // Imprimir los valores de los árboles en inorden
    vector<int> valoresT, valoresS;
    inOrden(arbolT, valoresT);
    inOrden(arbolS, valoresS);

    for (int valor : valoresT) cout << valor << " ";
    cout << endl;

    for (int valor : valoresS) cout << valor << " ";
    cout << endl;

    return 0;
}
