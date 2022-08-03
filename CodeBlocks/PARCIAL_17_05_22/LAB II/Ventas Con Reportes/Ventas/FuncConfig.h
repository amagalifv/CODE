#ifndef FUNCCONFIG_H_INCLUDED
#define FUNCCONFIG_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "prototipos.h"
#include "clsCliente.h"
#include "clsArticulo.h"
#include "clsVentas.h"

/*hace backUp de Clientes*/
bool moverArchivoObjClientes(const char*origen, const char*destino){
    FILE *pCli;

    pCli=fopen(destino, "wb");
    if(pCli==NULL){return false;}

    Cliente cli;
    int pos=0;

    while (cli.leerDeDisco(pos, origen)==1){
        fwrite(&cli, sizeof cli, 1 , pCli);
        pos++;
    }
    fclose(pCli);

    return true;
}

/*hace backUp de Articulos*/
bool moverArchivoObjArticulos(const char*origen, const char*destino){
    FILE *pArti;

    pArti=fopen(destino, "wb");
    if(pArti==NULL){return false;}

    Articulo arti;
    int pos=0;

    while (arti.leerDeDisco(pos, origen)==1){
        fwrite(&arti, sizeof arti, 1 , pArti);
        pos++;
    }
    fclose(pArti);

    return true;
}

/*hace backUp de Ventas*/
bool moverArchivoObjVentas(const char*origen, const char*destino){
    FILE *pVent;

    pVent=fopen(destino, "wb");
    if(pVent==NULL){return false;}

    Venta vent;
    int pos=0;

    while (vent.leerDeDisco(pos, origen)==1){
        fwrite(&vent, sizeof vent, 1 , pVent);
        pos++;
    }
    fclose(pVent);

    return true;
}


int menuConfiguracion () {
    int opc;
    bool cargo, cargo1, cargo2;

    while(true){
        cout<<"--------------MENÚ CONFIGURACIÓN---------------\n";
        cout<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE CLIENTES  \n";
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE ARTICULOS \n";
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS    \n";
        cout<<"4) RESTAURAR EL ARCHIVO DE CLIENTES            \n";
        cout<<"5) RESTAURAR EL ARCHIVO DE ARTICULOS           \n";
        cout<<"6) RESTAURAR EL ARCHIVO DE VENTAS              \n";
        cout<<"7) ESTABLECER DATOS DE INICIO                  \n";
        cout<<"---------------------------------------------- \n";
        cout<<"0) VOLVER AL MENÚ PRINCIPAL                    \n";

        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cargo=moverArchivoObjClientes(AR_CLIENTES, BK_CLIENTES);
                if (cargo==true) {
                    cout<<"back Up exitoso";
                }else{
                    cout<<"Error de backUp";
                }
                break;
            case 2:
                cargo=moverArchivoObjArticulos(AR_ARTICULOS, BK_ARTICULOS);
                if (cargo==true) {
                    cout<<"back Up exitoso";
                }else{
                    cout<<"Error de backUp";
                }
                break;
            case 3:
                cargo=moverArchivoObjVentas(AR_VENTAS, BK_VENTAS);
                if (cargo==true) {
                    cout<<"back Up exitoso";
                }else{
                    cout<<"Error de backUp";
                }
                break;
            case 4:
                cargo=moverArchivoObjClientes(BK_CLIENTES, AR_CLIENTES);
                if (cargo==true) {
                    cout<<"Restauracion exitoso";
                }else{
                    cout<<"Error de Restauracion";
                }
                break;
            case 5:
                cargo=moverArchivoObjArticulos(BK_ARTICULOS, AR_ARTICULOS);
                if (cargo==true) {
                    cout<<"Restauracion exitoso";
                }else{
                    cout<<"Error de Restauracion";
                }
                break;
            case 6:
                cargo=moverArchivoObjVentas(BK_VENTAS, AR_VENTAS);
                if (cargo==true) {
                    cout<<"Restauracion exitoso";
                }else{
                    cout<<"Error de Restauracion";
                }
                break;
            case 7:
                cargo=moverArchivoObjClientes(INI_CLIENTES, AR_CLIENTES);
                cargo1=moverArchivoObjArticulos(INI_ARTICULOS, AR_ARTICULOS);
                cargo2=moverArchivoObjVentas(INI_VENTAS, AR_VENTAS);
                if (cargo==true&& cargo1==true&&cargo2==true) {
                    cout<<"Restauracion valores de inicio exitosa";
                }else{
                    cout<<"Error de restauracion valores de inicio";
                }
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

#endif // FUNCCONFIG_H_INCLUDED
