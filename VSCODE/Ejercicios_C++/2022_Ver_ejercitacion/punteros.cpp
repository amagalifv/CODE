#include <iostream>
#include <cstdlib>
using namespace std;

/*
PASAJE DE PARAMETROS:
-POR VALOR
-POR DIRECION
-POR REFERENCIA
*/

void intercambiarPorValor(int c, int d){
    int aux;
    aux=c;
    c=d;
    d=aux;

    cout<<"C: "<<c<<endl;
    cout<<"D: "<<d<<"\n\n";
}

void intercambiarReferencia(int &c, int &d){
    int aux;
    aux=c;
    c=d;
    d=aux;

    cout<<"C: "<<c<<endl;
    cout<<"D: "<<d<<"\n\n";
}

void verPunteros (){
    system("clr");

    int var=1000;
    int *p;
    p=&var; // p está apuntando a var

    /*
        & --> operador de direccion
        * --> operador de indireccion
    */

   cout<<"Valor de var:         "<<var<<endl;
   cout<<"Direcion de var:      "<<&var<<endl;
   cout<<"Valor de p:           "<<p<<endl;
   cout<<"Indireccion de var:   "<<*p<<endl;
   cout<<"Valor de var:         "<<var<<endl;
}

void intercambiarConPunteros(int *c, int *d){
    int aux;
    aux = *c;
    *c=*d;
    *d=aux;

    cout<<"C: "<< *c <<endl;
    cout<<"D: "<< *d <<"\n\n";
}




int main () {

    int a=500, b=1000;
    int aux;

    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<"\n\n";

    intercambiarPorValor(a,b);
    //intercambiarReferencia(a,b);

    cout<<"A: "<<a<<endl;
    cout<<"B: "<<b<<"\n\n";



    system("pause");
    return 0;
}