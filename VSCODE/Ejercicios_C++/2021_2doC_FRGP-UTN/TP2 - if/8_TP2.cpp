#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
8) Basado en los 2 ejercicios anteriores, hacer un programa para ingresar por teclado la
longitud de los tres lados de un triángulo y luego listar que tipo de triángulo es:
- Equilátero: si los tres lados son iguales
- Isósceles: si dos de los tres lados son iguales
- Escaleno: si los tres lados son distintos entre sí
*/

int main () {
    int lado1;
    int lado2;
    int lado3;

    cout<<"Ingrese un numero"<<endl;
    cin>>lado1;
    cout<<"Ingrese otro numero"<<endl;
    cin>>lado2;
    cout<<"Ingrese otro numero"<<endl;
    cin>>lado3;

    if (lado1==lado2 && lado2==lado3 && lado1==lado3) {
        cout<<"Es equilatero"<<endl;
    } else if (lado1!=lado2 && lado2!=lado3 && lado3!=lado1) {
        cout<<"Es escaleno"<<endl;
    } else {
        cout<<"Es isoceles"<<endl;
    }

    system("pause");
    return 0;
}