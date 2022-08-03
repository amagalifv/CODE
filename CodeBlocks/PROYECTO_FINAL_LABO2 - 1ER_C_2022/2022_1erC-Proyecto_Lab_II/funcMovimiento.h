#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
# include<cstring>
using namespace std;

#include "clsMovimiento.h"
#include "funcCategoria.h"

/* LISTA TODOS LOS MOVIMIENTOS */
void listarMovimientos(){
    Movimiento mov;
    int i=0, j=0;
    //Movimiento *vMov;
    //int tam;

    while(mov.leerDeDisco(i)==1){
        if (mov.getEstado()==true) {
            mov.Mostrar();
            j++;
        }
        i++;
    }
    //tam=j;

    /*vMov=new Movimiento[tam];
    for (int i=0; i<tam; i++) {

    }*/
    cout<<"\n\nTotal Movimientos: "<<j<<endl;
}

/************************************
retorna pos de servicio en arch mov_Servicios
-1 si no lo encuentra
*************************************/
int buscarPorIdMov (int &id) {
    int i=0;
    Movimiento mov;

    while (mov.leerDeDisco(i)==1) {
        if (mov.getId()==id) {
            return i;
        }
        i++;
    }
    return -1;
}

/*
-1 registro no encontrado
0 si no pudo modificar
1 si cambió el archivo correctamente
*/
int bajaLogica(int id){
    Movimiento mov;
    int modif, pos;

    pos=buscarPorIdMov(id);
    if (pos>=0){
        mov.leerDeDisco(pos);
        mov.setEstado(false);
        modif=mov.modificarDeDisco(pos);
        return modif;
    }
    return -1;
}

/*Se llama desde clsMovimiento en Cargar si es == a categoria 7*/
void mostrarServicio(int id){
    MovimientoServicio serv;
    int pos;

    pos=buscarPorIdServ(id);
    if (pos!=-1) {
        serv.leerDeDisco(pos);
        serv.Mostrar();
    }else{cout<<"\nError! No se encontró el servicio indicado\n"<<endl;}
}

int modificarRegistro(int id){
    int opc;
    Movimiento mov;
    Fecha fecha;
    int auxI;
    float auxF;
    char resp;
    int devol;

    mov.leerDeDisco(id);

    cout<<"\n      ¿QUE DESEA MODIFICAR?    \n";
    cout<<"1) FECHA DE MOVIMIENTO         \n";
    cout<<"2) IMPORTE DE MOVIMIENTO       \n";
    cout<<"3) CATEGORIA DE MOVIMIENTO     \n";
    cout<<"4) SI ES GASTO FIJO            \n";
    cout<<"-------------------------------\n\n";

    cin>>opc;
    system("cls");

    switch(opc){

        case 1:
            fecha.Cargar();
            mov.setFecha(fecha);
            break;
        case 2:
            cout<<"INGRESE EL IMPORTE A MODIFICAR: ";
            cin>>auxF;
            mov.setImporte(auxF);
            break;
        case 3:
            cout<<"INGRESE LA CATEGORIA DESEADA: ";
            cin>>auxI;
            mov.setCategoria(auxI);
            break;
        case 4:
            cout<<"ES UN GASTO FIJO (S PARA SI Y N PARA NO): ";
            cin>>resp;
            if (resp=='s' || resp=='S') mov.setSiGastoFijo(true);
            else mov.setSiGastoFijo(false);
            break;
        default:
            break;
    }
    devol=mov.modificarDeDisco(id);

    return devol;
}

bool siCategoriaValida(int cate){
    int pos;

    pos=buscarCategoria(cate);

    if (pos>=0) {
        return true;
    }

    return false;
}

int menuMovimientos(){
    int opc, id, devol;
    Movimiento obj;

    while(true){
        cout<<"\n************************************\n";
        cout<<"          MENU MOVIMIENTOS          \n";
        cout<<"************************************\n";
        cout<<"      1) INGRESAR MOVIMIENTO        \n";
        cout<<"      2) MODIFICAR MOVIMIENTO       \n";
        cout<<"      3) BORRAR MOVIMIENTO          \n";
        cout<<"      4) LISTAR MOVIMIENTOS         \n";
        cout<<"************************************\n";
        cout<<"      0) IR A MENU PRINCIPAL        \n";
        cout<<"************************************\n";
        cout<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                obj.Cargar();
                if (obj.grabarEnDisco()==1){
                    cout<<"\nRegistro agregado exitosamente!\n";
                }else{cout<<"Error\n";}
                break;
            case 2:
                cout<<"\nINGRESE EL ID DEL MOVIMIENTO A MODIFICAR: ";
                cin>>id;
                modificarRegistro(id);
                break;
            case 3:
                cout<<"\nINGRESE EL ID DEL MOVIMIENTO A BORRAR: ";
                cin>>id;
                devol=bajaLogica(id);
                if (devol==1) {
                    cout<<"\nEl registro se dió de baja exitosamente!\n";
                }else{cout<<"Error\n";}
                break;
            case 4:
                listarMovimientos();
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

#endif // MOVIMIENTO_H_INCLUDED
