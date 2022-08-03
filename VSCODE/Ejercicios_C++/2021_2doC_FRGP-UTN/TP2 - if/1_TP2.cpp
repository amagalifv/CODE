#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
1) Hacer un programa para ingresar por teclado un número y luego emitir por pantalla un
cartel aclaratorio indicando si el mismo es positivo, negativo o cero.
*/

int main () {
    int num;

    cout<<"Ingrese el numero a evaluar: "<<endl;
    cin>>num;

    if (num>0) {
        cout<<"El numero es positivo"<<endl;
    } else if (num==0){
        cout<<"El numero es 0"<<endl;
    } else {
        cout<<"El numero es negativo"<<endl;
    }

    system("pause");
    return 0;
}