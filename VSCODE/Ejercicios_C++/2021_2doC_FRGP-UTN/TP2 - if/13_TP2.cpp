#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
13- Hacer un programa para ingresar tres números distintos y listarlos ordenados de menor a
mayor. Ejemplo: si se ingresa 4,-3,7, se debe mostrar -3, 4,7.
*/

int main () {
    int num1;
    int num2;
    int num3;
    int primero;
    int segundo;
    int tercero;

    cout<<"Ingrese un numero"<<endl;
    cin>>num1;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num2;
    cout<<"Ingrese otro numero"<<endl;
    cin>>num3;

    if (num1<num2 && num2<num3) {
        primero=num1;
        segundo=num2;
        tercero=num3;
    } else if (num1<num3 && num3<num2) {
        primero=num1;
        segundo=num3;
        tercero=num2;
    } else if (num2<num1 && num1<num3) {
        primero=num2;
        segundo=num1;
        tercero=num3;
    } else if (num2<num3 && num3<num1) {
        primero=num2;
        segundo=num3;
        tercero=num1;
    } else if (num3<num1 && num1<num2) {
        primero=num3;
        segundo=num1;
        tercero=num2;
    } else if (num3<num2 && num2<num1) {
        primero=num3;
        segundo=num2;
        tercero=num1;
    }

    cout<<"- "<<primero<<endl;
    cout<<"- "<<segundo<<endl;
    cout<<"- "<<tercero<<endl;

    system("pause");
    return 0;
}