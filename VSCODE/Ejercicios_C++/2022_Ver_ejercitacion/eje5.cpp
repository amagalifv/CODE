#include <iostream>
#include <cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

void impRacau(float m[3][31]){
    cout<<"\n\n-------------------------------------------------------------------\n";
    for (int i = 0; i < 3; i++) {
        cout<<"Para el PAIS "<<i+1<<" se lista la racaudación por dia: \n\n";

        for (int j = 0; j < 31; j++) {

            if (m[i][j]!=0){
                cout<<"Dia "<<j+1<<": $"<<m[i][j]<<" de racaudacion\n";
            }
        }
    }
}

void impSinRacau(float m[3][31]){
    int cant=0;
    cout<<"\n\n-------------------------------------------------------------------\n";

    for (int i = 0; i < 3; i++) {
        cout<<"Para el PAIS "<<i+1<<": \n\n";

        for (int j = 0; j < 31; j++) {

            if (m[i][j]==0){
                cant++;
            }
        }
        cout<<"Cantidad de dias sin recaudacion: "<<cant<<"\n";
        cant=0;
    }
}

void impSinRacauEntrePaises(float m[3][31]){
    int cant=0;
    cout<<"\n\n-------------------------------------------------------------------\n";
    cout<<"Se lista los dias SIN recaudacion en los 3 paises: \n\n";

    for (int i = 0; i < 31; i++) {

        for (int j = 0; j < 3; j++) {

            if (m[j][i]==0){
                cant++;
            }
        }
        if (cant==3) {
            cout<<"Dia "<<i+1<<endl;
        }
        cant=0;
    }
}


int main () {
    float matrV[3][31]{};
    int pais;
    int dia;
    float venta;

    while (pais!=-1) {

        cout<<"Ingrese el dia: "<<endl;
        cin>>dia;
        cout<<"Ingrese el monto de la venta: "<<endl;
        cin>>venta;

        matrV[pais-1][dia-1]+=venta;

        cout<<"Ingrese el país: "<<endl;
        cin>>pais;
    }

    //---------A---------
    impRacau(matrV);

    //---------B---------
    impSinRacau(matrV);

    //---------C---------
    impSinRacauEntrePaises(matrV);

    system("pause");
    return 0;
}

/*
Una tienda online dispone de todas las ventas realizadas el mes pasado en los tres paises donde comercializa. Por cada venta registra:
-numero de pais (1a3)
-dia de venta (1a31)
-monto de la venta(float)

Para indicar el fin de la carga de informacion se ingresa un numero de pais igual a -1. La informacion NO se encuentra agrupada ni ordenada bajo ningun criterio.

Se pide informar:
A)Por cada pais y dia el total recaudado. Solo mostrar informacion de aquellos dias en los que hubo recaudacion
B)Por cada pais, la cantidad de dias en los que no hubo recaudacion.
C)Los numeros de dia en los que no hubo recaudacion en ninguno de los paises
*/

/*
void cargarValor(float v[], int pais,int dia, float venta){
    dia--;

    if (dia<31) {
        v[dia]+=venta;
    }

    return;
}

void imprimirDiasRecau(float v[], int num){

    cout<<"Ventas del pais "<<num<<":\n\n";

    for (int i=0; i<31; i++) {

        if (v[i]!=0) {
            cout<<"Dia "<<i+1<<": "<<v[i]<<"\n";
        }
    }
}

void imprimirDiasSinRacau(float v[], int num){

    cout<<"Ventas del pais "<<num<<":\n\n";

    for (int i=0; i<31; i++) {

        if (v[i]==0) {
            cout<<"Dia "<<i+1<<": "<<v[i]<<" ventas\n";
        }
    }
}

void diasSinRacau (float v1[], float v2[],float v3[]){

    for (int i=0; i<31; i++) {

        if (v1[i]==0 && v2[i]==0 && v3[i]==0) {
            cout<<"Dia "<<i+1<<" no hubo ventas en ninguno de los 3 paises\n";
        }
    }
}

int main () {

    float vector1[31]{};//notacion para inicializar en 0
    float vector2[31]{};
    float vector3[31]{};
    int pais;
    int dia;
    float venta;

    cout<<"Ingrese el país: "<<endl;
    cin>>pais;

    while (pais!=-1) {

        cout<<"Ingrese el dia: "<<endl;
        cin>>dia;
        cout<<"Ingrese el monto de la venta: "<<endl;
        cin>>venta;

        switch (pais) {
            case 1 :
                cargarValor(vector1,pais,dia,venta);
                break;

            case 2 :
                cargarValor(vector2,pais,dia,venta);
                break;

            case 3 :
                cargarValor(vector3,pais,dia,venta);
                break;

            default:
                break;
        }

        cout<<"Ingrese el país: "<<endl;
        cin>>pais;
    }

    // PUNTO A
    imprimirDiasRecau(vector1,1);
    imprimirDiasRecau(vector2,2);
    imprimirDiasRecau(vector3,3);

    // PUNTO B
    imprimirDiasSinRacau(vector1,1);
    imprimirDiasSinRacau(vector2,2);
    imprimirDiasSinRacau(vector3,3);

    // PUNTO C
    diasSinRacau(vector1,vector2,vector3);


    system("pause");
    return 0;
}
*/
