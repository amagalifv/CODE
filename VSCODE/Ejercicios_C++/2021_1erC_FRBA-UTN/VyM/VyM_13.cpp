#include <iostream>
using namespace std;

#define CANT 50

void cargarVector(int sinor[CANT],int dimension){
    for (int i = 0; i < dimension; i++) {
     cout <<"Ingrese el numero sinor a registrar"<<endl;
     cin>>sinor[i];
    }
 return;
}

void ordenarVector(int sinor[CANT],int dimension){
 int aux=0;
 
 for (int i = 0; i<dimension/2; i++) {
    aux=0;

    aux= sinor[dimension-1-i];

    sinor[dimension-1-i]=sinor[i];
  
    sinor[i]=aux;
 }
 return;
}

void imprimirVector (int sinor[CANT],int dimension){
 for (int i = 0; i < dimension; i++) {
  cout <<"En la posicion: "<<i<<" el valor es "<<sinor[i]<<endl;
  cout<<"----------------------------------------------------" <<endl;
 }
 return;
}

int main () {
 int sinor[CANT];
 int dimension=0;

 cout<<"Ingrese la cantidad de datos a registrar"<<endl;
 cin>>dimension;
 
 cargarVector(sinor, dimension);
 imprimirVector(sinor, dimension);

 cout<<"*********************************************************";
 cout<<endl;

 ordenarVector(sinor, dimension);
 imprimirVector(sinor, dimension);
 
 system("pause");
 return 0;
}