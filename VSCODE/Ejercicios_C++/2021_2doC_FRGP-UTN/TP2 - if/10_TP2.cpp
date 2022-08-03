#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
10) Hacer un programa para ingresar cinco números. Se pide luego resolver como tres casos
diferentes:
a) Listar el máximo
b) Listar el mínimo
c) Listar el máximo y el mínimo.
*/

int main () {
    int num1;
    int num2;
    int num3;
    int num4;
    int num5;
    int opcion;

    cout<<"Ingrese que opcion quiere listar 1-maximo 2-minimo 3-ambos"<<endl;
    cin>>opcion;
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

    switch (opcion) {

        case 1:
                //---------------------MAYOR----------------------------
            if (num1>num2 && num1>num3 && num1>num4 && num1>num5) {
            cout<<num1<<" es el mayor "<<endl;
            } else if (num2>num1 && num2>num3 && num2>num4 && num2>num5) {
            cout<<num2<<" es el mayor "<<endl;
            } else if (num3>num1 && num3>num2 && num3>num4 && num3>num5) {
            cout<<num3<<" es el mayor "<<endl;
            } else if (num4>num1 && num4>num2 && num4>num3 && num4>num5) {
            cout<<num4<<" es el mayor "<<endl;
            } else {
            cout<<num5<<" es el mayor "<<endl;
            }
            break;
        case 2:
            //---------------------MENOR----------------------------
            if (num1<num2 && num1<num3 && num1<num4 && num1<num5) {
            cout<<num1<<" es el menor "<<endl;
            } else if (num2<num1 && num2<num3 && num2<num4 && num2<num5) {
            cout<<num2<<" es el menor "<<endl;
            } else if (num3<num1 && num3<num2 && num3<num4 && num3<num5) {
            cout<<num3<<" es el menor "<<endl;
            } else if (num4<num1 && num4<num2 && num4<num3 && num4<num5) {
            cout<<num4<<" es el menor "<<endl;
            } else {
            cout<<num5<<" es el menor "<<endl;
            }
            break;
        case 3:
            //---------------------MAYOR----------------------------
            if (num1>num2 && num1>num3 && num1>num4 && num1>num5) {
                cout<<num1<<" es el mayor "<<endl;
            } else if (num2>num1 && num2>num3 && num2>num4 && num2>num5) {
                cout<<num2<<" es el mayor "<<endl;
            } else if (num3>num1 && num3>num2 && num3>num4 && num3>num5) {
                cout<<num3<<" es el mayor "<<endl;
            } else if (num4>num1 && num4>num2 && num4>num3 && num4>num5) {
                cout<<num4<<" es el mayor "<<endl;
            } else {
                cout<<num5<<" es el mayor "<<endl;
            }
            break;
            //---------------------MENOR----------------------------
            if (num1<num2 && num1<num3 && num1<num4 && num1<num5) {
            cout<<num1<<" es el menor "<<endl;
            } else if (num2<num1 && num2<num3 && num2<num4 && num2<num5) {
            cout<<num2<<" es el menor "<<endl;
            } else if (num3<num1 && num3<num2 && num3<num4 && num3<num5) {
            cout<<num3<<" es el menor "<<endl;
            } else if (num4<num1 && num4<num2 && num4<num3 && num4<num5) {
            cout<<num4<<" es el menor "<<endl;
            } else {
            cout<<num5<<" es el menor "<<endl;
            }
        default:
            break;
    }

    system("pause");
    return 0;
}