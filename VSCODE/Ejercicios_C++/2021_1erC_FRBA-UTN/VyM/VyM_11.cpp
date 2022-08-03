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

void ordenarVectores(int vector[], int dimension){
    int i, j, aux;
    int i=0;
    bool ordenado = false;

    while (i < dimension && !ordenado){
        ordenado= true;

        for (int j = 0; j < dimension-i-1 ; j++){
            if (vector[j]>vector[j+1]){
                aux = vector[j];
                vector[j]=vector[j+1];
                vector[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void crearVectorC(int vecA[],int dimensionA, int vecB[], int dimensionB, int vecC[]){
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < dimensionA && j < dimensionB) {

        if (vecA[i] < vecB[j]) {

            vecC[k] = vecA[i];
            i++;
            
        } else {
            vecC[k] = vecB[j];
            j++;
        }

        k++;
    }

    while(i < dimensionA) {
        vecC[k] = vecA[i];
        i++;
        k++;
    }

    while(j < dimensionB) {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
}


int main () {
    int dimensionA=0;
    int dimensionB=0;
    int vectorA[N_VALORES]={0};
    int vectorB[M_VALORES]={0};
    int vectorC[M_VALORES]={0};

    cout<<"Ingresar la longitud del vector A"<<endl;
    cin>>dimensionA;
    cout<<"Ingresar la longitud del vector B"<<endl;
    cin>>dimensionB;

    cargarVector(vectorA, dimensionA, " del vector A");
    cargarVector(vectorB, dimensionB, " del vector B");

    ordenarVectores(vectorA, dimensionA);
    ordenarVectores(vectorB, dimensionB);

    crearVectorC(vectorA, dimensionA, vectorB, dimensionB, vectorC);
    
    system("pause");
    return 0;
}
