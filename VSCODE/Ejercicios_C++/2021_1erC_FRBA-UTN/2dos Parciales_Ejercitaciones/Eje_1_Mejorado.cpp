#include <iostream>
using namespace std;

#define MAX 100

void leer (string mensaje, int &x) {
    cout<<mensaje<<endl;
    cin>>x;

    return;
}

void cargarVectores(int vector[], int dimension){

    for (int i = 0; i < dimension; i++) {
        cout<<"Ingrese un numero"<<endl;
        cin>>vector[i];
    }
    return;
}

void cargarVecSuma (int vector1[], int vector2[],int vecSuma[], int dimension) {

    for (int i = 0; i < dimension; i++) {

        vecSuma[i]=vector1[i]+vector2[i];
    }

    return;
}

void cargarVecResta (int vector1[], int vector2[],int vecResta[], int dimension) {

    for (int i = 0; i < dimension; i++) {

        vecResta[i]=vector1[i]-vector2[i];
    }

    return;
}

void cargarVecProd (int vector1[], int vector2[],int vecProd[], int dimension) {
    for (int i = 0; i < dimension; i++) {
        vecProd[i]=vector1[i]*vector2[i];
    }

    return;
}

void imprimirVector (int vector[], int dimension){
    for (int i = 0; i < dimension; i++) {
        cout<<"En la posicion "<<i<<"el resultado es: "<<vector[i]<<endl;
    }
    return;
}

int main () {
    int vector1[MAX];
    int vector2[MAX];
    int vecSuma[MAX];
    int vecResta[MAX];
    int vecProd[MAX];
    int dimension1=0;
    int dimension2=0;

    leer("Ingrese la dimension del primer vector", dimension1);
    leer("Ingrese la dimension del segundo vector", dimension2);

    if (dimension1=dimension2) {
        cargarVectores(vector1,dimension1);
        cargarVectores(vector2,dimension2);

        cargarVecSuma(vector1,vector2,vecSuma,dimension1);
        cargarVecResta(vector1,vector2,vecResta,dimension1);
        cargarVecProd(vector1,vector2,vecProd,dimension1);

        cout<<"--------------------VECTOR SUMA--------------------"<<endl;
        imprimirVector(vecSuma,dimension1);
        cout<<endl;

        cout<<"--------------------VECTOR RESTA--------------------"<<endl;
        imprimirVector(vecResta,dimension1);
        cout<<endl;

        cout<<"--------------------VECTOR PRODUCTO--------------------"<<endl;
        imprimirVector(vecProd,dimension1);
        cout<<endl;
    }

    system("pause");
    return 0;
}