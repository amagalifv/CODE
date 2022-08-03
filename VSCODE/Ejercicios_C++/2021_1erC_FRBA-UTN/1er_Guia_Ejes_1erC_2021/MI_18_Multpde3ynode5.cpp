#include <iostream>
using namespace std;

int main () {
 
 int cantMultip=0;
 int numaVerificar =0;
 int i=0;

cout << "Ingrese un numero" << endl;
cin >> cantMultip;

while (i < cantMultip) {
    if (numaVerificar % 3 == 0 && numaVerificar % 5 != 0) {
        cout << "El numero: "<< numaVerificar << " es multiplo de 3 y no de 5"<< endl;
        i++;
    }
numaVerificar=numaVerificar+1;
}

 return 0;
}
