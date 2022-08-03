#include <iostream>
#include <cstdlib>
using namespace std;

/*
19- Se define a un número como primo cuando tiene solamente dos divisores: el número 1
y el número en sí mismo. Todo número que tenga otros divisores adicionales al 1 y al
número en sí mismo, son números No Primos.
Ejemplo 1: 2, 7, 11, 13 son números primos, ya que todos tienen solamente dos divisores.
Ejemplo 2: 6 no es primo, pues tiene 4 divisores (1, 2 3 y 6)
Ejemplo 3: 9 no es primo, pues tiene 3 divisores (1, 3 y 9)
Favor de no confundir número primo con número impar. Son dos conceptos
diferentes. El 9 no es primo. El 13 si es primo. Sin embargo, ambos son impares.
Hacer un programa para ingresar un número y luego informar con un cartel aclaratorio si el
mismo es un número primo o es número no primo.
*/

int main () {
    int num;
    int i;
    int contDiv=0;

    cout<<"Ingrese un numero distinto de 0: "<<endl;
    cin>>num;
    i=num;

    while (i!=0) {
        if (num%i==0) {
            contDiv++;
        }
        i--;
    }

    if (contDiv==2) {
        cout<<"Es primo"<<endl;
    } else {
        cout<<"NO es primo"<<endl;
    }

    system("pause");
    return 0;
}