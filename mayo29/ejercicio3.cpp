#include <iostream>

using namespace std;

// Estructura para la cola circular
struct ColaCircular {
    int elementos[5]; // Tamaño de la cola (puede ser modificado)
    int frente;
    int final;
};

// Inicialización de la cola
void inicializarCola(ColaCircular &cola) {
    cola.frente = -1;
    cola.final = -1;
}

// Verificar si la cola está vacía
bool estaVacia(ColaCircular cola) {
    return cola.frente == -1;
}

// Verificar si la cola está llena
bool estaLlena(ColaCircular cola) {
    return (cola.final + 1) % 5 == cola.frente; // Manejo circular del índice
}

// Agregar un elemento a la cola
void ingresarElemento(ColaCircular &cola, int elemento) {
    if (estaLlena(cola)) {
        cout << "La cola está llena. No se puede agregar el elemento." << endl;
    } else {
        if (estaVacia(cola)) {
            cola.frente = 0;
            cola.final = 0;
        } else {
            cola.final = (cola.final + 1) % 5; // Manejo circular del índice
        }
        cola.elementos[cola.final] = elemento;
        cout << "Elemento agregado a la cola." << endl;
    }
}

// Sacar un elemento de la cola
int sacarElemento(ColaCircular &cola) {
    int elemento;
    if (estaVacia(cola)) {
        cout << "La cola está vacía. No se puede sacar ningún elemento." << endl;
        return -1;
    } else {
        elemento = cola.elementos[cola.frente];
        if (cola.frente == cola.final) {
            inicializarCola(cola);
        } else {
            cola.frente = (cola.frente + 1) % 5; // Manejo circular del índice
        }
        cout << "Elemento sacado de la cola." << endl;
        return elemento;
    }
}

// Mostrar un elemento de la cola
void mostrarElemento(ColaCircular cola) {
    if (estaVacia(cola)) {
        cout << "La cola está vacía. No se puede mostrar ningún elemento." << endl;
    } else {
        int posicion = cola.frente;
        while (posicion != cola.final) {
            cout << "Elemento " << (posicion + 1) << " de la cola: " << cola.elementos[posicion] << endl;
            posicion = (posicion + 1) % 5; // Manejo circular del índice
        }
        cout << "Elemento " << (posicion + 1) << " de la cola: " << cola.elementos[posicion] << endl;
    }
}

int main() {
    ColaCircular cola;
    inicializarCola(cola);

    int opcion, elemento;
    do {
        cout << "*** Cola Circular Estática ***" << endl;
        cout << "1. Ingresar un elemento en la cola" << endl;
        cout << "2. Sacar un elemento de la cola" << endl;
        cout << "3. Mostrar un elemento de la cola" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el elemento: ";
                cin >> elemento;
                ingresarElemento(cola, elemento);
                break;
            case 2:
                sacarElemento(cola);
                break;
            case 3:
                mostrarElemento(cola);
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}