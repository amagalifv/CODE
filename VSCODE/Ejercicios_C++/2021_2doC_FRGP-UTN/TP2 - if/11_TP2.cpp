#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
11- Hacer un programa para ingresar cinco números y listar cuántos de esos cinco números
son positivos
*/

int main () {
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int cont=0;

    cout<<"Ingrese un numero"<<endl;
    cin>>num1;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num2;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num3;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num4;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num5;

    if (num1 > 0) {
        cont++;
    }
    if (num2 > 0) {
        cont++;
    }
    if (num3 > 0) {
        cont++;
    }
    if (num4 > 0) {
        cont++;
    }
    if (num5 > 0) {
        cont++;
    }

    cout<<"Positivos: "<<cont<<endl;

    system("pause");
    return 0;
}