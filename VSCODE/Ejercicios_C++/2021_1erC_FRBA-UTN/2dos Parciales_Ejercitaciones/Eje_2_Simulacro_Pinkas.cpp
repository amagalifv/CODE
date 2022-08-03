#include <iostream>
using namespace std;

#define MAX 100
#define MAX_S 50

typedef struct{
    string nombre;
    int codGusto;
}ST_GUSTO;

typedef struct{
    int hora;
    int codGusto;
    int cant;
}ST_VENTA;

typedef struct{
    string gusto;
    int consumoTot;
}ST_CONSUMO;

void apareo (ST_VENTA sucur1[MAX], int dime1, ST_VENTA sucur2[MAX], int dime2, ST_VENTA sucurConsol[MAX], int &dimeConsol){
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < dime1 && j < dime2) {

        if (sucur1[i].hora < sucur2[j].hora) {

            sucurConsol[k] = sucur1[i];
            i++;
            
        } else {
            sucurConsol[k] = sucur2[j];
            j++;
        }

        k++;
    }

    while(i < dime1) {
        sucurConsol[k] = sucur1[i];
        i++;
        k++;
    }

    while(j < dime2) {
        sucurConsol[k] = sucur2[j];
        j++;
        k++;
    }

    dimeConsol=k;

    return;
}

float calcularFactur (ST_VENTA sucurConsol[MAX], int dimeConsol) {
    float factur;

    for (int i = 0; i < dimeConsol; i++) {

        if (sucurConsol[i].hora<180000){
            factur+=sucurConsol[i].cant*(300/1000); 
            //la cantidad de la venta se ingresa en gramos
        }else{
            factur+=sucurConsol[i].cant*(400/1000);
        }
    }

    return factur;
}

void ordenarPorGusto( ST_VENTA sucurConsol[MAX], int dimeConsol){
    int j=0;
    ST_VENTA aux;
    int i=0;
    bool ordenado = false;

    while (i < dimeConsol && !ordenado){
        ordenado= true; 

        for (int j = 0; j < dimeConsol-i-1 ; j++){
            if (sucurConsol[j].codGusto>sucurConsol[j+1].codGusto){
                aux = sucurConsol[j];
                sucurConsol[j]=sucurConsol[j+1];
                sucurConsol[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }

    return;
}

void corteControl (ST_VENTA sucurConsol[MAX], int dimeConsol, ST_GUSTO gustos[MAX_S], ST_CONSUMO consumos[MAX],int &dimeConsumo) {
    int i = 0;
    int k = 0;
    float contador = 0;
    int key;

    while(i < dimeConsol) {

        key = sucurConsol[i].codGusto;

        contador = 0;

        while(i < dimeConsol && key == sucurConsol[i].codGusto) {

            contador+=sucurConsol[i].cant;
            
            i++; 
        }

        consumos[k].consumoTot=contador;
        consumos[k].gusto= gustos[sucurConsol[i].codGusto-1].nombre;
        k++;
    }
    dimeConsumo=k;

    return;
}

void ordenarPorConsumo(ST_CONSUMO consumos[MAX_S], int dimeConsumo){
    int j=0;
    ST_CONSUMO aux;
    int i=0;
    bool ordenado = false;

    while (i < dimeConsumo && !ordenado){
        ordenado= true; 

        for (int j = 0; j < dimeConsumo-i-1 ; j++){
            if (consumos[j].consumoTot>consumos[j+1].consumoTot){
                aux = consumos[j];
                consumos[j]=consumos[j+1];
                consumos[j+1]=aux;
                ordenado = false;
            }
        }
        i++;
    }

    return;
}

void imprimir (ST_CONSUMO consumos[MAX_S], int dimeConsumo) {
    float aux=0;
    
    for (int i = 0; i < dimeConsumo; i++) {
        
        aux=(consumos[i].consumoTot)/1000;
        cout<<consumos[i].gusto<<"\t\t"<<aux<<" kg"<<endl;
        cout<<endl;

        aux=0;
    }

    return;
}

int main () {
    ST_GUSTO gustos[MAX_S];
    ST_VENTA sucur1[MAX]={{121403,12,100},{121403,3,150},{130112,12,200}};
    ST_VENTA sucur2[MAX]={{111101,3,98},{164510,11,110},{173114,24,112}};
    ST_VENTA sucurConsol[MAX];
    int dime1=3;
    int dime2=3;
    int dimeConsol;
    float facturacion=0;
    ST_CONSUMO consumos[MAX_S];
    int dimeConsumo;

    // ------------------------PUNTO A------------------------
    apareo(sucur1,dime1,sucur2,dime2,sucurConsol,dimeConsol); 


    // ------------------------PUNTO B------------------------
    facturacion=calcularFactur(sucurConsol, dimeConsol);
    cout << "La facturacion es "<<facturacion<<endl;

    // ------------------------PUNTO C------------------------
    ordenarPorGusto(sucurConsol, dimeConsol);
    corteControl(sucurConsol, dimeConsol,gustos,consumos,dimeConsumo);
    ordenarPorConsumo(consumos,dimeConsumo);
    imprimir(consumos,dimeConsumo);

    system("pause");
    return 0;
}