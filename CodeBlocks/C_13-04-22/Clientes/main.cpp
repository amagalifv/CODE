#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "prototipos.h"
#include "clsFecha.h"
#include "clsCliente.h"
#include "funciones.h"

int main () {
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
                //cargo=cargarEnArchivoCli();
                if (cargo==true) {
                    cout<<"Registro Agregado";
                }else{cout<<"Registro NO agregado";}
                break;
            case 2:
                //mostrarClientesDeArchivo();
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

    system("pause");
    return 0;
}