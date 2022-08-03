#ifndef FUNCART_H_INCLUDED
#define FUNCART_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "prototipos.h"
#include "clsArticulo.h"


//----FUNCIONES ARTICULOS------------------------

/*
-2 error de apertura;
-1 no encontrado;
- si no posición
*/
int buscarPosArt(const char *cod){
    Articulo arti;
    int i=0;

    while (arti.leerDeDisco(i)==1) {

        if (strcmp(arti.getCodigo(),cod)==0 && arti.getEstado()==true) {
            return i;
        }
        i++;
    }
    return -1;
}

/*Muestra toda la información de una archivo*/
void listarArticulos(){
    Articulo arti;
    int i=0;

    while (arti.leerDeDisco(i)==1) {
        if (arti.getEstado()==true) {
            arti.Mostrar();
        }
        i++;
    }
}

/*
-1 registro no encontrado
0 si no pudo modificar
1 si cambió el archivo correctamente
*/
int cambiarPrecio(const char *cod){
    int pos,modif;
    Articulo arti;
    float prec;

    pos=buscarPosArt(cod);
    if (pos>=0) {
        cout<<"Ingrese nuevo precio: "<<endl;
        cin>>prec;

        arti.leerDeDisco(pos);
        arti.setPrecio(prec);
        modif=arti.modificarDeDisco(pos);
        return modif;
    } else {
        return -1;
    }
}

/*
-1 registro no encontrado
0 si no pudo modificar
1 si cambió el archivo correctamente
*/
int darDeBajaArt(char cod[5]){
    Articulo arti;
    int pos,modif;

    pos=buscarPosArt(cod);
    if (pos>=0) {
        arti.leerDeDisco(pos);
        arti.setEstado(false);
        modif=arti.modificarDeDisco(pos);
        return modif;
    } else {
        return -1;
    }
}

bool siStock(int stockVendido, int pos){
    Articulo arti;

    arti.leerDeDisco(pos);
    if (arti.getStock()>=stockVendido) {
        return true;
    }
    return false;
}

void actualizarStock( int cant, int pos){
    int aux;
    Articulo arti;

    arti.leerDeDisco(pos);

    aux=arti.getStock();

    aux=aux-cant;

    arti.setStock(aux);

    arti.modificarDeDisco(pos);

}

float modificarStockEnArt(int cantAnterior, const char *codigoArt, int cantActualizar){
    int aux=0, aux2=0, pos;
    Articulo arti;

    pos=buscarPosArt(codigoArt);

    arti.leerDeDisco(pos);

    aux=arti.getStock()+cantAnterior;

    arti.setStock(aux);//DEVOLVi lo q saqué por error

    if (arti.getStock()>=cantActualizar) {
        aux2=arti.getStock()-cantActualizar;
        arti.setStock(aux2);// le saco lo comprado
        arti.modificarDeDisco(pos);
        return arti.getPrecio();
    }
    return -1;
}

//----MENU ARTICULOS-----------------------------
int menuArticulos(){
    Articulo obj;
    int opc, devol,pos;
    bool cargo;
    char aux[5];

    while(true){
        cout<<"        MENU ARTICULOS          \n";
        cout<<"--------------------------------\n";
        cout<<endl;
        cout<<"1) AGREGAR ARTICULO             \n";
        cout<<"2) LISTAR ARTICULO POR CODIGO   \n";
        cout<<"3) LISTAR TODOS LOS ARTICULOS   \n";
        cout<<"4) MODIFICAR PRECIO             \n";
        cout<<"5) ELIMINAR ARTICULO            \n";
        cout<<"--------------------------------\n";
        cout<<"0) VOLVER AL MENU PRINCIPAL     \n";

        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cout<<"INGRESE EL CODIGO: ";
                cargarCadena(aux, 4);

                if (buscarPosArt(aux)==-1) {
                    obj.Cargar(aux);
                    cargo=obj.grabarEnDisco();
                    if (cargo==true) {
                        cout<<"Registro Agregado";
                    }else{cout<<"Registro NO agregado";}

                }else{
                    cout<<"EL DNI INGRESADO YA EXISTE";
                }

                break;
            case 2:
                cout<<"Ingrese el Codigo del Articulo: "<<endl;
                cargarCadena(aux, 4);
                pos=buscarPosArt(aux);
                if (pos<0) {
                    cout<<"Articulo NO encontrado"<<endl;
                }else{
                    obj.leerDeDisco(pos);
                    if (obj.getEstado()==true) {
                        obj.Mostrar();
                    }else{
                        cout<<"Articulo dado de BAJA"<<endl;
                    }
                }
                break;
            case 3:
                listarArticulos();
                break;
            case 4:
                cout<<"Ingrese el el codigo del articulo para cambiar el precio: "<<endl;
                cargarCadena(aux, 4);
                devol=cambiarPrecio(aux);
                if (devol==-1) { cout<<"Registro NO encontrado";}
                else if (devol==0) {cout<<"Error de modificacion";}
                else if (devol==1) {cout<<"Precio modificado!";}
                break;
            case 5:
                cout<<"Ingrese el codigo del articulo a eliminar: "<<endl;
                cargarCadena(aux, 4);
                devol=darDeBajaArt(aux);
                if (devol==-1) { cout<<"Registro NO encontrado";}
                else if (devol==0) {cout<<"Error de modificacion";}
                else if (devol==1) {cout<<"Articulo dado de baja";}
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

#endif // FUNCART_H_INCLUDED
