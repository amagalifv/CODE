#include <iostream>
#include <cstdlib>
using namespace std;

/*
11) Hacer un programa para ingresar por teclado una cantidad de cantidad de minutos y
mostrar por pantalla a cuantos días, horas y minutos equivalen.
Ejemplo 1: si se ingresan 1520 minutos el programa mostrará por pantalla que equivalen a 1
día, 1 hora y 20 minutos.
Ejemplo 2: si se ingresan 480 minutos el programa mostrará por pantalla que equivalen a 0
día, 8 horas y 0 minutos.
*/

int main () {
    int cantMin;
    int dias;
    int horas;
    int min;

    cout<<"Ingrese la cantidad de minutos a convertir: "<<endl;
    cin>>cantMin;

    horas=cantMin/60;
    min=cantMin%60;
    dias=horas/24;
    horas=horas-(dias*24);

    cout<<"Dias: "<<dias<<", horas: "<<horas<<" y minutos: "<<min<<endl;

    system("pause");
    return 0;
}