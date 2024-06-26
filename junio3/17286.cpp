#include <iostream>
#include <string>
using namespace std;

char letracirculo(const string& palabra, int pasos) {
    int longitud = palabra.length();
    // Calcula el índice de la letra resultante después de pasar 'pasos' veces
    int indice = ((pasos % longitud + longitud) % longitud)-1;
    return palabra[indice];
}

int main() {
    string palabra;
    int pasos;
    
    cin >> palabra;
    cin >> pasos;
    if (palabra.length()> pasos)
    {
        return 1;
    }else{
        char letraResultante = letracirculo(palabra, pasos);
    cout <<  letraResultante << endl;
    }

    return 0;
}
