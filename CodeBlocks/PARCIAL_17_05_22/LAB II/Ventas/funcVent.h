#ifndef FUNCVENT_H_INCLUDED
#define FUNCVENT_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "prototipos.h"
#include "clsFecha.h"
#include "clsArticulo.h"
#include "clsVentas.h"


//----FUNCIONES VENTAS---------------------------
float calcularImporte(int cant, int pos){
    Articulo arti;
    int auxP;

    arti.leerDeDisco(pos);
    auxP=arti.getPrecio();
    auxP=auxP*(float)cant;

    return auxP;
}

/*
-2 error de apertura;
-1 no encontrado;
*/
int buscarPosVent(int ide){
    FILE *pVent;
    Venta vent;
    int devol=1;
    int i=0;

    pVent=fopen(AR_VENTAS,"rb");
    if (pVent==NULL){return -2;}

    while (devol==1) {
        devol=fread(&vent ,sizeof(Venta),1,pVent);

        if (vent.getId()==ide && vent.getEstado()==true ) {
            return i;
            fclose(pVent);
        }
        i++;
    }
    fclose(pVent);
    return -1;
}
//lista todas las ventas
void listarVentas(){
    Venta vent;
    int i=0;

    while (vent.leerDeDisco(i)==1) {
        if (vent.getEstado()==true) {
            vent.Mostrar();
        }
        i++;
    }
}

/*
-1 registro no encontrado
0 si no pudo modificar no hay suficiente stock
1 si cambió el archivo correctamente
*/
int cambiarStockEnVenta( int cantActualizar, int id){
    int  pos;
    Venta vent;
    bool siModfEnArt;

    pos=buscarPosVent(id);
    if (pos>=0) {
        vent.leerDeDisco(pos);
        siModfEnArt=modificarStockEnArt(vent.getCantidad(),vent.getCodigo(), cantActualizar);

        if (siModfEnArt==true) {
            vent.setCantidad(cantActualizar);
            vent.modificarDeDisco(pos);
            return 1;
        }
        return 0;
    }
    return -1;
}

//----MENU VENTAS--------------------------------

int menuVentas(){
    Venta obj;
    bool cargo;
    int opc, pos;
    int cant, id, aux;

    while(true){
        cout<<"          MENU VENTAS           \n";
        cout<<"--------------------------------\n";
        cout<<endl;
        cout<<"1) AGREGAR VENTA                \n";
        cout<<"2) LISTAR VENTA POR ID          \n";
        cout<<"3) LISTAR TODAS LAS VENTAS      \n";
        cout<<"4) MODIFICAR CANTIDAD           \n";
        cout<<"--------------------------------\n";
        cout<<"0) VOLVER AL MENU PRINCIPAL     \n";

        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cargo=obj.grabarEnDisco();
                if (cargo==true) {
                    cout<<"Registro Agregado";
                }else{cout<<"Registro NO agregado";}
                break;
            case 2:
                cout<<"Ingrese el ID de la venta: "<<endl;
                cin>>id;
                pos=buscarPosVent(id);
                if (pos<0) {
                    cout<<"Venta NO encontrada"<<endl;
                }else{
                    obj.leerDeDisco(pos);
                    if (obj.getEstado()==true) {
                        obj.Mostrar();
                    }
                }
                break;
            case 3:
                listarVentas();
                break;
            case 4:
                cout<<"Ingrese el ID de la venta: "<<endl;
                cin>>id;
                cout<<"Ingrese la cantidad a modificar: "<<endl;
                cin>>cant;
                aux=cambiarStockEnVenta(cant,id);
                if (aux == 1) {
                    cout<<"Operacion Exitosa";
                }else if (aux == 0) {
                    cout<<"Sin stock suficiente para la operacion";
                }else{
                    cout<<"Error, registro no encontrado";
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

#endif // FUNCVENT_H_INCLUDED
