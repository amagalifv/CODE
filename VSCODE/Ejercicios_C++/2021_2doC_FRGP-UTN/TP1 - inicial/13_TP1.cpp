#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
13- Hacer un programa para un cajero automático para ingresar un importe a retirar y
convertir el mismo en la cantidad de billetes de $ 1.000, $ 500, $ 200 y $ 100 a entregar.

Ejemplo 1: Si el importe a retirar es $ 2.500 se mostrara por pantalla que se deberán entregar
2 billetes de $ 1.000, 1 billete de $ 500 y 0 billetes de $ 200 y $ 100. SIGUE 
Ejemplo 2: Si el importe a retirar es $ 3.400 se mostrara por pantalla que se deberán entregar
3 billetes de $ 1.000, 2 billetes de $ 200 y 0 billetes de $ 500 y $ 100.
Ejemplo 3: Si el importe a retirar es $ 300 se mostrara por pantalla que se deberán entregar 1
billete de $ 200, 1 billete de $ 100, 0 billetes de $ 1.000 y 0 billetes de $ 500.
Recordatorio. Considerar en todos los casos que el importe a retirar es en todos los casos
múltiplo de $ 100 ya que el cajero no cuenta con billetes de $ 50, $ 20 o $ 10.
*/

int main () {
    int importeRetiro;
    int cant1000;
    int cant500;
    int cant200;
    int cant100;
    int aux=0;

    cout<<"Ingrese el importe a retirar: (debe terminar con 00)"<<endl;
    cin>>importeRetiro;

    cant1000=importeRetiro/1000;
    aux=importeRetiro%1000;
    cant500=aux/500;
    aux=aux%500;
    cant200=aux/200;
    aux=aux%200;
    cant100=aux/100;
    aux=aux%100;

    if (aux==0){
        cout<<"Cantidad billetes de $1000: "<<cant1000<<" de $500: "<<cant500<<" de $200: "<<cant200<<" de $100: "<<cant100<<endl;
    }else{
        cout<<"Monto ingresado no válido"<<endl;
    }

    system("pause");
    return 0;
}