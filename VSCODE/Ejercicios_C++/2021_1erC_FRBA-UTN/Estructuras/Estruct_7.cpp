#include <iostream>
using namespace std;

#define MAX_ALU 1000

typedef struct {
 int nroLegajo;
 int codMateria;
 int diaExamen;
 int mesExamen;
 int anioExamen;
 string apellido;
} ST_REG;

typedef struct {
 int nroLegajo;
 string apellido;
} ST_LISTADO;

void cargarVectorPUP (ST_REG registro[], int dimensionR, ST_LISTADO listaOrd[],int dimListaO) {
    int inicial=80001;
    int clave;

    for (int i = 0; i < dimensionR; i++) {
        clave=registro[i].nroLegajo-inicial;

        listaOrd[clave].nroLegajo=registro[i].nroLegajo;
        listaOrd[clave].apellido=registro[i].apellido;
    }

    return;
}

int main () {
    ST_REG registro[MAX_ALU];
    int dimensionR=200;
    ST_LISTADO listaOrd[99];
    int dimListaO=99;

    cargarVectorPUP(registro, dimensionR, listaOrd, dimListaO);
 
    system("pause");
    return 0;
}