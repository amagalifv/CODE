#ifndef REPORTEGLOBALES_H_INCLUDED
#define REPORTEGLOBALES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "ClienteGlobales.h"
#include "Venta.h"

using namespace std;

///PROTOTIPOS DE FUNCIONES GLOBALES DE LA CLASE REPORTES
void menuReportes();
void totalVentasPorCliente();
void listarActivosEInactivos();
///FIN PROTOTIPOS DE FUNCIONES GLOBALES DE LA CLASE REPORTES

///FUNCIONES GLOBALES DE LA CLASE REPORTES
void menuReportes(){
    int opc=0;

    cout<<"**** MENU REPORTES ****"<<endl<<endl;
    cout<<"1. MOSTRAR POR CADA CLIENTE LA CANTIDAD DE VENTAS REGISTRADAS A ESE CLIENTE"<<endl;
    cout<<"2. INFORMAR LA CANTIDAD DE CLIENTES ACTIVOS Y LA CANTIDAD DE CLIENTES INACTIVOS"<<endl;
    cout<<"****************************"<<endl;
    cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"SELECCIONES UNA DE LAS OPCIONES: ";
    cin>>opc;
    system("cls");

    switch (opc){
        //1. MOSTRAR TOTAL DE VENTAS POR CADA CLIENTE
        case 1: totalVentasPorCliente();
            system("pause");
            break;

        //2. LISTAR CANTIDAD CLIENTES ACTIVOS E INACTIVOS
        case 2: listarActivosEInactivos();
            system("pause");
            break;

        case 0: return;

        default:
            break;
    }

}
void totalVentasPorCliente(){
    int arrayVentasPorCliente[100]={0};     //ver si sirve este metodo para cargar clientes, si hay un m�ximo
                                            //para as� ver si puedo definir un array
    Cliente regCliente;
    int posDiscoCliente=0;
    Venta regVenta;
    int posDiscoVenta=0;
    int dniCliente=0;

    //busco en el archivo clientes el dni, obtengo la posicion, y uso esa posicion para guardar
    //dentro del array clientes
    while(regVenta.leerDeDisco(posDiscoVenta)==1){
        dniCliente=regVenta.getDniCliente();
        posDiscoCliente = buscarClientePorDni(dniCliente);
        arrayVentasPorCliente[posDiscoCliente]++;
        posDiscoVenta++;
    }

    cout<<"Cliente"<<"\t"<<"Cant Oper"<<endl;
    for(int i=0; i<100; i++){
        regCliente.leerDeDisco(i);
        dniCliente=regCliente.getDni();
        posDiscoCliente = buscarClientePorDni(dniCliente);

        if(arrayVentasPorCliente[i]>=1){
            cout<<"  "<<dniCliente<<"\t"<<"   "<<arrayVentasPorCliente[posDiscoCliente]<<endl;
        }
    }
}
void listarActivosEInactivos(){
    Cliente reg;
    int posDisco=0;
    int activos=0;
    int inactivos=0;

    while(reg.leerDeDisco(posDisco)==1){
        if(reg.getEstado()){
            activos++;
        }
        posDisco++;
    }

    posDisco=0;

    while(reg.leerDeDisco(posDisco)==1){
        if(!reg.getEstado()){
            inactivos++;
        }
        posDisco++;
    }

    cout<<"**** CLIENTES ****"<<endl;
    cout<<"ACTIVOS"<<"\t"<<"INACTIVOS"<<endl;
    cout<<"   "<<activos<<"\t"<<"   "<<inactivos<<endl<<endl;
}
///FIN FUNCIONES GLOBALES DE LA CLASE REPORTES
#endif // REPORTEGLOBALES_H_INCLUDED
