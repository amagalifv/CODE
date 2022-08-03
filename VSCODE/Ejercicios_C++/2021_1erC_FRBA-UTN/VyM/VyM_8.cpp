#include <iostream>
using namespace std;

#define N_VALORES 25

void cargarVector (string vector[], int dimension){
 for (int i = 0; i < dimension; i++){
     cout<<"Ingrese un valor del conjunto GG"<<endl;
     cin>>vector[i];
 }
}

void imprimirUnoxLinea(string vector[], int dimension){
    for (int i = dimension-1; i >= 0 ; i--){
        cout<<vector[i]<<" esta la posicion "<<i<<endl;
    }
}

void imprimirDiezxLinea(string vector[], int dimension){
    for (int i = dimension-1; i >= 20 ; i--){
        cout<<vector[i]<<" ";
    }

    cout<<endl;

    for (int i = 19; i >= 10 ; i--){
        cout<<vector[i]<<" ";
    }

    cout<<endl;

    for (int i = 9; i >= 0 ; i--){
        cout<<vector[i]<<" ";
    }

    cout<<endl;
}

void imprimirCincoxLinea(string vector[], int dimension){
 for (int i = 24 ; i >= 20 ; i--){
        cout<<vector[i]<<"(pos "<<i<<")";
 }

 cout<<endl;

 for (int i = 19 ; i >= 15 ; i--){
        cout<<vector[i]<<"(pos "<<i<<")";
 }

 cout<<endl;

 for (int i = 14 ; i >= 10 ; i--){
        cout<<vector[i]<<"(pos "<<i<<")";
 }

 cout<<endl;

 for (int i = 9 ; i >= 5 ; i--){
        cout<<vector[i]<<"(pos "<<i<<")";
 }

 cout<<endl;
 
 for (int i = 4 ; i >= 0 ; i--){
        cout<<vector[i]<<"(pos "<<i<<")";
 }

 cout<<endl;
}

int main () {
 int dimension=0;
 string vector[N_VALORES];

 cout<<"Ingresar la longitud del conjunto"<<endl;
 cin>>dimension;

 cargarVector(vector, dimension);
 
 cout<<"--------------------1ra IMPRESION--------------------"<<endl;
 imprimirUnoxLinea(vector, dimension);
 
 cout<<"--------------------2da IMPRESION--------------------"<<endl;
 imprimirDiezxLinea(vector, dimension);

 cout<<"--------------------3ra IMPRESION--------------------"<<endl;
 imprimirCincoxLinea(vector, dimension);

 system("pause");
 return 0;
}