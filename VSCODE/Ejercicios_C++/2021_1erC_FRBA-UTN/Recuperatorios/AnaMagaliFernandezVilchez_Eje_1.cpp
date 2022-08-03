#include <iostream>
using namespace std;

#define MAX_S 4
#define MAX_ART 20

typedef struct{
    int codArt;
    int codSucursal;
    string TipoMovim;
    int cantidad;
}ST_LISTADO;

void ordenarPorSucursal(ST_LISTADO listadoMesActual[],int dime);

void ActualizarStock (int stockInicial[MAX_ART][MAX_S],ST_LISTADO listadoMesActual[], int dime) {
    int k=0;
    int aux=0;

    ordenarPorSucursal(listadoMesActual, dime);

    for (int i = 0; i < MAX_S; i++) {
        
        for (int j = 0; j < MAX_ART; j++) {
            

            if (listadoMesActual[k].TipoMovim=="entrada"){
                stockInicial[j][i]=stockInicial[j][i]+listadoMesActual[k].cantidad;
            }else{
                if (listadoMesActual[k].TipoMovim=="salida"){
                   stockInicial[j][i]=stockInicial[j][i]-listadoMesActual[k].cantidad; 
                }  
            }
            
            k++;
        }
    }


    return;
}

// no llegue a terminar

int main () {
    int stockInicial[MAX_ART][MAX_S];
    ST_LISTADO listadoMesActual[MAX_ART];



 
    system("pause");
    return 0;
}