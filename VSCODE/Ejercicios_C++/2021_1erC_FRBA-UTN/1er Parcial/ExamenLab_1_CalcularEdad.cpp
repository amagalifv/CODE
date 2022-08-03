#include <iostream>
using namespace std;

int edadDesdeFechaNac(int fechaNacimieto, int fechaActual);
int pedirValor (string mensaje);

int main () {
 int fechaNac;
 int fechaActual;
 int edad;

 fechaNac=pedirValor("Ingrese la fecha de nacimiento en formato AAAAMMDD");
 fechaActual=pedirValor("Ingrese la fecha actual en formato AAAAMMDD");

 edad=edadDesdeFechaNac(fechaNac, fechaActual);

 cout<< "La edad de la persona es "<< edad<<endl;

 system("pause");
 return 0;
}

int pedirValor (string mensaje){
    int valor;
    cout<<mensaje<<endl;
    cin>>valor;

    return valor;
}

int edadDesdeFechaNac(int fechaNacimieto, int fechaActual){
 return (fechaActual-fechaNacimieto)/10000;
}

