#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
18- Hacer un programa para ingresar por teclado cuatro números. Si los valores que se
ingresaran están ordenados en forma creciente, emitir el mensaje “Conjunto Ordenado”, caso
contrario emitir el mensaje: “Conjunto Desordenado”.
Ejemplo 1: si los números que se ingresan son 8,10, 12 y 14, entonces están ordenados.
Ejemplo 2: si los números que se ingresan son 8,12, 12 y 14, entonces están ordenados.
Ejemplo 3: si los números que se ingresan son 10, 8,12 y 14, entonces están desordenados.
*/

int main () {
    int num1;
    int num2;
    int num3;
    int num4;

    cout<<"Ingrese un numero"<<endl;
    cin>>num1;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num2;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num3;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num4;

    if (num1<=num2 && num2<=num3 && num1<=num3 && num3<=num4 && num1<=num4 && num2<=num4) {
        cout<<"Está ordenado"<<endl;
    } else {
        cout<<"NO está ordenado"<<endl;
    }

    system("pause");
    return 0;
}