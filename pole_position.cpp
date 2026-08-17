#include <iostream>
#include <vector>
//include <cmath>
#include <string>

using namespace std;

using tint = int;

int main() {

    tint n;

    vector<string> resultados;
    
    while (cin >> n && n != 0){
        tint pos_inicial;

        vector<int> nro_auto(n);
        vector<int> pos_perdidas(n);
        vector<int> grilla_salida(n+1);

        bool valido = true;

        //ingreso todos los datos
        for (auto i = 0ul; i < n; ++i) {
            cin >> nro_auto[i] >> pos_perdidas[i];
            pos_inicial = i + 1 + pos_perdidas[i];
            pos_inicial > 0 && pos_inicial <= n 
                ?grilla_salida[pos_inicial] == 0 
                ? grilla_salida[pos_inicial] = nro_auto[i] : valido = false : valido = false;
        }

        if (!valido) {
            resultados.push_back("-1");
        } else {
            string resultado = "";

            for (auto i = 1ul; i <= n; i++) {
                resultado += to_string(grilla_salida[i]);

                if (i < n)
                    resultado += " ";
            }

            resultados.push_back(resultado);
        }
        
        
        //for (const string& resultado : resultados) {   //const: Quiero referirme al elemento original, pero no quiero modificarlo.
                                                        // &: significa que resultado es una referencia al elemento del vector, en lugar de ser una copia.
        //   cout << resultado << endl;
        //}

        for (auto res = resultados.begin(); res != resultados.end(); ++res) { //begin() va al primero
                                                                              //end() va al posterior del último
            cout << *res << endl;                                             //* es para acceder al contenido
        }
    }
    
  
    return 0;
}