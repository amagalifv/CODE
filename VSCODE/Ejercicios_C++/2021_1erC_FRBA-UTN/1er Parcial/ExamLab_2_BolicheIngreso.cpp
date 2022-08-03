#include <iostream>
using namespace std;

int edadDesdeFechaNac(int fechaNacimieto, int fechaActual);
int pedirValor (string mensaje);

int main () {
 int fechaNac;
 int fechaActual;
 int edad;
 int capacidadLocal=0;

 fechaActual=pedirValor("Ingrese la fecha actual en formato AAAAMMDD");
 fechaNac=pedirValor("Ingrese la fecha de nacimiento en formato AAAAMMDD");
 capacidadLocal=pedirValor("Ingrese la capacidad del local");

 edad=edadDesdeFechaNac(fechaNac, fechaActual);
 
 while (capacidadLocal>0 && fechaNac !=0){
    if (edad>=18){
            cout << "Ingreso permitido"<<endl;
            capacidadLocal=capacidadLocal-1;
    }else{
        cout<< "Menor de edad, acceso denegado"<< endl;
    }

    fechaNac=pedirValor("Ingrese la fecha de nacimiento en formato AAAAMMDD");
    edad=edadDesdeFechaNac(fechaNac, fechaActual);
 }
       
 cout<< "local lleno, fin"<<endl;

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
