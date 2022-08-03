#include <iostream>
using namespace std;

int buscarSecuencial(int vec[], int cant, int valor){
    for (int i = 0; i < cant; i++){
        if (vec[i] == valor){
            return i;
        }
    }
    //Si no salio todavia, es que no estaba en el vector
    return -1;
}

//*BENEFICIOS*
//Simple
//Poco Eficiente

int buscarSecuencial2(int vec[], int cant, int valor){
    int i=0;
    int pos=-1;

    while (i<cant && pos == -1){
        if (vec[i] == valor){
            pos = i;
        }
        i++;
    }
    return pos;
}


int main () {
    int posicion=-1;

    posicion=buscarSecuencial(vector, 10, 7);
    if (posicion>=0){
        //lo encontro
    }else{
        //no lo encontro
    }


    system("pause");
    return 0;
}