#include <iostream>
using namespace std;

/*
Hacer un programa que solicite por teclado que se ingresen dos números y luego
guardarlos en dos variables distintas. A continuación se deben intercambiar mutuamente los
valores en ambas variables y mostrarlos por pantalla.
Ejemplo: Suponiendo que se ingresan 3 y 8 como valores y que la variables usadas son A y B,
entonces A=3 y B=8, pero luego debe quedar A=8 y B=3.
*/

int main () {
    int valor1;
    int valor2;
    int aux=0;

    cout<<" Ingrese un número: "<<endl;
    cin>>valor1;

    cout<<" Ingrese otro número: "<<endl;
    cin>>valor2;

    aux=valor1;
    valor1=valor2;
    valor2=aux;

    cout<<"Ahora el primer valor es: "<<valor1<<endl;
    cout<<"Ahora el segundo valor es: "<<valor2<<endl;
 
    system("pause");
    return 0;
}