#include <iostream>
using namespace std;

#define MAX 1000

void cargarVector (int arr[], int dimension) {
    
    for (int i = 0; i < dimension; i++) {
        cout<<"Ingrese el numero a guardar"<<endl;
        cin>>arr[i];
    }

    return;
}
//BUBBLE SORT
void ordVector(int arr[], int dimension){
    int j;
    int i=0;
    int aux;

    bool ordenado = false;

    while (i < dimension && !ordenado){
        ordenado= true;
         
        for (int j = 0; j < dimension-i-1 ; j++){
            if (arr[j]>arr[j+1]){
                aux = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }
}

void apareoConUnDato (int arr[], int dimension, int dato, int arrFinal[]){
    int i = 0;
    int k = 0;

    while (i < dimension && arr[i] < dato) {
        if (arr[i] <= dato) {
            arrFinal[k] = arr[i];
            i++;
        }
        k++;
    }

    arr[i]=dato;
    k++;

    while(i < dimension && arr[i] >= dato) {
        arrFinal[k] = arr[i];
        i++;
        k++;
    }

    return;
}

void imprimirVector(int arr[], int dimension){
    for (int i = 0; i < dimension; i++) {
     cout<<"Posicion"<<i+1<<": "<<arr[i]<<endl;
    }
    return;
}

int main () {
    int arr[MAX];
    int dimension;
    int  dato;
    int arrFinal[MAX+1];

    cout<<"Ingresar la cantidad de datos a guardar"<<endl;
    cin>>dimension;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<endl;

    cargarVector(arr, dimension);
    cout<<"-----------------------IMPRESION VECTOR ORIGINAL-----------------------"<<endl;
    cout<<endl;
    imprimirVector(arr, dimension);
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<endl;
   
    ordVector(arr, dimension);
    cout<<"-----------------------IMPRESION VECTOR ORDENADO-----------------------"<<endl;
    imprimirVector(arr, dimension);
    cout<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;

    cout<<"Ingresar el dato a buscar"<<endl;
    cin>>dato;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<endl;

    apareoConUnDato(arr, dimension, dato, arrFinal);
    cout<<"-----------------------IMPRESION VECTOR RESULTANTE-----------------------"<<endl;
    imprimirVector(arrFinal, dimension+1);
    cout<<endl;
 
    system("pause");
    return 0;
}