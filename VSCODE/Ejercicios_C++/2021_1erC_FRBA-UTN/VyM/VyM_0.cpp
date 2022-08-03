#include <iostream>
using namespace std;

void cargarVector (int vec[] , int dimension, string mensaje);
void sumaVectores (int vec1 [], int vec2 [], int sumaVec[], int dimension);
void imprimirVectores (int sumaVec[] , int dimension);

int main () {
    int dimension=0;
       
    cout << "Ingrese la cantidad de numeros a sumar"<<endl;
    cin >> dimension;

    int vector1[dimension]={0};
    int vector2[dimension]={0};
    int sumaVec[dimension]={0};

    cargarVector(vector1 , dimension, "Vector 1");
    cargarVector(vector2 , dimension, "Vector 2");

    sumaVectores( vector1, vector2, sumaVec, dimension);

    imprimirVectores (sumaVec , dimension);
 
 system("pause");
 return 0;
}

void cargarVector (int vec[] , int dimension, string mensaje){
    for (int i = 0; i < dimension; i++){
        cout<<"Ingrese el numero "<< i+1 << " a sumar del " << mensaje<< endl;
        cin>> vec[i];
        cout<<endl;    
    }
    return;    
}

void sumaVectores (int vec1 [], int vec2 [], int sumaVec[], int dimension){
    for (int i = 0; i < dimension; i++){
        sumaVec[i]=vec1[i] + vec2[i];
    }
    return;
}

void imprimirVectores (int sumaVec[] , int dimension){
    for (int i = 0; i < dimension; i++){
        cout<< "Posicion: "<< i << " - valor: "<< sumaVec[i]<<endl;
    }
    return;
}