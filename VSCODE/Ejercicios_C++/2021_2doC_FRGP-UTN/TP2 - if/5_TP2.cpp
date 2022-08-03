#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
5) Un negocio de perfumería efectúa descuentos según el importe de la venta.
- Si el importe es menor a $100 aplicar un descuento del 5%
- Si el importe es entre $100 y hasta $500 aplicar un descuento del 10%
- Si el importe es mayor a $500 aplicar un descuento del 15%
Hacer un programa donde se ingresa el importe original sin descuento y que se informe por
pantalla el importe con el descuento ya aplicado.
*/

int main () {
    float importe;
    float aPagar;

    cout<<"Ingrese el importe: "<<endl;
    cin>>importe;

    if (importe>500) {
        aPagar=importe*0.85;
        cout<<"El total a pagar es $"<<aPagar<<endl;
    } else if (importe<=500 && importe>100) {
        aPagar=importe*0.9;
        cout<<"El total a pagar es $"<<aPagar<<endl;
    } else {
        aPagar=importe*0.95;
        cout<<"El total a pagar es $"<<aPagar<<endl;
    }


    system("pause");
    return 0;
}