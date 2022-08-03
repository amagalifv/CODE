#include <iostream>
#include <cstdlib>
using namespace std;

/*
10) Hacer un programa para ingresar por teclado una cantidad de horas y mostrar por pantalla
a cuantas días y horas equivalen.
Ejemplo 1: si se ingresan 26 horas el programa mostrará por pantalla que equivalen a 1 día y
2 horas.
Ejemplo 2: si se ingresan 72 horas el programa mostrará por pantalla que equivalen a 3 días y
0 horas.
Ejemplo 3: si se ingresan 20 horas el programa mostrará por pantalla que equivalen a 0 días y
20 horas.
*/

int main () {
    int cantHoras;
    int dias;
    int horas;

    cout<<"Ingrese la cantidad de minutos a convertir: "<<endl;
    cin>>cantHoras;

    dias=cantHoras/24;
    horas=cantHoras-(dias*24);

    cout<<"Días: "<<dias<<", horas: "<<horas<<endl;

    system("pause");
    return 0;
}