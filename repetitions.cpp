#include <iostream>
#include <string>


using namespace std;

int main() {

    string dna;
    cin >> dna;
   
        int contador = 1;
        int mayor = 1;

        for (int i = 1; i < dna.length(); i++){
           if (dna[i] == dna[i - 1]){
            contador++;
           }else{
            contador = 1;
           }

           mayor = max(contador, mayor);
        }

    cout << mayor << endl;
    
    return 0;
}


