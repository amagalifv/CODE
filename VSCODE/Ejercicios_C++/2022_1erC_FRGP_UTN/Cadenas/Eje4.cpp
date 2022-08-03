#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
4) Diseñar una rutina que liste por pantalla en forma de columna las letras de una palabra dada.
*/

void mostrarCadena (char* vchar){
    int i=0;

    while(vchar[i]!='\0'){
        cout<<vchar[i]<<endl;
        i++;
    }
    cout<<endl;
}

int main () {
    char vChar[5]="Hola";

    mostrarCadena(vChar);

    system("pause");
    return 0;
}