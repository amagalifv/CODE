#include <iostream>
using namespace std;

typedef struct {
 string nombre;
 int fechaNac;
} REGISTRO_REG;

int edadDesdeFechaNac(int fechaNacimieto, int fechaActual){
 return (fechaActual-fechaNacimieto)/10000;
}

void masGrande(int edades, int &edadMasGrande, string &nombreMasGrande, REGISTRO_REG registros){
 
 if (edades>edadMasGrande || edadMasGrande==-1) {
  edadMasGrande=edades;
  nombreMasGrande=registros.nombre;
 }

 return;
}

int main () {
 REGISTRO_REG registros;
 int fechaAct;
 int edad=0;
 int edadMasGrande=-1;
 string nombreMasGrande;

 cout<< "Ingrese el apellido, nombre "<<endl;
 cin>> registros.nombre;
 cout<<endl;
 cout<<"Ingrese la fecha actual"<<endl;
 cin>>fechaAct;

 while (registros.nombre != "FIN"){
     cout<< "Ingrese la respeciva fecha de nacimieto "<<endl;
     cin>> registros.fechaNac;
     cout<<endl;

     edad=edadDesdeFechaNac(registros.fechaNac, fechaAct);
     masGrande(edad, edadMasGrande, nombreMasGrande, registros);
     
     cout<< "Ingrese el apellido, nombre "<<endl;
     cin>> registros.nombre;
     cout<<endl;
 }

 cout<<"La persona mas grande es "<< nombreMasGrande << " y su edad es "<< edadMasGrande<<endl;
 
 system("pause");
 return 0;
}