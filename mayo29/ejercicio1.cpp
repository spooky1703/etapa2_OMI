#include <iostream>

using namespace std;

// Función para generar la traspuesta de una matriz dinámica
void transponerMatriz(int** matriz, int filas, int cols, int** matrizTranspuesta) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            matrizTranspuesta[j][i] = matriz[i][j];
        }
    }
}

int main() {
    int filas, cols;

    // Pedir al usuario el número de filas y columnas de la matriz
    cout << "Ingrese el número de filas: ";
    cin >> filas;
    cout << "Ingrese el número de columnas: ";
    cin >> cols;

    // Crear matrices dinámicas
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[cols];
    }

    int** matrizTranspuesta = new int*[cols];
    for (int i = 0; i < cols; i++) {
        matrizTranspuesta[i] = new int[filas];
    }

    // Inicializar matriz con valores
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            matriz[i][j] = i * cols + j;
        }
    }

    // Mostrar matriz original
    cout << "Matriz original:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Generar traspuesta de la matriz
    transponerMatriz(matriz, filas, cols, matrizTranspuesta);

    // Mostrar matriz traspuesta
    cout << "Matriz traspuesta:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < filas; j++) {
            cout << matrizTranspuesta[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    for (int i = 0; i < cols; i++) {
        delete[] matrizTranspuesta[i];
    }
    delete[] matrizTranspuesta;

    return 0;
}