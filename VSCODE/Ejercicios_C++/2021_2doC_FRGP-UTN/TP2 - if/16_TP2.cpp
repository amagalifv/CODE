#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
16- Un año es bisiesto si es múltiplo de 4, exceptuando a los años que son múltiplos de 100
pero que no sean múltiplos de 400. Esto último significa que el año 1900 no es bisiesto, pero
el año 2000 si lo es.
Hacer un programa para que ingresar un año y listar por pantalla si es bisiesto o no lo es.
Ejemplo 1. Si se ingresa el año 2020 se indicará como bisiesto.
Ejemplo 2. Si se ingresa el año 2019 se indicará como no bisiesto.
Ejemplo 3. Si se ingresa el año 1800 o 1900 se indicará como no bisiesto.
Ejemplo 4. Si se ingresa el año 1600 o 2000 se indicará como bisiesto.
*/

int main () {
    int anio;
    int resto4;
    int resto100;
    int resto400;

    cout<<"Ingrese el año"<<endl;
    cin>>anio;

    resto4=anio%4;
    resto400=anio%400;
    resto100=anio%100;

    if (resto100!=0 && resto4==0) {
        cout<<"El año es bisiesto"<<endl;
    } else if (resto100==0 && resto400==0) {
        cout<<"El año es bisiesto"<<endl;
    } else {
        cout<<"El año NO es bisiesto"<<endl;
    }

    system("pause");
    return 0;
}