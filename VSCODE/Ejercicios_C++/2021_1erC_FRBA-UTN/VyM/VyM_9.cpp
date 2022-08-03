#include <iostream>
using namespace std;

#define N_VALORES 40

void cargarVector (int vector[], int dimension, string mensaje){
 for (int i = 0; i < dimension; i++){
     cout<<"Ingrese un valor del conjunto"<< mensaje<<endl;
     cin>>vector[i];
 }
}

void impVectorC (int vectorC[], int dimension, int vectorA[], int vectorB[]){
 int contN=0;
 
 for (int i = 0; i < dimension; i++){

     vectorC[i]=vectorA[i]+vectorB[dimension-i];
     
     cout<<"El valor del vector C es "<<vectorC[i]<<" en la posicion "<<i+1<<endl;
 }
}

int main () {
 int dimension=0;
 int vectorA[N_VALORES]={0};
 int vectorB[N_VALORES]={0};
 int vectorC[N_VALORES]={0};

 cout<<"Ingresar la longitud del conjunto"<<endl;
 cin>>dimension;

 cargarVector(vectorA, dimension, " del vector A");
 cargarVector(vectorB, dimension, " del vector B");

 impVectorC (vectorC, dimension, vectorA, vectorB);
 
 system("pause");
 return 0;
}