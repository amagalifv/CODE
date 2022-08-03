#include <iostream>
using namespace std;

/*
Una concesionaria de autos paga a los vendedores un sueldo fijo de $ 15.000 más $ 2.000
de premio por cada auto vendido. Hacer un programa que permita ingresar por teclado la
cantidad de autos vendidos por un vendedor y luego informar por pantalla el sueldo total a
pagar.
Ejemplo. Si la cantidad de autos vendidos fuera 4 entonces el sueldo total a pagar es de
$ 23.000.
*/

int main () {

    int premPorAuVen=2000;
    int cantAuVen;
    int sueldoBasico=15000;
    float sueldo=0;

    cout <<"Ingrese la cantidad de autos vendidos: "<< endl;
    cin>> cantAuVen;

    sueldo=sueldoBasico + (cantAuVen*premPorAuVen);

    cout<<"El sueldo para los datos ingresados es: "<<sueldo<< endl;

    system("pause");
    return 0;
}