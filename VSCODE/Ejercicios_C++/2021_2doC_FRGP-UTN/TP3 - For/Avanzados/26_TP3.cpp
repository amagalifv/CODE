#include <iostream>
#include <cstdlib>
using namespace std;

/*
26- Dada una lista de 10 números informar la cantidad de duplas de números impares
consecutivos.
Ejemplo: 12, 3, 5, 7, 6, 9, 13, 10, 7, -5. En esta lista las duplas son: 3:5, 5:7, 9:13, 7:-5 por lo
tanto se informará que hay 4 duplas de números impares consecutivos.
*/

int main () {
    int num;
    int numAnt=2;
    int cont=0;

    for (int i=0; i<10; i++) {
        cout<<"ingrese un numero"<<endl;
        cin>>num;

        if (num%2!=0 && numAnt%2!=0) {
            cont++;
        }

        numAnt=num;
    }

    cout<<"Cantidad de duplas impares: "<<cont<<endl;

    system("pause");
    return 0;
}