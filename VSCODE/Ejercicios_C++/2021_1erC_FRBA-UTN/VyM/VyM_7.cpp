#include <iostream>
using namespace std;

void cargarVector (int vec[] , int dimension);
void encontrarMaximo (int vec[], int dimension, int vecMaximos[]);

int main () {
 int dimension=0;
 cout << "Ingrese la cantidad de numeros a ingresar"<<endl;
 cin >> dimension;
 
 int vector[dimension]={0};
 int vecMaximos[2]={0};

 cargarVector(vector , dimension);

 encontrarMaximo (vector, dimension, vecMaximos);

 cout<< "El mejor dato es "<< vecMaximos[0]<<" y el siguiente es "<<vecMaximos[1]<<endl;

 system("pause");
 return 0;
}

void cargarVector (int vec[] , int dimension){
   for (int i = 0; i < dimension; i++){
        cout<<"Ingrese un numero "<< endl;
        cin>> vec[i];
        cout<<endl;    
    }
    return;
}

void encontrarMaximo (int vec[], int dimension, int vecMaximos[]){
    vecMaximos[0]=vec[0];
    vecMaximos[1]=vec[0];

    for (int i = 0; i < dimension; i++){
        if (vec[i]>=vecMaximos[0]){
            vecMaximos[1]=vecMaximos[0];
            vecMaximos[0]=vec[i];

        } else {
             if (vec[i]>=vecMaximos[1]){
                vecMaximos[1]=vec[i];
             }
        }
    }
}