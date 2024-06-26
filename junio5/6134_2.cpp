#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct Proceso {
    int tiempo;
    int index; // Para mantener el orden de inserción
};

int main() {
    int N, K;
    cin >> N >> K;
    
    map<int, Proceso> procesos;
    queue<int> cola;
    
    // Leer los procesos e insertarlos en el mapa y la cola
    for (int i = 0; i < N; i++) {
        int id, tiempo;
        cin >> id >> tiempo;
        procesos[id] = {tiempo, i};
        cola.push(id);
    }
    
    vector<int> ordenFinalizacion;
    
    // Procesar la cola
    while (!cola.empty()) {
        int id = cola.front();
        cola.pop();
        
        if (procesos[id].tiempo <= K) {
            // Si el proceso puede finalizar en esta tanda
            ordenFinalizacion.push_back(id);
        } else {
            // Si el proceso necesita más tiempo
            procesos[id].tiempo -= K;
            cola.push(id);
        }
    }
    
    // Imprimir el orden de finalización de los procesos
    for (int id : ordenFinalizacion) {
        cout << id << endl;
    }
    
    return 0;
}
