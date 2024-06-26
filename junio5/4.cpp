#include <iostream>
#include <map>
using namespace std;
//entendimiento del map
int main(){

    map<int, int> m;
    int n=5;
    while (n--){
        int clave, valor;
        cin>>clave>>valor;
        m[clave]=valor; //cada indice va a tener su valor
    }

  for(pair <int, int>p : m){
    cout<< p.first<<" su valor es: "<< p.second<< "\n";
  }
    
    return 0;
}