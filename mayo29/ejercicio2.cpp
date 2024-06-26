#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Parentesis {
    char tipo;
    int indice;
};

int main() {
    string cadena;
    cin >> cadena;

    stack<Parentesis> pila;
    bool error = false;
    int indiceError = 0;

    for (int i = 0; i < cadena.length(); i++) {
        char caracter = cadena[i];

        if (caracter == '(' || caracter == '{' || caracter == '[') {
            Parentesis p = {caracter, i + 1};
            pila.push(p);
        } else if (caracter == ')' || caracter == '}' || caracter == ']') {
            if (pila.empty() || (
                (caracter == ')' && pila.top().tipo != '(') ||
                (caracter == '}' && pila.top().tipo != '{') ||
                (caracter == ']' && pila.top().tipo != '[')
            )) {
                error = true;
                indiceError = i + 1;
                break;
            } else {
                pila.pop();
            }
        }
    }

    if (error) {
        cout << indiceError << endl;
    } else if (!pila.empty()) {
        cout << pila.top().indice << endl;
    } else {
        cout << "Success" << endl;
    }

    return 0;
}