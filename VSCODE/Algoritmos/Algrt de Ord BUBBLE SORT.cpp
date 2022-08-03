#include <iostream>
using namespace std;

//BUBBLE SORT

void burbujeo(int arr[], int n){
 int i;
 int j;
 int aux;

 for (int i = 0; i < n-1; i++){

     for (int j = 0; i < n-i-1 ; j++){

         if (arr[j]>arr[j+1]){
             aux = arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=aux;
         }
     }
 }

}

void burbujeoReloaded(int arr[], int n){
 int j=0;
 int aux;
 int i=0;
 bool ordenado = false;

 while (i < n && !ordenado){
     ordenado= true; //Arranco asumiendo que si esta ordenado
     //Los ultimos i elementos ya estan ordenados

     for (int j = 0; j < n-i-1 ; j++){
         if (arr[j]>arr[j+1]){
             aux = arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=aux;
             ordenado = false; // Cambio de flag si hice un swap
         }
     }
     i++;
 }

}

void burbujeoReloaded(int arr[], int n){
    int aux;
    int i=0;
    bool ordenado = false;

    while (i < n && !ordenado){

        ordenado= true;

        for (int j = 0; j < n-i-1 ; j++){

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

int main () {




 system("pause");
 return 0;
}

//Burbujeo matrices por columnas
void ordenarPorColumnas (int matriz[filas][columnas], int dimension1, int dimension2){
    int aux;

    for (int i = 0; i < dimension1-1; i++) {

        for (int j = 0; j < dimension2-i; j++) {

            for (int k=0; k < dimension2-i;k++){

                if (matriz[i][j] > matriz[i+1][j]) {
                    aux = matriz[j][i];
                    matriz[j][i] = matriz[j+1][i];
                    matriz[j+1][i] = aux;
                }
            }
        }
    }
}


//Burbujeo matrices por filas
void ordenarPorFilas (int matriz[filas][columnas], int dimension1, int dimension2){
    int aux;

    for (int i = 0; i < dimension1; i++) {

        for (int j = 0; j < dimension2-i-1; j++) {

            for (int k=0; k < dimension2-i;k++){

                if (matriz[i][k] > matriz[i][k+1]) {
                    aux = matriz[i][k];
                    matriz[i][k] = matriz[i][k+1];
                    matriz[i][k+1] = aux;
                }
            }
        }
    }
}