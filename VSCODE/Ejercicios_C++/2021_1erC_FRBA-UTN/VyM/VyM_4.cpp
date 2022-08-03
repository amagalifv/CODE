#include <iostream>
using namespace std;

void cargarVector (int vec[] , int dimension);

int main () {
 int dimension=0;
       
 cout << "Ingrese la cantidad de numeros pares que desea obtener"<<endl;
 cin >> dimension;
 int vector1[dimension]={0};

 cargarVector(vector1 , dimension);

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