#include <iostream>
#include <cstdlib>
using namespace std;

/*
17- Hacer un programa para ingresar una lista de números que finaliza cuando se ingresan
dos números consecutivos iguales, y luego informar el máximo. Cuando se ingresa el
número repetido el mismo debe ser descartado.
Ejemplo: 5, 10, 20, 8, 25, 13, 35, -8, -5, 22, 22. Se listará Máximo 35.
En este caso, el segundo número 22 no se analiza, solo sirve para finalizar el ingreso.
Ejemplo: 5, 10, 20, 8, 55, 13, 55, -8, -5, 33, 33. Se listará Máximo 55.
En este caso, el segundo número 33 no se analiza, solo sirve para finalizar el ingreso.
Ejemplo: 5, 10, 20, 8, 55, 13, 55, -8, -5, -13, -13. Se listará Máximo 55.
En este caso, el segundo número -13 no se analiza, solo sirve para finalizar el ingreso.
*/

int main () {
    int num;
    int numAnt;
    bool primerEnt=true;
    int max;

    cout<<"Ingrese un numero: "<<endl;
    cin>>num;

    while (primerEnt==true || num!=numAnt){

        if (primerEnt==true || max<num) {
            max=num;
        }

        primerEnt=false;

        numAnt=num;
        cout<<"Ingrese un numero: "<<endl;
        cin>>num;
    }

    cout<<"Maximo: "<<max<<endl;

    system("pause");
    return 0;
}