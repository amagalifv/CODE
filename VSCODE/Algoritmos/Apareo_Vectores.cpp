#include <iostream>
using namespace std;

//SOLO PARA VECTORES YA ORDENADOS ANTES DEL APAREO (MERGE)

void apareo(int vecA[], int n, int vecB[], int m, int vecC[], int &k) {
    int i = 0, j = 0;
    int k = 0;

    while (i < n && j < m) {

        if (vecA[i] < vecB[j]) {

            vecC[k] = vecA[i];
            i++;
            
        } else {
            vecC[k] = vecB[j];
            j++;
        }

        k++;
    }

    while(i < n) {
        vecC[k] = vecA[i];
        i++;
        k++;
    }

    while(j < m) {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
}

int main () {


 
 system("pause");
 return 0;
}

// SI ES CON ESTRUCTURAS (ordenado por nro codigo)
typedef struct{
    int codigo;
    string nombre;
} ST_ESTRUCTURA;

void apareo(ST_ESTRUCTURA vecA[], int n, ST_ESTRUCTURA vecB[], int m, ST_ESTRUCTURA vecC[], int &k) {
    int i = 0, j = 0;
    int k = 0;

    while (i < n && j < m) {

        if (vecA[i].codigo < vecB[j].codigo) {

            vecC[k] = vecA[i];
            i++;
            
        } else {
            vecC[k] = vecB[j];
            j++;
        }

        k++;
    }

    while(i < n) {
        vecC[k] = vecA[i];
        i++;
        k++;
    }

    while(j < m) {
        vecC[k] = vecB[j];
        j++;
        k++;
    }
}