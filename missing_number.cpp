#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tint = int;

int main(){
    tint n;
    tint nro;
    tint faltante;
    
    cin >> n;

    vector<bool> solucion(n+1, false);

    solucion[0] = true;

    for(auto i = 1ul; i < n; ++i){
        cin >> nro;
        solucion[nro] = true;
    }

    auto it = find(solucion.begin(), solucion.end(), false);
   
    cout << "Nro faltante: " << it - solucion.begin() << endl;

    return 0;
}
