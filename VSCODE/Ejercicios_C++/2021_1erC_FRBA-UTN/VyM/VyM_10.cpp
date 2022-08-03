#include <iostream>
using namespace std;

#define N_VALORES 15
#define M_VALORES 10

void cargarVector (int vector[], int dimension, string mensaje){
 for (int i = 0; i < dimension; i++){
     cout<<"Ingrese un valor del conjunto"<< mensaje<<endl;
     cin>>vector[i];
 }
}

void crearVectorC(int vectorA[], int vectorB[], int dimension, int vectorC[]){
    for (int i = 0; i < dimension; i++){

     vectorC[i]=vectorA[i]+vectorB[i];

     cout<<"El valor del vector C es "<<vectorC[i]<<" en la posicion "<<i+1<<endl;
 }
}

void crearVectorD(int vectorA[], int vectorB[], int dimension, int vectorD[]){
int e=0;

    for (int i = 0; i < dimension; i++){

        if (vectorA[i] != 0  &&  vectorB[i] != 0){
         vectorD[e]=vectorA[i]+vectorB[i];
         cout<<"El valor del vector D es "<<vectorD[i]<<" en la posicion "<<i+1<<endl;
         e++;
        }

    }
}

int main () {
 int dimensionA=0;
 int dimensionB=0;
 int vectorA[N_VALORES]={0};
 int vectorB[M_VALORES]={0};
 int vectorC[M_VALORES]={0};
 int vectorD[N_VALORES]={0};

 cout<<"Ingresar la longitud del vector A"<<endl;
 cin>>dimensionA;
 cout<<"Ingresar la longitud del vector B"<<endl;
 cin>>dimensionB;

 cargarVector(vectorA, dimensionA, " del vector A");
 cargarVector(vectorB, dimensionB, " del vector B");

 cout<<"-------------------- 1ra IMPRESION--vector C---------------------"<<endl;
 crearVectorC(vectorA, vectorB, dimensionB, vectorC);
 cout<<"-------------------- 2da IMPRESION--vector D---------------------"<<endl;
 crearVectorD(vectorA, vectorB, dimensionA, vectorD);
 
 system("pause");
 return 0;
}