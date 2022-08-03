#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
Hacer una función que devuelva la cantidad de caracteres de una cadena que recibe como parámetro
*/

void mostrarCadena(char *v){
    int i=0;
    while(v[i]!='\0'){
        cout<<v[i];
        i++;
    }

}

int contarCaracteres(char *v){
    int cant=0;

    while(v[cant]!='\0'){
        cant++;
    }

    return cant;
}

int main () {
    char vCh [15], palabra[15];
    int cantidad;

    cin.getline(vCh,15);
    cin.getline(palabra,15);

    //cout<<cadena;
    //mostrarCadena(vCh);
    cout<<"\n\n";

    //cantidad=contarCaracteres(vCh);
    cout<<strlen(vCh)<<"\n\n"; // cuenta cant de caracteres

    strcpy(palabra, vCh);//funcion de lib cString para pasar una cadena de caracteres a otra

    int valorComp=strcmp(palabra, vCh);//funcion de lib cString para comparar si son iguales da 0
    // si palabra viene antes por orden alfabético
    // si palabra viene después por orden alfabético
    // (usa los valores ASCII por lo tanto es caseSensitive)


    system("pause");
    return 0;
}