#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
17- Hacer un programa para ingresar por teclado las cuatro notas de los exámenes obtenidas
por un alumno y luego emitir un solo cartel de acuerdo a las siguientes condiciones:
- “Promociona”, si obtuvo en los cuatro exámenes nota 7 o más.
- “Rinde examen final”, si obtuvo nota 4 o más en por lo menos tres exámenes.
- “Recupera Parciales”, si obtuvo nota 4 o más en por lo menos uno de los exámenes.
- “Recursa la materia”, si no aprobó ningún examen parcial.
*/

int main () {
    int nota1;
    int nota2;
    int nota3;
    int nota4;

    cout<<"Ingrese 1er nota: "<<endl;
    cin>>nota1;
    cout<<"Ingrese 2da nota: "<<endl;
    cin>>nota2;
    cout<<"Ingrese 3er nota: "<<endl;
    cin>>nota3;
    cout<<"Ingrese 4ta nota: "<<endl;
    cin>>nota4;

    if (nota1>=7 && nota2>=7 && nota3>=7 && nota4>=7) {
        cout<<"Promociona"<<endl;
    } else if ( nota1>=4 && nota2>=4 && nota3>=4 || nota4>=4 && nota2>=4 && nota3>=4 || nota4>=4 && nota1>=4 && nota3>=4 || nota1>=4 && nota2>=4 && nota4>=4) {
        cout<<"Rinde examen final"<<endl;
    } else if ( nota1>=4 || nota2>=4 || nota3>=4 || nota4>=4) {
        cout<<"Recupera Parciales"<<endl;
    } else {
        cout<<"Recupera la materia"<<endl;
    }

    system("pause");
    return 0;
}