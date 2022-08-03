#include <iostream>
using namespace std;

int main () {
    int num =0;
    int mayor=0;
    int menor=0;
    int canti=0;
    int posicionMaj=0;
    int posicionMin=0;

    cout << "Ingrese la cantidad de valores a ingresar";
    cin>> canti;

    for (int i=0 ; i < canti ; i++) {
        cout << "Ingrese un valor" << endl;
        cin >> num;

        if (num>mayor || mayor==0){
         mayor = num;
         posicionMaj=i+1;
        }

        if (num < menor || menor==0){
         menor = num;
         posicionMin=i+1;
        }

    }

    cout << "El mayor numero ingresado es " << mayor << " su posicion es " << posicionMaj << endl;
    cout << "El menor numero ingresado es " << menor << " su posicion es " << posicionMin << endl;

 system("pause");
 return 0;
}