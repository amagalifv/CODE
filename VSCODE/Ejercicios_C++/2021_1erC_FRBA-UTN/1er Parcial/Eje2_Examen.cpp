#include <iostream>
using namespace std;

void pedirDatos(string mensaje, string &dato);
void pedirEdad(string mensaje, int &dato);
float promedios(int edades, int cantAlum);


int main () {
 string nombre;
 string apellido;
 int edad;
 string sistemaOp;
 int cantTotAlm=0;
 int contEdades=0;
 int contLinux=0;
 int contLinuxEdad=0;
 int masViejo=0;
 string nombreMasViejo;
 string nombreMasJoven;
 int masJoven=0;
 float promedioEdades=0;
 float promedioLinux=0;

 
 pedirEdad("Ingrese su edad", edad);

 while (edad>0){
    pedirDatos("Ingrese el nombre", nombre);
    pedirDatos("Ingrese el apellido", apellido);
    pedirDatos("Ingrese el sistema operativo que utiliza", sistemaOp);

    cantTotAlm++;
    contEdades=contEdades+edad;

    if (edad>masViejo || masViejo==0){
        masViejo=edad;
        nombreMasViejo=nombre,apellido;
    }

    if (edad<masJoven || masJoven==0){
        masJoven=edad;
        nombreMasJoven=nombre,apellido;
    }

    if (sistemaOp=="linux"){
        contLinux++;
        contLinuxEdad=contLinuxEdad+edad;
    }
    

    pedirEdad("Ingrese su edad", edad); 
 }

 promedioEdades=promedios(contEdades, cantTotAlm);
 promedioLinux=promedios(contLinuxEdad,contLinux);

 cout<<"El promedio de las edades es "<< promedioEdades<<endl;
 cout<<"El promedio de las edades de quienes usan linux es "<< promedioLinux<<endl;
 cout<<"La edade del mas viejo es "<< masViejo<<" y su nombre es "<< nombreMasViejo<<endl;
 cout<<"La edade del mas joven es "<< masJoven<<" y su nombre es "<< nombreMasJoven<<endl;


 system("pause");
 return 0;
}

void pedirDatos(string mensaje, string &dato){
    cout << mensaje <<endl;
    cin >> dato;

    return;
}

void pedirEdad(string mensaje, int &dato){
     cout << mensaje <<endl;
    cin >> dato;

    return;
}

float promedios(int edades, int cantAlum){
 float promedio;

 promedio= edades/cantAlum;

 return promedio;
}