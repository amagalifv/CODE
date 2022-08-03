#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
19- Una empresa de electricidad cobra el servicio a sus clientes de acuerdo a la siguiente
escala:
$ 10 por kilovatio por el consumo hasta los primeros 100 kilovatios de consumo.
$ 12 por kilovatio por el consumo excedente de 101 a 200 kilovatios.
$ 15 por kilovatio por el consumo excedente de 201 kilovatios en adelante.
Hacer un programa para que, dado el consumo en kilovatios de un determinado cliente, el
programa calcule e informe el total a pagar por el mismo.
Ejemplo 1: Un consumo de 55 kilovatios, se calculará: $ 10 x 55= $ 550
Ejemplo 2: Un consumo de 125 kilovatios, se calculará: $ 10 x 100 + $ 12 x 25=$ 1300
Ejemplo 3: Un consumo de 250 kilovatios, se calculará: $ 10 x 100 + $ 12 x 100 + $ 15 x 50 = $ 2950
*/

int main () {
    int consumo;
    int aux=0;
    int tot=0;

    cout<<"Ingrese el consumo: "<<endl;
    cin>>consumo;

    aux=consumo;

    if (aux>=200){
        tot=(aux-200)*15;
        aux=aux-(aux-200);
        tot+=(aux-100)*12;
        aux=aux-(aux-100);
        tot+=aux*10;
    } else if (101<=aux &&  aux<200){
        tot+=(aux-100)*12;
        aux=aux-(aux-100);
        tot+=aux*10;
    } else {
        tot+=aux*10;
    }

    cout<<"Monto a abonar: $"<<tot<<endl;

    system("pause");
    return 0;
}