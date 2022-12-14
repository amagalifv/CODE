#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
# include<cstring>
using namespace std;

//#include "funcCategoria.h"
#include "clsMovimiento.h"
//#include "funcNombreServicio.h"

/* LISTA TODOS LOS MOVIMIENTOS */
void listarMovimientos(){
    Movimiento mov;
    int i=0, j=0;

    while(mov.leerDeDisco(i)==1){
        if (mov.getEstado()==true) {
            mov.Mostrar();
            j++;
        }
        i++;
    }
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
    }else{cout<<"Error! No se encontr� el servicio indicado"<<endl;}
}

int modificarRegistro(int id){
    int opc;
    Movimiento mov;
    Fecha fecha;
    int auxI;
    float auxF;
    char resp;
    int devol;
    bool bandera=false;

    mov.leerDeDisco(id-1);

    cout<<"      ¿QUE DESEA MODIFICAR?    \n";
    cout<<"1) FECHA DE MOVIMIENTO         \n";
    cout<<"2) IMPORTE DE MOVIMIENTO       \n";
    cout<<"3) CATEGORIA DE MOVIMIENTO     \n";
    cout<<"4) SI ES GASTO FIJO            \n";
    cout<<"-------------------------------\n";

    cin>>opc;
    system("cls");

    switch(opc){

        case 1:
            fecha.Cargar();
            mov.setFecha(fecha);
            bandera=true;
            break;
        case 2:
            cout<<"INGRESE EL IMPORTE A MODIFICAR: ";
            cin>>auxF;
            mov.setImporte(auxF);
            bandera=true;
            break;
        case 3:
            cout<<"INGRESE LA CATEGORIA DESEADA: ";
            cin>>auxI;
            if(buscarCategoriaCodigo(auxI)!=-1){
                mov.setCategoria(auxI);
                bandera=true;
            }
            cout<<"Esa categoria no existe. Proceso cancelado."<<endl;
            break;
        case 4:
            cout<<"ES UN GASTO FIJO (S PARA SI Y N PARA NO): ";
            cin>>resp;
            if (resp=='s' || resp=='S') mov.setSiGastoFijo(true);
            else mov.setSiGastoFijo(false);
            bandera=true;
            break;
        default:
            break;
    }
    if(bandera){
        devol=mov.modificarDeDisco(id-1);
    }
    else{
        devol=-1;
    }

    return devol;
}

bool siCategoriaValida(int cate){
    int pos;

    pos=buscarCategoriaCodigo(cate);

    if (pos>=0) {
        return true;
    }

    return false;
}

int menuMovimientos(){
    int opc, id, devol;
    Movimiento obj;
    int cod=0;

    while(true){
        cout<<"************************************\n";
        cout<<"          MENU MOVIMIENTOS          \n";
        cout<<"************************************\n";
        cout<<"      1) INGRESAR MOVIMIENTO        \n";
        cout<<"      2) MODIFICAR MOVIMIENTO       \n";
        cout<<"      3) BORRAR MOVIMIENTO          \n";
        cout<<"      4) LISTAR MOVIMIENTOS         \n";
        cout<<"      5) AGREGAR SERVICIO           \n";
        cout<<"      6) MODIFICAR SERVICIO         \n";
        cout<<"      7) LISTAR TODOS LOS SERVICIOS \n";
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
                    cout<<"Registro agregado exitosamente!\n";
                }else{cout<<"Error\n";}
                break;
            case 2:
                cout<<"INGRESE EL ID DEL MOVIMIENTO A MODIFICAR: ";
                cin>>id;
                if(buscarPorIdMov(id)!=-1){
                    devol=modificarRegistro(id);
                }
                else{
                    cout<<"El id ingresado no existe. Proceso cancelado."<<endl;
                    system("pause");
                    return 0;
                }
                if (devol==1) {
                    cout<<"El registro se modificó exitosamente!\n";
                }else{cout<<"Error\n";}
                break;
            case 3:
                cout<<"INGRESE EL ID DEL MOVIMIENTO A BORRAR: ";
                cin>>id;
                devol=bajaLogica(id);
                if (devol==1) {
                    cout<<"El registro se dió de baja exitosamente!\n";
                }else{cout<<"Error\n";}
                break;
            case 4:
                listarMovimientos();
                break;
            //5. AGREGAR SERVICIO
            case 5: agregarNombreServicio();
                break;

            //6. MODIFICAR SERVICIO
            case 6: mensajesListados("MODIFICAR SERVICIO");
                cout<<"\nSe emitir� un listado con los servicios activos: ";
                listarNombreServiciosAcotado();
                cout<<"\nIngrese el codigo del servicio a modificar: ";
                cin>>cod;
                if(cod==0){
                    cout<<"Operaci�n cancelada"<<endl;
                    return 0;
                }
                mensajeOperacion(modificarNombreServicio(cod));
                break;

            //7. LISTAR TODOS LOS SERVICIOS
            case 7: listarNombreServicios();
                break;

            default:
                return 0;
                break;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }

    //system("pause");
    return 0;
}

#endif // MOVIMIENTO_H_INCLUDED
