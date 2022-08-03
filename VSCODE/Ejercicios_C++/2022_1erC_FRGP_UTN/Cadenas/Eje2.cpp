#include <iostream>
#include <cstdlib>
using namespace std;

/*
2) Hacer una función que reciba como parámetros una cadena de caracteres y dos caracteres, y reemplace en la cadena todas las ocurrencias del primer carácter dado por el segundo.
Ejemplo:
CADENA FUENTE: “La mar estaba serena”
CARÁCTER 1: ‘a’
CARÁCTER 2: ‘i’
CADENA RESULTADO: “Li mir estibi sereni”
*/
void mostrarCadena (char* vchar){
    int i=0;

    while(vchar[i]!='\0'){
        cout<<vchar[i];
        i++;
    }
    cout<<endl;
}

void reemplazoChar (char* vchar, char ca, char ci){
    int i=0;

    while (vchar[i]!='\0') {
        if (vchar[i]==ca) {
            vchar[i]=ci;
        }
        i++;
    }
}

int main () {
    char vChar[21]="La mar estaba serena";
    char caracterA='a';
    char caracterI='i';

    mostrarCadena(vChar);
    reemplazoChar(vChar,caracterA,caracterI);
    mostrarCadena(vChar);

    system("pause");
    return 0;
}