#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
3) Diseñar una función que reciba como parámetros una cadena de caracteres, un valor entero que representa una posición de ella y 1 carácter, e inserte en la cadena el carácter dado en la posición pedida.

Ejemplo:
CADENA FUENTE: “Hola”
CARÁCTER: ’a’
POSICION: 1

CADENA RESULTADO: “Hala”

NOTA: la función no debe hacer nada si el valor de posición es mayor que la cantidad de caracteres de la cadena
*/

void mostrarCadena (char* vchar){
    int i=0;

    while(vchar[i]!='\0'){
        cout<<vchar[i];
        i++;
    }
    cout<<endl;
}

void reemplazarCharEnPos (char* vchar, char ca, int pos){
    int longitud;
    longitud=strlen(vchar);
    cout<<"long: "<<longitud<<endl;

    if (pos<longitud) {
        vchar[pos]=ca;
    }
}

int main () {
    char vChar[5]="Hola";
    char caracterA='a';
    int pos=1;

    mostrarCadena(vChar);
    reemplazarCharEnPos(vChar,caracterA,pos);
    mostrarCadena(vChar);

    system("pause");
    return 0;
}