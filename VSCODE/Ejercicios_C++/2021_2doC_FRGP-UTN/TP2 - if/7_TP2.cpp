#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
7) Hacer un programa para ingresar por teclado tres números e informar con una leyenda
aclaratoria si los tres son todos distintos entre sí, caso contrario no emitir nada.
Ayuda: Si A es distinto de B y B es distinto de C, es no sígnica que A y C sean distintos.
Ejemplo: A=8, B=6 y C=8.
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

    if (num1!=num2 && num1!=num3 && num2!=num3) {
        cout<<"Los numeros son todos distintos"<<endl;
    }

    system("pause");
    return 0;
}