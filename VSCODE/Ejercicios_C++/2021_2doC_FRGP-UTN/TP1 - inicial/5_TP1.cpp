#include <iostream>
using namespace std;

/*
5) Un comercio vende tres marcas de alfajores distintas A, B y C.
Hacer un programa para ingresar por teclado la cantidad de alfajores vendidos de cada una de
las tres marcas y luego se informe el porcentaje de ventas para cada una de ellas.
Ejemplo. Si se ingresa 100, 25 y 75 como cantidades vendidas entonces el programa calculará
e informará A: 50%, B: 12,50% y C: 37,50%.
*/

int main () {

    int alfajorA;
    int alfajorB;
    int alfajorC;
    int cantTot=0;
    float porcA;
    float porcB;
    float porcC;

    cout<<"Ingrese la cantidad vendida de alfajores A"<<endl;
    cin>>alfajorA;
    cout<<"Ingrese la cantidad vendida de alfajores B"<<endl;
    cin>>alfajorB;
    cout<<"Ingrese la cantidad vendida de alfajores C"<<endl;
    cin>>alfajorC;

    cantTot=alfajorA+alfajorB+alfajorC;
    porcA=((float)alfajorA/(float)cantTot)*100;
    porcA=((float)alfajorB/(float)cantTot)*100;
    porcA=((float)alfajorC/(float)cantTot)*100;

    cout>>"El porcentaje de ventas del alfajor A es: ">>porcA>>"%">>endl;
    cout>>"El porcentaje de ventas del alfajor B es: ">>porcB>>"%">>endl;
    cout>>"El porcentaje de ventas del alfajor C es: ">>porcC>>"%">>endl;

    system("pause");
    return 0;
}