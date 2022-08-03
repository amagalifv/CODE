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

bool siDatoEs (int arr[], int dimension, int dato){
    bool siDato=false;

    for (int i = 0; i < dimension; i++) {
        if (arr[i]==dato) {
            siDato=true;
        }
    }

    return siDato; 
}

int busqSecuencial (int arr[], int dimension, int dato) {
    int i=0;
    int pos=-1;

    while (i<dimension && pos == -1){
        if (arr[i] == dato){
            pos = i;
        }
        i++;    
    }
    return pos;
}

void busqC (int arr[], int dimension, int dato) {
    int i=0;

    while (i<dimension){
        if (arr[i] == dato){
            cout<<"El dato buscado se encontro en la posicion "<<i+1<<endl;
        }
        i++;    
    }
    return;
}

void primeraYultima (int arr[], int dimension, int dato) {
    int i=0;
    int pos=-1;
    bool primeraEntrada=true;

    while (i<dimension){
        
        if (arr[i] == dato){
            if (primeraEntrada==true) {
                cout<<"La primer posicion en que aparece dato es: "<<i+1<<endl;
                primeraEntrada=false;
            }
            pos = i;
        }
        i++;    
    }
    cout<<"La ultima posicion en que aparece dato es: "<<pos+1<<endl;

    return;
}

int main () {
    int arr[MAX];
    int dimension;
    int  dato;
    bool datoEncontrar;
    int busqSecu;

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

    cout<<"--------------------DATO ES PARTE DEL VECTOR?(A)--------------------"<<endl;
    datoEncontrar=siDatoEs(arr,dimension, dato);
    if (datoEncontrar==true) {
        cout<<"SI"<<endl;
    }else{
       cout<<"NO"<<endl; 
    }
    cout<<endl;
     
    cout<<"--------------------BUSQUEDA SECUENCIAL(B)--------------------"<<endl;
    busqSecu=busqSecuencial(arr,dimension, dato);
    if (busqSecu != -1) {
        cout<<"Aparecio en la posicion "<<busqSecu+1<<endl;
    }else{
        cout<<"No aparecio "<<endl;
    }
    cout<<endl;
    
    cout<<"--------------------(C)--------------------"<<endl;
    busqC(arr,dimension, dato);
    cout<<endl;

    cout<<"--------------------(D)--------------------"<<endl;
    primeraYultima(arr,dimension, dato);
 
    system("pause");
    return 0;
}