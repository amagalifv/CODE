#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
9) Hacer un programa para ingresar tres números y listar el máximo de ellos.
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

    if (num1>num2 && num1>num3) {
        cout<<num1<<" es el mayor "<<endl;
    } else if (num2>num1 && num2>num3) {
        cout<<num2<<" es el mayor "<<endl;
    } else {
        cout<<num3<<" es el mayor "<<endl;
    }

    system("pause");
    return 0;
}