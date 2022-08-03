#include <iostream>
using namespace std;

#define MAX_F 12
#define MAX_C 31
#define MAX_P 100

typedef struct{
    int fecha;
    int codProd;
    int cantidad;
}ST_VENTA;

typedef struct{
    int codProd;
    string nombreProd;
    double precioUnit;
    int cantTotal;
}ST_PRODUCTO;

void ordenarPorCodProd (ST_PRODUCTO productos[MAX_P]) {



    return;
}

int busquedaBinaria (ST_PRODUCTO productos[MAX_P], int valor) {



    return -1;
}

void mayorFacturacion (ST_VENTA ventas2020 [MAX_F][MAX_C], ST_PRODUCTO productos[MAX_P]) {
    float contadorMes;
    float mesMax=0;
    int iMesMax=0;
    int pos;


    for (int i = 0; i < MAX_F; i++) {
    
        for (int j = 0; j < MAX_C; j++) {
        
            pos=busquedaBinaria(productos, ventas2020[i][j].codProd);

            if (pos>-1){
                contadorMes+=ventas2020[i][j].cantidad*productos[pos].precioUnit;
            }
            
        }

        if (contadorMes>mesMax){
            mesMax=contadorMes;
            iMesMax=i;
        }
        
    }

    cout<<"El mes de mas facturacion es "<<iMesMax+1<<endl;

    return;
}

void menosVendido (ST_VENTA ventas2020 [MAX_F][MAX_C], ST_PRODUCTO productos[MAX_P]) {
    int pos;

    for (int i = 0; i < MAX_F; i++) {
    
        for (int j = 0; j < MAX_C; j++) {
        
            pos=busquedaBinaria(productos, ventas2020[i][j].codProd);

            if (pos>-1){
                productos[pos].cantTotal+=ventas2020[i][j].cantidad;
            }
        
        }
    
    }

    return;
}

void ordenarCantTot (ST_PRODUCTO productos[MAX_P]) {



    return;
}

int main () {
    ST_VENTA ventas2020 [MAX_F][MAX_C];
    ST_PRODUCTO productos[MAX_P];//NO BUSQUEDA SECUENCIAL ACA//DESORDENADO


 
    system("pause");
    return 0;
}