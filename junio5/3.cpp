//for de rango
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int num =6;

while (num--){
    int numeros;
    cin>>numeros;
    v.push_back(numeros);
}
    for(auto i :v){
        cout<<i<<"\n";
    }
    return 0;
}