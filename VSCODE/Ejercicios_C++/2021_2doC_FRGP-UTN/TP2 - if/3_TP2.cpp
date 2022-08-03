#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
3) Hacer un programa para ingresar por teclado un número y luego informar por pantalla con
un cartel aclaratorio si el mismo es par o impar
*/

int main () {
    int num;

    cout<<"Ingrese un numero: "<<endl;
    cin>>num;

    if (num%2==0) {
        cout<<"El numero es par"<<endl;
    }else if (num==0) {
        cout<<"El 0 no es par ni impar"<<endl;
    } else {
        cout<<"El numero es impar"<<endl;
    }

    system("pause");
    return 0;
}