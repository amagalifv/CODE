#include <iostream>
#include <cstdlib>
using namespace std;

// VECTORES
// PUNTO 1
int devuelveMinimo(int vector[], int dimension){
    int min;

    min=vector[0];

    for (int i=1; i<dimension; i++) {
        if (vector[i]<min) {
            min=vector[i];
        }
    }

    return min;
}
//PUNTO 2
int devuelvecontadorimo(int vector[], int dimension){
    int max;

    max=vector[0];

    for (int i=1; i<dimension; i++) {
        if (vector[i]>max) {
            max=vector[i];
        }
    }

    return max;
}
//PUNTO 3
int devuelvePosMinimo(int vector[], int dimension){
    int posMin;
    int min;

    min=vector[0];
    posMin=0;

    for (int i=1; i<dimension; i++) {
        if (vector[i]<min) {
            posMin=i;
            min=vector[i];
        }
    }

    return posMin;
}
//PUNTO 4
int devuelvePosMaximo(int vector[], int dimension){
    int posMax;
    int max;

    max=vector[0];
    posMax=0;

    for (int i=1; i<dimension; i++) {
        if (vector[i]>max) {
            posMax=i;
            max=vector[i];
        }
    }

    return posMax;
}
//PUNTO 5
bool siEncuentra(int vector[10], int valorBuscado){
    int bandera=false;

    for (int i=0; i<10; i++) {
        if (vector[i]==valorBuscado) {
            bandera=true;
        }
    }

    return bandera;
}
//PUNTO 6
int busquedaBinaria(int vector[10], int valorBuscado){
    //  DEBE ESTAR ORDENADO ANTES de min a maj
    int inicio=0;
    int fin = 10-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        if (vector[mitad]==valorBuscado){
            return mitad;
        }

        if (vector[mitad]>valorBuscado){
             fin = mitad - 1; //Cambio el limite superior
        }else{
             inicio = mitad+1; //Cambio el limite inferior
        }
    }
    // Si llegamos hasta aca es que el elemento no estaba
    return -1;
}
//PUNTO 7
int contarRepetidas(int vector[10], int valorBuscado){
    int contador=0;

    for (int i=1; i<10; i++) {
        if (vector[i]==valorBuscado) {
            contador++;
        }
    }

    return contador;
}

//MATRICES
// PUNTO 1
int maxFila(int mtrz[10][10], int buscarEnFila){
    int max;
    max=mtrz[buscarEnFila][0];

    for (int i=1; i<10 ; i++) {
        if (mtrz[buscarEnFila][i]>max) {
            max=mtrz[buscarEnFila][i];
        }
    }

    return max;
}
// PUNTO 2
int posMaxFila(int mtrz[10][10], int buscarEnFila){
    int max=0;
    int posMax=0;
    max=mtrz[buscarEnFila][0];

    for (int i=1; i<10 ; i++) {
        if (mtrz[buscarEnFila][i]>max) {
            max=mtrz[buscarEnFila][i];
            posMax=i;
        }
    }

    return posMax;
}
// PUNTO 3
int sumaDeFila(int mtrz[10][10], int sumarEnFila){
    int acum=0;

    for (int i=0; i<10 ; i++) {
        acum+=mtrz[sumarEnFila][i];
    }

    return acum;
}
// PUNTO 4
int contarPositivosDeFila(int mtrz[10][10], int positEnFila){
    int acumPisitivos=0;

    for (int i=0; i<10 ; i++) {
        if (mtrz[positEnFila][i]>0) {
            acumPisitivos++;
        }
    }

    return acumPisitivos;
}
// PUNTO 5
int sumaDeMatriz(int mtrz[][10], int fila){
    int acum=0;

    for (int j=0; j<10; j++) {
        for (int i=0; i<fila ; i++) {
        acum+=mtrz[i][j];
        }
    }

    return acum;
}

int main () {

    system("pause");
    return 0;
}