//6078 omega up
#include <iostream>
#include <map>
using namespace std;
int main(){

    map<int, int> m;
    int n,p,alumnos, preg;

    cin>>n>>p;
    for (int i = 1; i <=n; i++){
        cin>>alumnos;
        m[i]=alumnos;
    }

    while (p--){
        cin>>preg;
        cout<<m[preg]<<endl;
    }
    
    

}