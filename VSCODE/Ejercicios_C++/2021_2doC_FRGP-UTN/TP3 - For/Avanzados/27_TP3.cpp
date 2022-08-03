#include <iostream>
#include <cstdlib>
using namespace std;

/*
27- Se dispone de una lista de 10 grupos de números y cada uno de los grupos estará
compuesto por 5 números. Se pide determinar e informar:
a- Para cada uno de los 10 grupos la cantidad de números positivos, negativos y
ceros que lo componen. Se informan 3 resultados para cada uno de los 10 grupos.
b- Para cada uno de los 10 grupos el último número primo y en qué orden apareció
en ese grupo, si en un grupo no hubiera números primos informarlo con un cartel
aclaratorio. Se informan 2 resultados para cada uno de los 10 grupos.
c- Informar cuantos números impares hay en total entre los 10 grupos. Se informa un
resultado al final de todo, es decir no debe informar resultados grupo por grupo.
*/

int main () {
    int num;
    int contPosi=0;
    int contNeg=0;
    int contCero=0;

    for (int j=0; j<10; j++) {

        for (int i=0; i<5; i++) {
            cout<<"ingrese un numero"<<endl;
            cin>>num;

            if (num>0) {
                contPosi++;
            }
            if (num<0) {
                contNeg++;
            }
            if (num==0) {
                contCero++;
            }
        }
        cout<<"Grupo "<<j+1<<": "<<endl;
        cout<<"Cantidad de ceros: "<<contCero<<endl;
        cout<<"Cantidad de positivos: "<<contPosi<<endl;
        cout<<"Cantidad de negativos:"<<contCero<<endl;

        contPosi=0;
        contNeg=0;
        contCero=0;
    }

    system("pause");
    return 0;
}