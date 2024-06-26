//hice esta olvidando que tenia que usar map 😭
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Proceso {
    int id;
    int tiempo;
};

int main() {
    int N, K;
    cin >> N >> K;
    
    queue<Proceso> cola;
    
    // Leer los procesos e insertarlos en la cola
    for (int i = 0; i < N; i++) {
        Proceso p;
        cin >> p.id >> p.tiempo;
        cola.push(p);
    }
    
    // Vector para guardar el orden de finalización de los procesos
    vector<int> ordenFinalizacion;
    
    // Procesar la cola
    while (!cola.empty()) {
        Proceso p = cola.front();
        cola.pop();
        
        if (p.tiempo <= K) {
            // Si el proceso puede finalizar en esta tanda
            ordenFinalizacion.push_back(p.id);
        } else {
            // Si el proceso necesita más tiempo
            p.tiempo -= K;
            cola.push(p);
        }
    }
    
    // Imprimir el orden de finalización de los procesos
    for (int id : ordenFinalizacion) {
        cout << id << endl;
    }
    
    return 0;
}
