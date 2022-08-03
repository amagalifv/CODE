#include <iostream>
using namespace std;

#define MAX_FILAS 29
#define MAX_COLUMNAS 24

void cargarMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            cout<<"Ingrese un valor: ";
            cin>> matriz[i][j];
            cout<<endl;
        }
    }
    return;
}

void imprimirMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
           cout << "Posicion ("<<i<<", "<<j<<") es:"<< matriz[i][j]<<endl;
        }
    }
    return;
}

float promedioMatriz(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas){
    int contadorMatriz=0;
    int prom=0;
    
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
           contadorMatriz+=matriz[i][j];
        }
    }

    if (filas*columnas!=0){
        prom=contadorMatriz/(filas*columnas);
    }
    return prom;
}

void SumaColumnas(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas,int vecSumCol[]){
 int sum=0;

 for (int j = 0; j < columnas; j++){
        
    for (int i = 0; i < filas; i++){
      sum+=matriz[i][j];
    }
    vecSumCol[j]=sum;
    sum=0;
 }
 return;
}

void imprimirVectores (int vec[], int dimension, string mensaje){
    for (int i = 0; i < dimension; i++){
        cout<< "Posicion: "<< i << mensaje << vec[i]<<endl;
    }
    return;
}


int main () {
 int filas=0;
 int columnas=0;
 float promedio=0;
 
 cout << "Ingrese la cantidad de filas de la matriz"<<endl;
 cin >> filas;
 cout << "Ingrese la cantidad de columnas de la matriz"<<endl;
 cin >> columnas;

 int matriz[MAX_FILAS][MAX_COLUMNAS];
 int vecSumCol[columnas]={0};
 //int vecMaxFilas[filas]={0};
 
 cargarMatriz(matriz, filas, columnas);
 imprimirMatriz(matriz, filas, columnas);

 promedio=promedioMatriz(matriz, filas, columnas);
 cout << "El promedio de los componentes es: "<< promedio << endl;

 SumaColumnas( matriz, filas, columnas, vecSumCol);
 imprimirVectores(vecSumCol, columnas, " del vector de suma de columnas - valor: ");

 system("pause");
 return 0;
}