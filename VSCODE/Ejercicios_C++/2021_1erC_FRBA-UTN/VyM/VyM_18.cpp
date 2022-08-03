#include <iostream>
using namespace std;

#define FILAS_COLUMNAS 25

void cargarMatriz(int matriz[FILAS_COLUMNAS][FILAS_COLUMNAS], int filasColumnas);
void diagonales1y2(int matriz[FILAS_COLUMNAS][FILAS_COLUMNAS], int filasColumnas);
void cuadrantes (int matriz[FILAS_COLUMNAS][FILAS_COLUMNAS], int filasColumnas);
void triangulares(int matriz[FILAS_COLUMNAS][FILAS_COLUMNAS], int filasColumnas);

int main () {
 int filasColumnas=0;
 int matriz[FILAS_COLUMNAS][FILAS_COLUMNAS];
 
 cout << "Ingrese la cantidad de filas/columnas de la matriz cuadrada (debe ser par)"<<endl;
 cin >> filasColumnas;

 cargarMatriz(matriz, filasColumnas);
 diagonales1y2(matriz, filasColumnas);

 
 system("pause");
 return 0;
}

void cargarMatriz(int matriz[FILAS_COLUMNAS][FILAS_COLUMNAS], int filasColumnas){
    for (int i = 0; i < filasColumnas; i++){
        for (int j = 0; j < filasColumnas; j++){
            cout<<"Ingrese un valor: ";
            cin>> matriz[i][j];
            cout<<endl;
        }
    }
    return;
}

void diagonales1y2(int matriz[FILAS_COLUMNAS][FILAS_COLUMNAS], int filasColumnas){
 int sumaDiagonaPrincip=0;
 int sumaDiagonaSecund=0; 
     
 for (int i = 0; i < filasColumnas; i++){
     sumaDiagonaPrincip += matriz[i][i];
     sumaDiagonaSecund += matriz[i][(filasColumnas-1)-i];
 }

//impresion
 if (sumaDiagonaPrincip>sumaDiagonaSecund){
    cout<<"La diagonal principal es la mayor: " <<sumaDiagonaPrincip<<" sus valores son " <<endl;
    for (int i = 0; i < filasColumnas; i++){
        cout<<matriz[i][i]<<" -";
    }

 }else{
    cout<<"La diagonal secundaria es la mayor "<<sumaDiagonaSecund<<" sus valores son "<<endl;
    for (int i = 0; i < filasColumnas; i++){
        cout<<matriz[i][(filasColumnas-1)-i]<<" -";
    }
 }

return;
}

void cuadrantes(int matriz[FILAS_COLUMNAS][FILAS_COLUMNAS], int filasColumnas){
 int  sumCuarto1=0;
 int  sumCuarto2=0;
 int  sumCuarto3=0;
 int  sumCuarto4=0;
 
 for (int i = 0; i < filasColumnas/2; i++) {

        for (int j = 0; j < filasColumnas/2; j++) {
            sumCuarto1 += matriz[i][j];
            sumCuarto2 += matriz[i][(filasColumnas/2) + j];
            sumCuarto3 += matriz[(filasColumnas/2) + i][j];
            sumCuarto4 += matriz[(filasColumnas/2) + i][(filasColumnas/2) + j];
        }
    }
}

void triangulares(int matriz[FILAS_COLUMNAS][FILAS_COLUMNAS], int filasColumnas){
  int triangularSup=0;
  int triangularInf=0;
  
  for (int i = 0; i < filasColumnas; i++){
    for (int j = i+1; j < filasColumnas; j++){
         cout<<matriz[i][j]<<"   ";
        triangularSup+=matriz[i][j];
    }
    cout<<endl;
 }

 for (int i = 0; i < filasColumnas; i++){
    for (int j = 0; j < i ; j++){
        cout<<matriz[i][j]<<"   ";
        triangularInf+=matriz[i][j];
    }
    cout<<endl;
 }

 return;    
}