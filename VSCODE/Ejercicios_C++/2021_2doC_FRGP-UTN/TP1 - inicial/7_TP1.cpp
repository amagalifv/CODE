#include <iostream>
#include <cstdlib>
using namespace std;

/*
7) Hacer un programa para ingresar por teclado el importe de una venta y el porcentaje de
descuento aplicada a la misma y luego informar por pantalla el importa a pagar.
Ejemplo 1. Si el importe de la venta es $ 1.200 y el descuento es el 15% entonces el total a
pagar será de $ 1.020.
Ejemplo 2. Si el importe de la venta es $ 800 y el descuento es el 0% entonces el total a pagar
será de $ 800.
*/

int main () {
    float impVenta;
    float porcDesc;
    float impTotal;

    cout<<"Ingrese el importe de la venta: "<<endl;
    cin>>impVenta;
    cout<<"Ingrese  el porcentaje de descuento: "<<endl;
    cin>>porcDesc;

    impTotal=impVenta*(porcDesc/100);

    cout<<"El importe a pagar con descuento es: $"<<impTotal<<endl;

    system("pause");
    return 0;
}