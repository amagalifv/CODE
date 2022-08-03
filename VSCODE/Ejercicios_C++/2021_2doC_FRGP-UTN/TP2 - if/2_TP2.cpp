#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
2) Hacer un programa para ingresar por teclado dos números y luego informar por pantalla
con un cartel aclaratorio si el primer número es múltiplo del segundo.
*/

int main () {
    int num1;
    int num2;
    float resultado;

    cout<<"Ingrese un numero: "<<endl;
    cin>>num1;
    cout<<"Ingrese el otro numero: "<<endl;
    cin>>num2;

    resultado=(float)num2/(float)num1;

    if (resultado==0){
        cout<<num1<<" es multiplo de "<<num2<<endl;
    }else{
        cout<<"No son multiplos"<<endl;
    }

    system("pause");
    return 0;
}