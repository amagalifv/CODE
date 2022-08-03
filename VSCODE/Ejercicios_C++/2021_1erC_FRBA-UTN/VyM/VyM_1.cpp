#include <iostream>
using namespace std;

void cargarVector (int vec[] , int dimension);
void imprimirVectores (int vec[] , int dimension);

int main () {
 int dimension=0;
       
    cout << "Ingrese la cantidad de numeros pares que desea obtener"<<endl;
    cin >> dimension;

    if (dimension<25){
        int vector1[dimension]={0};

        cargarVector(vector1 , dimension);

        imprimirVectores (vector1 , dimension);
    }
    
 system("pause");
 return 0;
}

void cargarVector (int vec[] , int dimension){
    int contPar=0;
    
    for (int i = 0; i < dimension; i++){
        vec[i]=contPar;

        contPar+=2;
    }
    return;
}


void imprimirVectores (int vec[] , int dimension){
    for (int i = 0; i < dimension; i++){
        cout<< "Posicion: "<< i << " - valor: "<< vec[i]<<endl;
    }
    return;
}


