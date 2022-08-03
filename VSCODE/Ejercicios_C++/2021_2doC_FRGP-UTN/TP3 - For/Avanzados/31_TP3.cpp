#include <iostream>
#include <cstdlib>
using namespace std;

/*
31) Hacer un programa para ingresar una lista de 20 números. Se pide luego determinar e
informar:
a) La cantidad de ternas de valores positivos consecutivos.
b) La cantidad de ternas de valores negativos consecutivos y ordenados en forma creciente.
Ejemplo si la lista de 12 números fuera: 10, 5, 4, 3, -8, -3, -1, 0, 3, 8, -5, 8 entonces el
programa detectará una terna de positivos consecutivos (10, 5, 4) y una terna de negativos
consecutivos ordenados (-8, -3, -1).
Nota: si el número ingresado es cero, no se lo considera ni negativo ni positivo.
*/

int main () {
    int num;
    int contTernasPos=0;
    int auxPos=0;
    int contTernasNeg=0;
    int auxNeg=0;
    bool primerEntPos=true;
    bool primerEntNeg=true;
    int numAnt=0;

    for (int i=0; i<12; i++) {
        cout<<"Ingrese un numero: "<<endl;
        cin>>num;

        //Para Positivos
        if (num>0 && numAnt>0) {
            auxPos++;
        }

        if (num>0 && primerEntPos==true){
            auxPos++;
            primerEntPos=false;
            numAnt=num;
        }

        if (auxPos==3) {
            contTernasPos++;
            auxPos=0;
        }

        //Para negativos
        if (num<0 && numAnt<0) {
            auxNeg++;
        }

        if (num<0 && primerEntNeg==true){
            auxNeg++;
            primerEntNeg=false;
            numAnt=num;
        }

        if (auxNeg==3) {
            contTernasNeg++;
            auxNeg=0;
        }

        numAnt=num;
    }

    cout<<"Cantidad ternas positivas: "<<contTernasPos<<endl;
    cout<<"Cantidad ternas negativas: "<<contTernasNeg<<endl;

    system("pause");
    return 0;
}