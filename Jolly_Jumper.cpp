#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;

    // Lee n mientras haya datos en la entrada 
    while (cin >> n) {
        vector<int> numeros(n);   //defino el vector con los numeros

        //itera para ingresar los n valores a evaluar en el vector numeros
        for (int i = 0; i < n; i++) {  
            cin >> numeros[i]; 
        }

        //si n=1, siempre es Jolly
        if (n == 1) {
            cout << "Jolly" << endl;
            continue;
        }

        bool jolly = true;  //jolly es true por default

        vector<bool> usado(n, false); //defino el vector que guarda las diferencias ya calculadas. se inicializa en false

        for (int i = 0; i < n - 1; i++) {
            int diferencia = abs(numeros[i + 1] - numeros[i]); //calculo la diferencia entre n[i] y el siguiente

            // La diferencia debe estar entre 1 y n-1
            if (diferencia < 1 || diferencia >= n || usado[diferencia]) {  //lo que no puede pasar es que la diferencia sea 0, >= n ó ya se haya calculado la diferencia
                jolly = false;
                break;
            }

            usado[diferencia] = true;  //cambio en usado para esa diferencia a true, significa que la calculé
        }

        if (jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }

    return 0;  //siempre termina con return 0
}