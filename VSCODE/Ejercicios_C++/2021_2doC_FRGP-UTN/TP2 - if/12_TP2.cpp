#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
12) Hacer un programa para leer tres números diferentes y determinar e informar el número
del medio. Ejemplo: si se ingresan 6, 10, 8, se emitirá 8.
*/

int main () {
    int num1;
    int num2;
    int num3;
    int medio;

    cout<<"Ingrese un numero"<<endl;
    cin>>num1;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num2;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num3;

    if (num2<num1 && num1<num3 || num3<num1 && num1<num2) {
        medio=num1;
    } else if (num1<num2 && num2<num3 || num3<num2 && num2<num1) {
        medio=num2;
    } else if (num1<num3 && num3<num2 || num2<num3 && num3<num1) {
        medio=num3;
    }

    cout<<"Numero del medio: "<<medio<<endl;

    system("pause");
    return 0;
}