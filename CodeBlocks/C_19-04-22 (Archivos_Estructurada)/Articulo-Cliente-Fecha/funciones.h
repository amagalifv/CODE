#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "clsArticulo.h"
#include "clsFecha.h"
#include "clsCliente.h"

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}


void menuArticulo(){
    Articulo art[10];
    int opc,aux;
    bool ent=true;

    while(ent){
        cout<<"-----------------MENU-----------------\n";
        cout<<"OPCION 1: CARGAR 10 ARTICULOS         \n";
        cout<<"OPCION 2: LISTAR TODOS LOS ARTICULOS  \n";
        cout<<"OPCION 3: BUSCAR POSICION DE ARTICULO \n";
        cout<<"OPCION 4: LISTAR STOCKS INFERIORES A  \n";
        cout<<"OPCION 5: MODIFICAR PRECIOS           \n";
        cout<<"OPCION 0: EXIT                        \n";
        cout<<"--------------------------------------\n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cargarDiezArts(art,3);
                break;
            case 2:
                mostrarArts(art,3);
                break;
            case 3:
                char cod[5];
                cout<<"Ingrese el codigo a buscar: ";
                cargarCadena(cod,4);
                aux=buscarCodigo(art,3,cod);
                if (aux!=-1) {
                    cout<<"El codigo se encontro en la posicion "<<aux<<endl;
                } else {cout<<"Codigo no encontrado"<<endl;}
                break;
            case 4:
                cout<<"Ingrese el stock a buscar: ";
                cin>>aux;
                cout<<"---------Productos-Con-Stock-Menor---------\n";
                buscarStockMenor(art,3,aux);
                break;
            case 5:
                cout<<"Ingrese el porcentaje a incrementar(Ej:10): ";
                cin>>aux;
                actualizarPrecio(art,3,aux);
                break;
            default:
                ent=false;
                break;
        }
    }
}

void menuCliente(){
    Cliente cli;
    Fecha fecha;
    int opc,aux,devol;
    bool ent=true;
    bool cargo;

    while(ent){
        cout<<"------------------------MENU-----------------------\n";
        cout<<"OPCION 1: CARGAR 1 CLIENTE EN ARCHIVO              \n";
        cout<<"OPCION 2: LISTAR TODOS LOS CLIENTES                \n";
        cout<<"OPCION 3: LISTAR DNI MAYORES A                     \n";
        cout<<"OPCION 4: BUSCAR CLIENTE POR DNI                   \n";
        cout<<"OPCION 5: BUSCAR CLIENTES CON FECHA NAC ANTERIOR A \n";
        cout<<"OPCION 0: EXIT                                     \n";
        cout<<"---------------------------------------------------\n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cargo=cargarEnArchivoCli();
                if (cargo==true) {
                    cout<<"Registro Agregado";
                }else{cout<<"Registro NO agregado";}
                break;
            case 2:
                mostrarClientesDeArchivo();
                break;
            case 3:
                cout<<"Ingrese el dni para listar mayores: ";
                cin>>aux;
                cout<<"---------DNIs-MAYORES---------\n";
                listarDniMayores(aux);
                break;
            case 4:
                cout<<"Ingrese dni a buscar: ";
                cin>>aux;
                devol=buscarPosDni(aux);
                if (devol==-1) {
                    cout<<" DNI NO ENCONTRADO \n";
                }else{cout<<"El DNI está en la posicion: "<<devol+1<<" \n";}
                break;
            case 5:
                cout<<"-------FECHA DE NAC A BUSCAR (mayores)-------"<<endl;
                fecha.Cargar();
                listarMenores(fecha);
                break;
            default:
                ent=false;
                break;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }
}

#endif // FUNCIONES_H_INCLUDED
