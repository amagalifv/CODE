#include <iostream>
using namespace std;

void cargarVector (int vec[] , int dimension);
void cargarFactorial (int vec[] , int factorial[] ,int  dimension);
void imprimirVectores (int vec[] , int fact[], int dimension);

int main () {
 
 int dimension=0;
       
 cout << "Ingrese la cantidad de numeros a sumar"<<endl;
 cin >> dimension;

 int vector[dimension]={0};
 int factorial[dimension]={0};

 cargarVector(vector , dimension);
 cargarFactorial (vector, factorial , dimension);

 imprimirVectores (vector, factorial, dimension);

 system("pause");
 return 0;
}

void cargarVector (int vec[] , int dimension){

    for (int i = 0; i < dimension; i++){
        cout<<"Ingrese el numero "<< i+1 << " del vector" << endl;
        cin>> vec[i];
        cout<<endl;    
    }
    return;    
}

void cargarFactorial (int vec[] , int fact[] , int dimension){
    int factr=1;
    
    for (int i = 0; i < dimension; i++){
        
        for (int e=vec[i] ; e !=0 ; e--){
        factr=factr*e;
        }

        fact[i]=factr; 
        
        factr=1;   
    }
    return;    
}

void imprimirVectores (int vec[], int fact[], int dimension){
    for (int i = 0; i < dimension; i++){
        cout<< "Posicion: "<< i << " del vector - valor: "<< vec[i]<< " su factorial es "<< fact[i]<<endl;
    }
    return;
}

