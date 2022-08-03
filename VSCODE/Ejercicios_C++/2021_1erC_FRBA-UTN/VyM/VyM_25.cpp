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

int busqSecuencial (int arr[], int dimension, int dato) {
    int i=0;
    int pos=-1;
    bool primeraEntrada=true;

    while (i<dimension && pos == -1 && primeraEntrada == true){
        if (arr[i] == dato && primeraEntrada == true){
            pos = i;
            primeraEntrada=false;
        }
        i++;    
    }
    return pos;
}

int busqBinaria(int arr[], int dimension, int dato){
    int inicio=0;
    int fin = dimension-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        if (arr[mitad]==dato){
            return mitad;
        }

        if (arr[mitad]>dato){
             fin=mitad - 1; 
         }else{
             inicio=mitad+1; 
         } 
    }
    return -1;
}

int main () {
    int arr[MAX];
    int dimension;
    int  dato;
    int busqSecu;
    int busqBin;

    cout<<"Ingresar la cantidad de datos a guardar"<<endl;
    cin>>dimension;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<endl;

    cargarVector(arr, dimension);
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<endl;

    cout<<"Ingresar el datos a buscar"<<endl;
    cin>>dato;
    cout<<endl;

    cout<<"--------------------BUSQUEDA SECUENCIAL(A)--------------------"<<endl;
    busqSecu=busqSecuencial(arr,dimension, dato);
    if (busqSecu != -1) {
        cout<<"Aparecio en la posicion "<<busqSecu+1<<endl;
    }else{
        cout<<"No aparecio "<<endl;
    }
    cout<<endl;

    cout<<"--------------------BUSQUEDA BINARIA (B)--------------------"<<endl;
    busqBin=busqBinaria(arr,dimension, dato);
    if (busqBin != -1) {
        cout<<"Aparecio en la posicion "<<busqBin+1<<endl;
    }else{
        cout<<"No aparecio "<<endl;
    }
    cout<<endl;
 
    system("pause");
    return 0;
}