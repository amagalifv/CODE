#ifndef FUNCCLI_H_INCLUDED
#define FUNCCLI_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "prototipos.h"
#include "clsCliente.h"

//----FUNCIONES CLIENTES------------------------

/*Muestra toda la información de una archivo*/
void listarClientes(){
  Cliente cli;
  int i=0;

  while (cli.leerDeDisco(i)==1) {
    if (cli.getEstado()==true) {
        cli.Mostrar();
    }
    i++;
  }
}

/*
-2 error de apertura;
-1 no encontrado;
- si no posición
*/
int buscarPosDni(int dni){
    Cliente cli;
    int i=0;

    while (cli.leerDeDisco(i)==1) {

        if (cli.getDni()==dni && cli.getEstado()==true) {
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
int darDeBaja (int dni){
    Cliente cli;
    int pos,modif;

    pos=buscarPosDni(dni);
    if (pos>=0) {
        cli.leerDeDisco(pos);
        cli.setEstado(false);
        modif=cli.modificarDeDisco(pos);
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
int cambiarFecha(int dni){
    int pos,modif;
    Cliente cli;
    Fecha fecha;

    pos=buscarPosDni(dni);
    if (pos>=0) {

        cli.leerDeDisco(pos);
        fecha.Cargar();
        cli.setFechaNac(fecha);
        modif=cli.modificarDeDisco(pos);
        return modif;
    } else {
        return -1;
    }
}

// vuelve a true todos los estados
void restaurarEliminados(){
    Cliente clie;
    int pos=0;

    while (clie.leerDeDisco(pos)==1) {
        if (clie.getEstado()==false) {
            clie.setEstado(true);
            clie.modificarDeDisco(pos);
        }
        pos++;
    }
}

//----MENU CLIENTES------------------------------

int menuClientes () {
    Cliente obj;
    int opc, aux, devol,pos;
    bool cargo;

    while(true){
        cout<<"------------------MENU------------------\n";
        cout<<"OPCION 1: AGREGAR CLIENTE               \n";
        cout<<"OPCION 2: LISTAR CLIENTE POR DNI        \n";
        cout<<"OPCION 3: LISTAR TODOS LOS CLIENTES     \n";
        cout<<"OPCION 4: MODIFICAR FECHA DE NACIMIENTO \n";
        cout<<"OPCION 5: ELIMINAR CLIENTE              \n";
        cout<<"OPCION 0: VOLVER AL MENU PRINCIPAL      \n";
        cout<<"----------------------------------------\n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cout<<"INGRESE EL DNI: ";
                cin>>aux;

                if (buscarPosDni(aux)==-1) {
                    obj.Cargar(aux);
                    cargo=obj.grabarEnDisco();
                    if (cargo==true) {
                        cout<<"Registro Agregado";
                    }else{cout<<"Registro NO agregado";}
                }else{
                    cout<<"EL DNI INGRESADO YA EXISTE";
                    return false;
                }

                break;
            case 2:
                cout<<"Ingrese el dni del cliente: "<<endl;
                cin>>aux;
                pos=buscarPosDni(aux);
                if (pos<0) {
                    cout<<"Cliente NO encontrado"<<endl;
                }else{
                    obj.leerDeDisco(pos);
                    if (obj.getEstado()==true) {
                        obj.Mostrar();
                    }else{
                        cout<<"Cliente dado de BAJA"<<endl;
                    }
                }
                break;
            case 3:
                listarClientes();
                break;
            case 4:
                cout<<"Ingrese el dni del cliente para cambiar la fecha de nacimiento: "<<endl;
                cin>>aux;
                devol=cambiarFecha(aux);
                if (devol==-1) { cout<<"Registro NO encontrado";}
                else if (devol==0) {cout<<"Error de modificacion";}
                else if (devol==1) {cout<<"Fecha de nacimiento modificada!";}
                break;
            case 5:
                cout<<"Ingrese el dni del cliente a eliminar: "<<endl;
                cin>>aux;
                devol=darDeBaja(aux);
                if (devol==-1) { cout<<"Registro NO encontrado";}
                else if (devol==0) {cout<<"Error de modificacion";}
                else if (devol==1) {cout<<"Cliente dado de baja";}
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

#endif // FUNCCLI_H_INCLUDED
