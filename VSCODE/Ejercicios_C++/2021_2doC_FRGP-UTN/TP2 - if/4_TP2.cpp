#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
4) Hacer un programa para ingresar por teclado dos números y luego informar por pantalla la
diferencia absoluta entre ambos.
Ejemplo 1: Si se ingresan 3 y 8, se emite 5. Si se ingresan 8 y 3, se emite 5.
Ejemplo 2: Si se ingresan -3 y 9, se emite 12. Si se ingresan -12 y -1, se emite 11.
*/

int main () {
    int num1;
    int num2;
    int modulo;

    cout<<"Ingrese un numero"<<endl;
    cin>>num1;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num2;

    modulo=num1-num2;

    if (modulo>=0) {
        cout<<"El modulo es: "<<modulo<<endl;
    } else {
        modulo=-modulo;
        cout<<"El modulo es: "<<modulo<<endl;
    }

    system("pause");
    return 0;
}