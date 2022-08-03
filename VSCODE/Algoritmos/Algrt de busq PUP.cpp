#include <iostream>
using namespace std;

// PUP (Posicion Unica Predecible)

int main () {
    float ventas[31];

    for (int i = 0; i < 31; i++){
        cout<< "Ingrese la venta del dia"<< i+1<<": ";
        cin>>ventas[i];
    }

    system("pause");
    return 0;
}

/*
int main () {
 float ventas[31];
 int dia;
 float vta;

 cout<<"Ingrese las ventas del mes"<<endl;

 for (int i = 0; i < 31; i++){
     cout<< "Dia: ";
     cin>>dia;
     cout<< "Venta: ";
     cin>>vta;
     ventas[dia-1]=ventas[dia-1]+vta; //Acumulo la venta leida
 }

 system("pause");
 return 0;
}
*/

//*BENEFICIOS*
//Simple
//Eficiente
//Requiere que el conjunto se encuentre ordenado
//Requiere conocer el rango de valores de las claves
//Requiere que el conjunto este completo(sin huecos)
//Equivalencia entre alguna clave del dato y la posicion