#include <iostream>
using namespace std;

#define MAX 100

void cargarVector(int vec[], int dimen){
    for (int i = 0; i < dimen; i++) {
     cout<<"Ingrese el valor del arreglo"<<endl;
     cin>> vec[i];
    }
    return;
}

void imprimirVector(int vec[], int dimen){
    for (int i = dimen-1; i >=0; i--) {
     cout<<"Posicion"<<i+1<<": "<<vec[i]<<endl;
    }
    return;
}

int main () {
 int vec[MAX]={0};
 int dimension=0;

 cout<<"Ingrese la cantidad de datos a procesar"<<endl;
 cin>>dimension;

 cargarVector(vec, dimension);

 imprimirVector(vec, dimension);

 system("pause");
 return 0;
}