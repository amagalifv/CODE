#include <iostream>
using namespace std;

#define MAX_IT 15
#define MAX_FACS 30
#define MAX_CONSOL 90

typedef struct{
    short int dia;
    short int mes;
    int anio;
}ST_FECHA;

typedef struct{
    long int nroFact;
    ST_FECHA fecha;
    string nombreC;
    long int cuit;
    float total;
    ST_ITEM items[MAX_IT];
}ST_FACTURA;

typedef struct{
    short int id;
    string descrip;
    short int cantidad;
    float precioUni;
}ST_ITEM;

typedef struct{
    int fecha; //ST_FECHA
    float monto;
}ST_LISTADO;

void apareoVectores(ST_FACTURA sucursal1[MAX_FACS], ST_FACTURA sucursal2[MAX_FACS], int dimension1, int dimension2, ST_FACTURA tercera[MAX_FACS],int &dimension3);

int fechaConsolidado(ST_FECHA fecha);

int main () {
    ST_FACTURA sucursal1[MAX_FACS];
    ST_FACTURA sucursal2[MAX_FACS];
    ST_FACTURA sucursal3[MAX_FACS];
    ST_FACTURA aux [MAX_FACS*2];
    int dimensionAux=0;
    ST_FACTURA consol [MAX_FACS*3];
    int dimensionCons=0;

    apareoVectores(sucursal1, sucursal2, 30, 30, aux, dimensionAux);
    apareoVectores(aux , sucursal3, dimensionAux, 30, consol, dimensionCons);

    system("pause");
    return 0;
}

void apareoVectores(ST_FACTURA sucursal1[MAX_FACS], ST_FACTURA sucursal2[MAX_FACS], int dimension1, int dimension2, ST_FACTURA tercera[MAX_FACS],int &dimension3 ){
    int i = 0, j = 0;
    int k = 0;
    int fecha1, fecha2;


    while (i < dimension1 && j < dimension2) {

        fecha1=fechaConsolidado(sucursal1[i].fecha);
        fecha2=fechaConsolidado(sucursal2[j].fecha);

        if (fecha1 < fecha2) {

            tercera[k] = sucursal1[i];
            i++;
            
        } else {
            tercera[k] = sucursal2[j];
            j++;
        }

        k++;
        
    }

    while(i < dimension1) {
        tercera[k] = sucursal1[i];
        i++;
        k++;
    }

    while(j < dimension2) {
        tercera[k] = sucursal2[j];
        j++;
        k++;
    }

    dimension3=k;
}

int fechaConsolidado( ST_FECHA fecha){
    return fecha.anio*10000+fecha.mes*100+fecha.dia;
}