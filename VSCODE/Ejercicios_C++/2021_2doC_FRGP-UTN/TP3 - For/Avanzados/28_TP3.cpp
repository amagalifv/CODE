#include <iostream>
#include <cstdlib>
using namespace std;

/*
28) Dada una lista de 7 números todos distintos entre sí determinar e informar con un cartel
aclaratorio si los números positivos primos que aparezcan en la misma están ordenados de menor
a mayor. Los números positivos primos pueden no ser consecutivos, pero sí estar ordenados.
Ejemplo 1: 4, 5, 7, 12, 13, 19, 20. Se emite un cartel que diga “Ordenados” ya que los números
primos están ordenados: 5, 7, 13, 19.
Ejemplo 2: 4, 10, 3, 5, 11, 7, 14. Se emite un cartel que diga “Desordenados” ya que los números
primos no están ordenados: 3, 5, 11, 7.
*/

int main () {
    int num;
    bool ordenado=true;
    int contDiv=0;
    int primoAnt=0;

    for (int i=0; i<7; i++) {

        cout<<"ingrese un numero"<<endl;
        cin>>num;

        for (int j=num; j>0; j--) {
            if (num%j==0) {
                contDiv++;
            }
        }

        if (contDiv==2 && num<primoAnt) {
            ordenado=false;
        }

        contDiv=0;
        primoAnt=num;
    }

    if (ordenado==true) {
        cout<<"Ordenados"<<endl;
    } else {
        cout<<"Desordenados"<<endl;
    }

    system("pause");
    return 0;
}