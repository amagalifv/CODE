#ifndef PARCIAL_FERNANDEZVILCHEZ_H_INCLUDED
#define PARCIAL_FERNANDEZVILCHEZ_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#include "prototipos.h"
#include "clsVentas.h"
#include "funcVent.h"

const char *AR_CLIENTESIMPORTESALTOS="Datos/clientesimportes.dat";

/*Informar cuál es número de venta de menor importe del artículo "ABCD".*/
void menorVentaABCD (){
    Venta ven;
    int i=0;
    float min=0;
    int minId;
    bool primeraEntrada=true;

    while (ven.leerDeDisco(i)==1) {

        if (strcmp(ven.getCodigo(), "ABCD")==0) {

            if (primeraEntrada==true) {
                min=ven.getImporte();
                minId=ven.getId();
                primeraEntrada=false;
            }

            if (ven.getImporte()<min) {
                min=ven.getImporte();
                minId=ven.getId();
            }
        }
        i++;
    }

    if (primeraEntrada==true) { //es porque nunca entró y no hay articulos ABCD
        cout<<"No hay ningun articulo vendido de codigo ABCD"<<endl;
    } else {
        cout<<"El ID de venta de menor importe del articulo ABCD es "<<minId<<" y su importe es $"<<min<<endl;
    }
}

/*El mes de mayor recaudación por ventas del artículo de código "WS25", en el año pasado.*/

void mesMayorRecaudacionWS25(){
    Venta ven;
    int i=0;
    float vMeses[12]={0};
    string vNombres[12]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","noviembre","diciembre"};
    float max;
    int mesMax;
    bool band=true;

    while (ven.leerDeDisco(i)==1) {
        if (strcmp(ven.getCodigo(), "WS25")==0 && ven.getFechaNac().getAnio()==2021) {
            vMeses[ven.getFechaNac().getMes()-1]+=ven.getImporte();
            band=false; // es para msj final por si no hay ventas de este articulo
        }
        i++;
    }

    max=vMeses[0];
    mesMax=0;
    for (int j=1; j<12; j++) {
        if (max<vMeses[j]) {
            max=vMeses[j];
            mesMax=j;
        }
    }

    if (band==true) {
        cout<<"No hay ninguna venta de articulo con codigo WS25"<<endl;
    } else{
        cout<<"El mes del 2021 de mayor recaudacion es "<<vNombres[mesMax]<<" y el importe recaudado es $"<<max<<endl;
    }
}

/*Generar un archivo con los clientes que hayan comprado por un importe mayor o igual a $ 50.000 en una sola compra este año.

El archivo debe tener el mismo formato de registro que el archivo de clientes.
*/

bool generarArchivoVentasImportesAltos(){
    Venta ven;
    int i=0;
    int posCli;
    Cliente cli;


    while (ven.leerDeDisco(i)==1) {

        if (ven.getImporte()>=50000 && ven.getFechaNac().getAnio()==2022) {

            posCli=buscarPosDni(ven.getDni());
            if (posCli>-1) {
                cli.leerDeDisco(posCli);
                cli.grabarEnDisco(AR_CLIENTESIMPORTESALTOS);
            } else {return false;}
        }

        i++;
    }

    return true;
}

int menuParcial () {
    int opc;
    bool band;

    while(true){
        cout<<"--------------MENÚ CONFIGURACIÓN---------------\n";
        cout<<endl;
        cout<<"1) PUNTO 1                                     \n";
        cout<<"1) PUNTO 2                                     \n";
        cout<<"1) PUNTO 3                                     \n";
        cout<<"---------------------------------------------- \n";
        cout<<"0) VOLVER AL MENÚ PRINCIPAL                    \n";

        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                menorVentaABCD ();
                break;
            case 2:
                mesMayorRecaudacionWS25();
                break;
            case 3:
                band=generarArchivoVentasImportesAltos();
                if (band ==true) {
                    cout<<"Archivo creado con exito!"<<endl;
                } else {cout<<"Error! "<<endl;}
                break;
            default:
                return 0;
                break;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }


    system("pause");
    return 0;
}

#endif // PARCIAL_FERNANDEZVILCHEZ_H_INCLUDED
