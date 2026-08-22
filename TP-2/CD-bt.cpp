#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using tint = long;

tint capacidad_maxima;
tint cantidad;
vector<tint> duraciones;//vector con todas las duraciones del input
vector<tint> canciones; //vector con las canciones seleccionadas

vector<tint> solucion; //longitudes de las canciones
tint capacidad_optima;

struct CasoResultado{
    vector<tint> canciones;
    tint suma;
};


void cd(tint capacidad_actual, tint indice) { // Capacidad, indice: posición de la canción que se está 
                                              //considerando dentro del vector duraciones
    if (capacidad_actual < 0) {
        return;
    }
    
    if (capacidad_actual == 0) {
        capacidad_optima = capacidad_actual;
        solucion = canciones;
        return;
    }
    
    if (indice == duraciones.size()) {
        if (capacidad_actual < capacidad_optima) {
            capacidad_optima = capacidad_actual;
            solucion = canciones;
        }
        return;
    }

    // Caso NO lo agrego
    cd(capacidad_actual, indice + 1);

    // Caso lo agrego
    canciones.push_back(duraciones[indice]);
    cd(capacidad_actual - duraciones[indice], indice + 1);
    canciones.pop_back();
}

int main() {
    vector<CasoResultado> resultadoFinal;
    while(cin >> capacidad_maxima >> cantidad){ 
        canciones.clear();
        duraciones.clear();
        solucion.clear();
        capacidad_optima = capacidad_maxima;

        for (tint i = 0; i < cantidad; ++i) {
            tint n;
            cin >> n;
            duraciones.push_back(n);
        }


        cd(capacidad_maxima, 0); //indice = 0 significa que comienza en la posición 0 del vector duraciones

        resultadoFinal.push_back({solucion, capacidad_maxima - capacidad_optima});
    }

    //for (const auto& res : resultadoFinal) {
    for (tint i = 0; i < resultadoFinal.size(); ++i){
        //cout << "i: " << i << endl;
        vector<tint>res = resultadoFinal[i].canciones;
        //for (tint track : res.canciones) {
        for (tint i = 0; i < res.size(); ++i){
            //cout << "track " << i << solucion[i] << " " << endl;
            cout << "track: " << res[i] << ", ";
        }
        cout << "SUMA: " << resultadoFinal[i].suma << "\n";
    }

    return 0;
}