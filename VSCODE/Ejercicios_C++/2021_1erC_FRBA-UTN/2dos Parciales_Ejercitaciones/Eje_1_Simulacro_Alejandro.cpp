#include <iostream>
using namespace std;

#define MAX_ITEM 15
#define MAX_FACTS 100

typedef struct{
    long int idFactura;
    short int dia;
    short int mes;
}ST_FECHA;

typedef struct{
    short int id;
    string descrip;
    short int cant;
    float precioUnit;
}ST_ITEM;

typedef struct{
    ST_FECHA fecha;
    string nombreCli;
    long int nroCli;
    ST_ITEM items[MAX_ITEM];
    float totalFac;
}ST_FACTURA;

typedef struct{
    ST_FECHA fecha;
    float totalDia;
}ST_LISTA;

float calcularTotFact(ST_ITEM items[MAX_ITEM], int dimI){
    int sumTot=0;
    
    for (int i = 0; i < dimI; i++) {
      sumTot+=items[i].precioUnit*items[i].cant;
    }

    return sumTot;
}

void cargarDatos(ST_FACTURA facturas1[MAX_FACTS], int dim1){

    facturas1[0]={{1,5,2021},"Pepe",0506,{{1,"polea",2,3},{2,"volante",1,4}},0};
    facturas1[0].totalFac=calcularTotFact(facturas1[0].items,2);

    facturas1[1]={{3,5,2021},"Carlos",0510,{{1,"polea",4,3},{2,"volante",2,4}},0};
    facturas1[1].totalFac=calcularTotFact(facturas1[1].items,2);

    facturas1[2]={{2,5,2021},"Juan",0507,{{1,"polea",6,3},{2,"volante",3,4}},0};
    facturas1[2].totalFac=calcularTotFact(facturas1[2].items,2);

    return;
}

void ordenarPorDia (ST_FACTURA facturas[MAX_FACTS], int dim1) {
    int j=0;
    ST_FACTURA aux;
    int i=0;
    bool ordenado = false;

    while (i < dim1 && !ordenado){
        ordenado= true;
        
        for (int j = 0; j < dim1-i-1 ; j++){
            if (facturas[j].fecha.dia>facturas[j+1].fecha.dia){
                aux = facturas[j];
                facturas[j]=facturas[j+1];
                facturas[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }

    return;
}

void apareo (ST_FACTURA facturas1[MAX_FACTS], int dim1, ST_FACTURA facturas2[MAX_FACTS], int dim2, ST_FACTURA facturasX[MAX_FACTS*2],int &dimX) {

    int i = 0, j = 0;
    int k = 0;

    while (i < dim1 && j < dim2) {

        if (facturas1[i].fecha.dia < facturas2[j].fecha.dia) {

            facturasX[k] = facturas1[i];
            i++;
            
        } else {
            facturasX[k] = facturas2[j];
            j++;
        }

        k++;
    }

    while(i < dim1) {
        facturasX[k] = facturas1[i];
        i++;
        k++;
    }

    while(j < dim2) {
        facturasX[k] = facturas2[j];
        j++;
        k++;
    }
    dimX=k;

    return;
}

void corteDeCont (ST_FACTURA facturasFin[MAX_FACTS*3],int dimFin,ST_LISTA totales[MAX_FACTS*3], int &dimLista) {
    int i = 0;
    int j = 0;
    int contTot = 0;
    int key;

    while(i < dimFin) {

        key = facturasFin[i].fecha.dia;

        contTot = 0;

        while(i < dimFin && key == facturasFin[i].fecha.dia) {

            contTot+=facturasFin[i].totalFac;
            
            i++; 
        }
        
        totales[j].totalDia=contTot;
        totales[j].fecha=facturasFin[i].fecha;
        j++;
    }
    dimLista=j;

    return;
}

void ordenarPorMonto (ST_LISTA totales[MAX_FACTS*3], int dimLista) {
    int j=0;
    ST_LISTA aux;
    int i=0;
    bool ordenado = false;

    while (i < dimLista && !ordenado){
        ordenado= true;

        for (int j = 0; j < dimLista-i-1 ; j++){
            if (totales[j].totalDia > totales[j+1].totalDia){
                aux = totales[j];
                totales[j]=totales[j+1];
                totales[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }

    return;
}

void imprimirLista (ST_LISTA totales[MAX_FACTS*3], int dimLista) {
    
    cout<<"Dia \t\t Monto \t\t"<<endl;
    for (int i = 0; i < dimLista; i++) {
        cout<< totales[i].fecha.dia <<"\t\t"<<totales[i].totalDia<<endl;
    }

    return;
}

int main () {
    ST_ITEM items[MAX_ITEM];
    ST_FACTURA facturas1[MAX_FACTS];
    ST_FACTURA facturas2[MAX_FACTS];
    ST_FACTURA facturasX[MAX_FACTS*2];
    ST_FACTURA facturas3[MAX_FACTS];
    ST_FACTURA facturasFin[MAX_FACTS*3];
    ST_LISTA totales[MAX_FACTS];
    int dim1;
    int dim2;
    int dim3;
    int dimX;
    int dimFin;
    int dimLista;

    //Cargar de datos de las 3 sucursales

    ordenarPorDia(facturas1,dim1);
    ordenarPorDia(facturas2,dim2);
    ordenarPorDia(facturas3,dim3);

    apareo(facturas1,dim1,facturas2,dim2,facturasX,dimX);
    apareo(facturasX,dimX,facturas3,dim3,facturasFin,dimFin);

    corteDeCont(facturasFin,dimFin,totales,dimLista);

    ordenarPorMonto(totales,dimLista);

    imprimirLista(totales,dimLista);
 
    system("pause");
    return 0;
}