#include <iostream>
#include <vector>

using namespace std;

const int N = 8; // Tamaño del tablero

bool esSeguro(int x, int y, vector<vector<bool> > &tablero) {
  // Verificar si el caballo en (x, y) está en captura
  for (int i = -2; i <= 2; i++) {
    for (int j = -2; j <= 2; j++) {
      if (abs(i) + abs(j) == 3) { // Movimiento de caballo
        int nx = x + i;
        int ny = y + j;
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && tablero[nx][ny]) {
          return false; // El caballo está en captura
        }
      }
    }
  }
  return true; // El caballo está seguro
}

void encontrarConfiguracion(vector<vector<bool> > &tablero) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      tablero[i][j] = true; // Colocar un caballo en (i, j)
      bool esValido = true;
      for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
          if (tablero[k][l] &&!esSeguro(k, l, tablero)) {
            esValido = false;
            break;
          }
        }
        if (!esValido) break;
      }
      if (esValido) {
        // Mostrar la configuración de caballos
        for (int k = 0; k < N; k++) {
          for (int l = 0; l < N; l++) {
            if (tablero[k][l]) {
              cout << "C ";
            } else {
              cout << ". ";
            }
          }
          cout << endl;
        }
        cout << endl;
        return;
      }
      tablero[i][j] = false; // Quitar el caballo de (i, j)
    }
  }
}

int main() {
  vector<vector<bool> > tablero(N, vector<bool>(N, false));
  encontrarConfiguracion(tablero);
  return 0;
}