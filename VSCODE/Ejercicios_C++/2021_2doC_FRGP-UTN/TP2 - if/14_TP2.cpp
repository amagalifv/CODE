#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
14- Un ciudadano está exento de votar si se cumple alguna de las siguientes situaciones:
 Su edad es mayor a 70 años
 Su edad es entre 18 y 70 años, pero se encuentra a más de 500 km de su ciudad.
Hacer un programa para ingresar la edad y la distancia de su ciudad de un ciudadano e indicar
con un cartel si está o no está exento de votar.
*/

int main () {
    int edad;
    float km;

    cout<<"Edad: "<<endl;
    cin>>edad;
    cout<<"Distancia:"<<endl;
    cin>>km;

    if (edad > 70) {
        cout<<"Esta exento de votar"<<endl;
    } else if (18<edad && edad<70 && km>500) {
        cout<<"Esta exento de votar"<<endl;
    } else{
        cout<<"Debe votar"<<endl;
    }

    system("pause");
    return 0;
}