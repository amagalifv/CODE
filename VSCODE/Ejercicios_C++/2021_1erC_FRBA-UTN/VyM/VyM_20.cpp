#include <iostream>
using namespace std;

#define M_DIMENSION 25

typedef struct{
int plano;
int columna;
int fila;
}ST_POS;

void cargarMatriz(int matridrim[M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension);

void imprimirMatriz(int matridrim [M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension);

void imprimirMatrizA(int matridrim [M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension);

void buscarMax (int matridrim [M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension, int &mayorValor, ST_POS &mayorPos);

void cargarMatSumCol (int matridrim [M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension,int matSumCol [M_DIMENSION][M_DIMENSION]);

void imprimirMatSumCol (int matSumCol [M_DIMENSION][M_DIMENSION],  int dimension);

int main () {
 int dimension;
 int matridrim [M_DIMENSION][M_DIMENSION][M_DIMENSION];
 int mayorValor;
 ST_POS mayorPos;
 int matMaxFil [M_DIMENSION][M_DIMENSION];
 int matSumCol [M_DIMENSION][M_DIMENSION];


 cout<<"Ingrese la cantidad de filas, columnas y planos de la matriz"<<endl;
 cin>>dimension;
 
 cargarMatriz(matridrim, dimension);

 imprimirMatriz(matridrim, dimension); 

 cout<<"-------------------------------"<<endl;

 imprimirMatrizA(matridrim, dimension);

 cout<<"-------------------------------"<<endl;

 buscarMax(matridrim, dimension, mayorValor, mayorPos);

 cout<<"El mayor valor encontrado fue "<<mayorValor<<" en la posicion plano:"<<mayorPos.plano<<", columna: "<<mayorPos.columna<<", fila: "<<mayorPos.fila<<endl;
 
 cargarMatSumCol(matridrim, dimension, matSumCol);

 cout<<"-------------------------------"<<endl;
 cout<< "Matriz matSumCol:"<<endl;

 imprimirMatSumCol(matSumCol, dimension);

 system("pause");
 return 0;
}

void cargarMatriz(int matridrim[M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension){
    
    for (int k = 0; k < dimension; k++) {
        
        for (int i = 0; i < dimension; i++){
            
            for (int j = 0; j < dimension; j++){
                cout<<"Ingrese un valor: ";
                cin>> matridrim[k][i][j];
                cout<<endl;
            }
        }
    } 
 return;   
}

void imprimirMatriz(int matridrim [M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension) {
 //plano:k columna:j fila:i
 for (int k = 0; k < dimension; k++) {
    cout<<"Plano "<<k+1<< ": "<<endl;

    for (int i = 0; i < dimension; i++) {
     
        for (int j = 0; j < dimension; j++) {
     
         cout<<matridrim[k][i][j]<<"  ";
     
        }
     cout<< endl;
    }
 }
return;
}

void imprimirMatrizA(int matridrim [M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension) {
 //plano:k columna:j fila:i
 for (int k = 0; k < dimension; k++) {
    cout<<"Plano "<<k+1<< ": "<<endl;

    for (int j = 0; j < dimension; j++) {
     
        for (int i = 0; i < dimension; i++) {
     
         cout<<matridrim[k][i][j]<<"   ";
     
        }
     cout<< endl;
    }
 }
return;
}

void buscarMax (int matridrim [M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension, int &mayorValor, ST_POS &mayorPos){
 bool primerEntrada=true;

    for (int k = 0; k < dimension; k++) {
        
        for (int i = 0; i < dimension; i++){
            
            for (int j = 0; j < dimension; j++){
                
                if (primerEntrada==true || matridrim[k][i][j]>mayorValor ) {
                 mayorValor=matridrim[k][i][j];

                 mayorPos.plano=k;
                 mayorPos.columna=j;
                 mayorPos.fila=i;

                 primerEntrada=false;
                }
            }
        }
    } 


return;
}

void cargarMatSumCol (int matridrim [M_DIMENSION][M_DIMENSION][M_DIMENSION], int dimension,int matSumCol [M_DIMENSION][M_DIMENSION]) {
 int sum=0;


 for (int k = 0; k < dimension; k++) {
        
    for (int j = 0; j < dimension; j++){
            
        for (int i = 0; i < dimension; i++){

            sum+=matridrim[k][i][j];
        }
     matSumCol[j][k]=sum;
     sum=0;
    }
 } 


return;
}

void imprimirMatSumCol (int matSumCol [M_DIMENSION][M_DIMENSION],  int dimension) {
 
 for (int k = 0; k < dimension; k++) {
    
    for (int j = 0; j < dimension; j++) {
     
     cout<<matSumCol[k][j]<<"  ";
     
    }
 cout<<endl;
 }
 return;
}