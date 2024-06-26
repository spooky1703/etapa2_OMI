#include <iostream>
#include <map>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    map<int, int> objetos;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            int tipo;
            cin >> tipo;
            objetos[tipo]++;
        }
    }
    for(auto objeto : objetos) {
        cout << objeto.second << " ";
    }
    cout << endl;
    return 0;
}