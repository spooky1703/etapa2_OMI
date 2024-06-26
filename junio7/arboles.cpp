#include <iostream>
using namespace std;

// Estructura de un nodo del árbol
struct Nodo {
    int valor;
    Nodo *izquierda;
    Nodo *derecha;

    Nodo(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};

// Prototipos de funciones
Nodo* insertarNodo(Nodo* nodo, int valor);
void muestraAcostado(Nodo* nodo, int nivel);
void graficarArbol(Nodo* nodo);
bool busqueda(Nodo* nodo, int x);
Nodo* buscaMayor(Nodo* nodo);
Nodo* buscaMenor(Nodo* nodo);
Nodo* eliminarPredecesor(Nodo* nodo, int x);
Nodo* eliminarSucesor(Nodo* nodo, int x);
void preOrden(Nodo* nodo);
void inOrden(Nodo* nodo);
void postOrden(Nodo* nodo);
void recorridoNiveles(Nodo* nodo);
void imprimirNivel(Nodo* nodo, int nivel);
int altura(Nodo* nodo);
int contarHojas(Nodo* nodo);
int contarNodos(Nodo* nodo);
void arbolEspejo(Nodo* nodo);
bool esCompleto(Nodo* nodo);
bool esCompletoRec(Nodo* nodo, int index, int totalNodos);
bool esLleno(Nodo* nodo);
bool esLlenoRec(Nodo* nodo, int h, int nivel);
void podarArbol(Nodo* &nodo);
void menu();

// Función principal
int main() {
    menu();
    return 0;
}

// Implementación de las funciones
Nodo* insertarNodo(Nodo* nodo, int valor) {
    if (nodo == nullptr) return new Nodo(valor);
    if (valor < nodo->valor)
        nodo->izquierda = insertarNodo(nodo->izquierda, valor);
    else if (valor > nodo->valor)
        nodo->derecha = insertarNodo(nodo->derecha, valor);
    return nodo;
}

void muestraAcostado(Nodo* nodo, int nivel) {
    if (nodo == nullptr) return;
    muestraAcostado(nodo->derecha, nivel + 1);
    for (int i = 0; i < nivel; ++i) cout << "   ";
    cout << nodo->valor << endl;
    muestraAcostado(nodo->izquierda, nivel + 1);
}

void graficarArbol(Nodo* nodo) {
    muestraAcostado(nodo, 0);
}

bool busqueda(Nodo* nodo, int x) {
    if (nodo == nullptr) return false;
    if (nodo->valor == x) return true;
    if (x < nodo->valor) return busqueda(nodo->izquierda, x);
    return busqueda(nodo->derecha, x);
}

Nodo* buscaMayor(Nodo* nodo) {
    if (nodo == nullptr || nodo->derecha == nullptr) return nodo;
    return buscaMayor(nodo->derecha);
}

Nodo* buscaMenor(Nodo* nodo) {
    if (nodo == nullptr || nodo->izquierda == nullptr) return nodo;
    return buscaMenor(nodo->izquierda);
}

Nodo* eliminarPredecesor(Nodo* nodo, int x) {
    if (nodo == nullptr) return nodo;
    if (x < nodo->valor) nodo->izquierda = eliminarPredecesor(nodo->izquierda, x);
    else if (x > nodo->valor) nodo->derecha = eliminarPredecesor(nodo->derecha, x);
    else {
        if (nodo->izquierda == nullptr) {
            Nodo* temp = nodo->derecha;
            delete nodo;
            return temp;
        } else if (nodo->derecha == nullptr) {
            Nodo* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }
        Nodo* temp = buscaMayor(nodo->izquierda);
        nodo->valor = temp->valor;
        nodo->izquierda = eliminarPredecesor(nodo->izquierda, temp->valor);
    }
    return nodo;
}

Nodo* eliminarSucesor(Nodo* nodo, int x) {
    if (nodo == nullptr) return nodo;
    if (x < nodo->valor) nodo->izquierda = eliminarSucesor(nodo->izquierda, x);
    else if (x > nodo->valor) nodo->derecha = eliminarSucesor(nodo->derecha, x);
    else {
        if (nodo->izquierda == nullptr) {
            Nodo* temp = nodo->derecha;
            delete nodo;
            return temp;
        } else if (nodo->derecha == nullptr) {
            Nodo* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }
        Nodo* temp = buscaMenor(nodo->derecha);
        nodo->valor = temp->valor;
        nodo->derecha = eliminarSucesor(nodo->derecha, temp->valor);
    }
    return nodo;
}

void preOrden(Nodo* nodo) {
    if (nodo == nullptr) return;
    cout << nodo->valor << " ";
    preOrden(nodo->izquierda);
    preOrden(nodo->derecha);
}

void inOrden(Nodo* nodo) {
    if (nodo == nullptr) return;
    inOrden(nodo->izquierda);
    cout << nodo->valor << " ";
    inOrden(nodo->derecha);
}

void postOrden(Nodo* nodo) {
    if (nodo == nullptr) return;
    postOrden(nodo->izquierda);
    postOrden(nodo->derecha);
    cout << nodo->valor << " ";
}

void recorridoNiveles(Nodo* nodo) {
    if (nodo == nullptr) return;
    int h = altura(nodo);
    for (int i = 1; i <= h; i++) {
        imprimirNivel(nodo, i);
    }
}

void imprimirNivel(Nodo* nodo, int nivel) {
    if (nodo == nullptr) return;
    if (nivel == 1) {
        cout << nodo->valor << " ";
    } else if (nivel > 1) {
        imprimirNivel(nodo->izquierda, nivel - 1);
        imprimirNivel(nodo->derecha, nivel - 1);
    }
}

int altura(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    int izqAltura = altura(nodo->izquierda);
    int derAltura = altura(nodo->derecha);
    return max(izqAltura, derAltura) + 1;
}

int contarHojas(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    if (nodo->izquierda == nullptr && nodo->derecha == nullptr) return 1;
    return contarHojas(nodo->izquierda) + contarHojas(nodo->derecha);
}

int contarNodos(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return contarNodos(nodo->izquierda) + contarNodos(nodo->derecha) + 1;
}

void arbolEspejo(Nodo* nodo) {
    if (nodo == nullptr) return;
    swap(nodo->izquierda, nodo->derecha);
    arbolEspejo(nodo->izquierda);
    arbolEspejo(nodo->derecha);
}

bool esCompleto(Nodo* nodo) {
    if (nodo == nullptr) return true;
    int totalNodos = contarNodos(nodo);
    return esCompletoRec(nodo, 0, totalNodos);
}

bool esCompletoRec(Nodo* nodo, int index, int totalNodos) {
    if (nodo == nullptr) return true;
    if (index >= totalNodos) return false;
    return esCompletoRec(nodo->izquierda, 2 * index + 1, totalNodos) &&
           esCompletoRec(nodo->derecha, 2 * index + 2, totalNodos);
}

bool esLleno(Nodo* nodo) {
    if (nodo == nullptr) return true;
    int h = altura(nodo);
    return esLlenoRec(nodo, h, 0);
}

bool esLlenoRec(Nodo* nodo, int h, int nivel) {
    if (nodo == nullptr) return true;
    if (nivel == h - 1) {
        if (nodo->izquierda == nullptr && nodo->derecha == nullptr) return true;
        if (nodo->izquierda != nullptr && nodo->derecha != nullptr) return true;
        return false;
    }
    if (nodo->izquierda == nullptr || nodo->derecha == nullptr) return false;
    return esLlenoRec(nodo->izquierda, h, nivel + 1) && esLlenoRec(nodo->derecha, h, nivel + 1);
}

void podarArbol(Nodo* &nodo) {
    if (nodo == nullptr) return;
    podarArbol(nodo->izquierda);
    podarArbol(nodo->derecha);
    delete nodo;
    nodo = nullptr;
}

void menu() {
    Nodo* arbol = nullptr;
    int opcion, valor;
    do {
        cout << "\n...[ ARBOL BINARIO ]... \n";
        cout << "[1] Insertar elemento \n";
        cout << "[2] Mostrar valor de la raiz \n";
        cout << "[3] Mostrar arbol acostado \n";
        cout << "[4] Graficar arbol \n";
        cout << "[5] Buscar elemento \n";
        cout << "[6] Recorrer el arbol en PreOrden \n";
        cout << "[7] Recorrer el arbol en InOrden \n";
        cout << "[8] Recorrer el arbol en PostOrden \n";
        cout << "[9] Eliminar un nodo del arbol PREDECESOR \n";
        cout << "[10] Eliminar un nodo del arbol SUCESOR \n";
        cout << "[11] Recorrer el arbol por niveles (Amplitud) \n";
        cout << "[12] Altura del arbol \n";
        cout << "[13] Cantidad de hojas del arbol \n";
        cout << "[14] Cantidad de nodos del arbol \n";
        cout << "[15] Mostrar arbol espejo \n";
        cout << "[16] Revisa si es un arbol binario completo \n";
        cout << "[17] Revisa si es un arbol binario lleno \n";
        cout << "[18] Podar el arbol \n";
        cout << "[19] SALIR \n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                arbol = insertarNodo(arbol, valor);
                break;
            case 2:
                if (arbol) cout << "Valor de la raiz: " << arbol->valor << endl;
                else cout << "El arbol esta vacio." << endl;
                break;
            case 3:
                muestraAcostado(arbol, 0);
                break;
            case 4:
                graficarArbol(arbol);
                break;
            case 5:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                cout << (busqueda(arbol, valor) ? "Elemento encontrado." : "Elemento no encontrado.") << endl;
                break;
            case 6:
                preOrden(arbol);
                cout << endl;
                break;
            case 7:
                inOrden(arbol);
                cout << endl;
                break;
            case 8:
                postOrden(arbol);
                cout << endl;
                break;
            case 9:
                cout << "Ingrese valor del predecesor a eliminar: ";
                cin >> valor;
                arbol = eliminarPredecesor(arbol, valor);
                break;
            case 10:
                cout << "Ingrese valor del sucesor a eliminar: ";
                cin >> valor;
                arbol = eliminarSucesor(arbol, valor);
                break;
            case 11:
                recorridoNiveles(arbol);
                cout << endl;
                break;
            case 12:
                cout << "Altura del arbol: " << altura(arbol) << endl;
                break;
            case 13:
                cout << "Cantidad de hojas del arbol: " << contarHojas(arbol) << endl;
                break;
            case 14:
                cout << "Cantidad de nodos del arbol: " << contarNodos(arbol) << endl;
                break;
            case 15:
                arbolEspejo(arbol);
                cout << "Arbol espejo mostrado." << endl;
                break;
            case 16:
                cout << (esCompleto(arbol) ? "El arbol es completo." : "El arbol no es completo.") << endl;
                break;
            case 17:
                cout << (esLleno(arbol) ? "El arbol es lleno." : "El arbol no es lleno.") << endl;
                break;
            case 18:
                podarArbol(arbol);
                cout << "Arbol podado." << endl;
                break;
        }
    } while (opcion != 19);
}