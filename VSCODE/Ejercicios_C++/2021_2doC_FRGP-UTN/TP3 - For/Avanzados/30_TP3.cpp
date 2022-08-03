#include <iostream>
#include <cstdlib>
using namespace std;

/*
30- Hacer un programa para ingresar 10 números, luego informar los 2 mayores
valores ingresados, aclarando cual es el máximo y cuál es el segundo máximo
descartando los números repetidos.
Ejemplo 1: 10, 8,12, 78 ,55, 20, 12, 40, 31, 28 el resultado será 78 y 55.
Ejemplo 2: -20, - 25, -3, -8, -50, -45, -20, -22, -15, -11 el resultado será -3 y -8.
Ejemplo 3: 20, 20, 12, 9, 14, 14, 8, 8, 10, 3 el resultado será 20 y 14.
En el ejemplo 3 el valor 20 aparece dos veces, pero solo se considera una vez.
*/

int main () {
    int num;
    int max;
    int max2;
    bool primerE=true;

    for (int i=0; i<10; i++) {
        cout<<"Ingrese un numero: "<<endl;
        cin>>num;

        if (i==0) {
            max=num;
        }

        if (i!=0 && primerE==true && num!=max) {
            primerE=false;
            max2=num;
        }

        if (i!=0 && primerE==false) {

            if (num>max) {
                max2=max;
                max=num;
            }
            if (max2<num && num<max) {
                max2=num;
            }
        }
    }

    cout<<"El maximo: "<<max<<" el que le sigue es: "<<max2<<endl;

    system("pause");
    return 0;
}