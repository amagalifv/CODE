#include <iostream>
#include <cstdlib>
using namespace std;

/*
24- Hacer un programa para ingresar los consumos de electricidad de los clientes de una
empresa. Cada registro contiene los siguientes datos:
- Número de cliente
- Localidad del cliente (1, 2 o 3)
- Kilovatios consumidos
El lote finaliza con un registro con número de cliente igual a cero.
El precio es escalonado según la siguiente escala:
$ 10 por kilovatio por los primeros 100 kilovatios de consumo.
$ 12 por kilovatio por el consumo de 101 a 200 kilovatios.
$ 15 por kilovatio por el consumo de 201 kilovatios en adelante.
Además, hay un cargo fijo de $ 100.
Ejemplo 1: Consumo de 55 kilovatios, se calculará: $ 10 x 55 + $ 100= $ 650
Ejemplo 2: Consumo de 125 kilovatios, se calculará: $ 10 x 100 + $ 12 x 25 + $ 100=$ 1400
Ejemplo 3: Consumo de 250 kilovatios, se calculará: $10 x 100+ $12 x 100 + $15 x 50 + $100= $ 3050
Ejemplo 3: Consumo de 0 kilovatios, se calculará: $ 10 x 0 + $ 100= $ 100
Se pide determinar e informar:
a) El número de cliente que tuvo la mayor cantidad de Kilovatios consumidos para cada
una de las 3 localidades. Se listan 3 resultados, uno para cada una de las 3 localidades
b) El total de recaudación para cada una de las 3 localidades. Se listan 3 resultados, uno
para cada una de las 3 localidades
c) El número de cliente que tuvo la menor cantidad de Kilovatios consumidos excluyendo a
los clientes que tuvieron Kilovatios consumidos con valor cero. Se lista 1 resultado.
*/

int main () {
    int numClien;
    int localidad;
    int kwatt;
    int aux=0;
    int tot=0;
    bool primeraEnt=true;
    bool primeraEnt1=true;
    bool primeraEnt2=true;
    bool primeraEnt3=true;
    int max1;
    int max2;
    int max3;
    int min;
    int minNumClien;
    int maxNumClien1;
    int maxNumClien2;
    int maxNumClien3;
    int totRecau1=0;
    int totRecau2=0;
    int totRecau3=0;

    cout<<"Ingrese un numero de cliente (0 para terminar): "<<endl;
    cin>>numClien;

    while (numClien!=0) {
        cout<<"Localidad: "<<endl;
        cin>>localidad;
        cout<<"Consumo de kilovatio: "<<endl;
        cin>>kwatt;
        aux=kwatt;

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
        tot+=100;

        if (kwatt<min || primeraEnt==true) {
            primeraEnt=false;
            min=kwatt;
            minNumClien=numClien;
        }

        switch (localidad) {
            case 1:
                if (primeraEnt1==true||kwatt>max1){
                    primeraEnt1=false;
                    max1=kwatt;
                    maxNumClien1=numClien;
                }
                totRecau1+=tot;
                break;
            case 2:
                if (primeraEnt2==true||kwatt>max1){
                    primeraEnt2=false;
                    max1=kwatt;
                    maxNumClien2=numClien;
                }
                totRecau2+=tot;
                break;
            case 3:
                if (primeraEnt3==true||kwatt>max1){
                    primeraEnt3=false;
                    max1=kwatt;
                    maxNumClien3=numClien;
                }
                totRecau3+=tot;
                break;

            default:
                break;
        }

        tot=0;
        cout<<"Ingrese un numero de cliente (0 para terminar): "<<endl;
        cin>>numClien;
    }

    cout<<"Nro Cliente mayor consumo localidad 1: "<<maxNumClien1<<endl;
    cout<<"Nro Cliente mayor consumo localidad 2: "<<maxNumClien2<<endl;
    cout<<"Nro Cliente mayor consumo localidad 3: "<<maxNumClien3<<endl;
    cout<<endl;
    cout<<"Recaudacion localidad 1: "<<totRecau1<<endl;
    cout<<"Recaudacion localidad 2: "<<totRecau2<<endl;
    cout<<"Recaudacion localidad 3: "<<totRecau3<<endl;
    cout<<endl;
    cout<<"Nro Cliente menor consumo: "<<minNumClien<<endl;

    system("pause");
    return 0;
}