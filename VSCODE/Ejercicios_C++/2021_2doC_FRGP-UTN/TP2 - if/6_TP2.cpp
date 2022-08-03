#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
6) Hacer un programa para ingresar por teclado tres números y luego determinar e informar
con una leyenda aclaratoria si los tres son iguales entre sí, caso contrario no emitir nada.
Ayuda: Si A es igual a B y B es igual a C, entonces A y C son iguales.
*/

int main () {
    int num1;
    int num2;
    int num3;

    cout<<"Ingrese un numero"<<endl;
    cin>>num1;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num2;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num3;

    if (num1==num2 && num1==num3 && num2==num3) {
        cout<<"Los numeros son iguales"<<endl;
    }

    system("pause");
    return 0;
}