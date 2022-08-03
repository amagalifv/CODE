#include <iostream>
using namespace std;

#define M_FILAS 20
#define N_COLUMNAS 25

void cargarMatriz(int matriz[M_FILAS][N_COLUMNAS], int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout<<"Ingrese un valor: ";
            cin>> matriz[i][j];
            cout<<endl;
        }
    }
    return;
}

void bubbleSort(int matriz[M_FILAS][N_COLUMNAS], int filas, int columnas){
    int j;
    int key;
 //ordena cada columna en forma creciente
    for ( int i = 0; i < filas; i++ ) {
    
        for (int j = 0; j < columnas; j++ ) { 
            key= matriz[i][j];
            
            for (int k = i + 1 ; k < filas; k++ ) {
                
                if ( matriz[k][j] < key ) {
                    key = matriz[k][j];
                    matriz[k][j] = matriz[i][j];  
                    matriz[i][j] = key;
                }
            }
        }
    }
 return;  
}

void bubbleSort2(int matriz[M_FILAS][N_COLUMNAS], int filas, int columnas){
    int j;
    int key;
//ordena cada fila en forma creciente
    for ( int i = 0; i < filas; i++ ) {
    
        for (int j = 0; j < columnas; j++ ) { 
            key= matriz[i][j];
            
            for (int k = j + 1 ; k < columnas; k++ ) {
                
                if ( matriz[i][k] < key ) {
                    key = matriz[i][k];
                    matriz[i][k] = matriz[i][j];  
                    matriz[i][j] = key;
                }
            }
        }
    }
 return;  
}

void imprimirMatriz (int matriz[M_FILAS][N_COLUMNAS], int filas, int columnas) {

 for (int i = 0; i < filas; i++) {
     
    for (int j = 0; j < columnas; j++) {
     
     cout<<matriz[i][j]<<" - ";
     
    }
  cout<< endl;
 }

return;
}

int main () {
 int matriz [M_FILAS][N_COLUMNAS];
 int filas;
 int columnas;

 cout<<"Ingrese la cantidad de filas de la matriz"<<endl;
 cin>>filas;
 cout<<"Ingrese la cantidad de columnas de la matriz"<<endl;
 cin>>columnas;

 cargarMatriz(matriz, filas, columnas);

 imprimirMatriz(matriz, filas, columnas);
 cout<<endl;
 cout<<"------------------------------"<<endl;

 bubbleSort(matriz, filas, columnas);

 imprimirMatriz(matriz, filas, columnas);
 cout<<endl;
 cout<<"------------------------------"<<endl;

 bubbleSort2(matriz, filas, columnas);

 imprimirMatriz(matriz, filas, columnas);
 cout<<endl;
 cout<<"------------------------------"<<endl;

 system("pause");
 return 0;
}

/*
LOTE DE PRUEBAS
7-3-10-0
1-2-9-6
4-5-12-8
*/