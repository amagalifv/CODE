#include <iostream>
using namespace std;

void cargarVector (int vec[] , int dimension);
void encontrarMaximo (int vec[], int dimension, int &max);
void imprimirPosMax(int vec[], int max, int dimension);

int main () {
 int dimension=0;
 cout << "Ingrese la cantidad de numeros a ingresar"<<endl;
 cin >> dimension;
 
 int vector[dimension]={0};
 int maximo=0;

 cargarVector(vector , dimension);

 encontrarMaximo (vector, dimension, maximo);

 cout<< "El maximo es "<<maximo;
 imprimirPosMax(vector, maximo, dimension);

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

void encontrarMaximo (int vec[], int dimension, int &max){
    max=vec[0];

    for (int i = 0; i < dimension; i++){
       if (vec[i]>=max){
           max=vec[i];
       }     
    }  
}

void imprimirPosMax(int vec[], int max, int dimension){
   for (int i = 0; i < dimension; i++){
      if (vec[i]== max){
          cout<< " y aparece en la posicion "<< i+1 <<endl;
      } 
   }
}

