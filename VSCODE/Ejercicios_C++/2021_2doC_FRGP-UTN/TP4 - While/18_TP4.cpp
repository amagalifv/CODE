#include <iostream>
#include <cstdlib>
using namespace std;

/*
18- Hacer un programa para ingresar una lista de números que finaliza cuando se ingresan
dos números positivos consecutivos, y luego informar el máximo. Cuando se ingresa el
número positivo repetido el mismo debe ser descartado.
Ejemplo: 5, -10, 20, -8, 0, 13, -35, -8, 15, 10. Se listará Máximo 20.
En este caso, el segundo número positivo consecutivo, el 10, no se analiza, solo sirve para
finalizar el ingreso.
Ejemplo: 5, -10, 20, -20, 0, 55, -13, 45, -8, -5, 12, 120. Se listará Máximo 55.
En este caso, el segundo número positivo consecutivo, el 120, no se analiza, solo sirve para
finalizar el ingreso.
*/

int main () {
    int num;
    int numAnt;
    bool primerEnt=true;
    int max;

    cout<<"Ingrese un numero: "<<endl;
    cin>>num;

    while (num<=0 || numAnt<=0 || primerEnt==true){

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