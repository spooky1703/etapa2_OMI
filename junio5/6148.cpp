#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> m;
    int nTrad, numpeg,clave,valor,preg;

    cin>>nTrad>>numpeg;
    while (nTrad--){
        cin>> clave>>valor;
        m[clave] =valor;
    }
    while (numpeg--){
        cin>>preg;
        if (m.count(preg)){
            cout<< m[preg]<<" ";
        }else{
            cout<<"C? "<<endl;
        }
    }
}