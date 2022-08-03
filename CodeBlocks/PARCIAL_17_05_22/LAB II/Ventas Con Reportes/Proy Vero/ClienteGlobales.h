#ifndef CLIENTEGLOBALES_H_INCLUDED
#define CLIENTEGLOBALES_H_INCLUDED

#include "Fecha.h"
#include "Cliente.h"

using namespace std;

///PROTOTIPOS FUNCIONES GLOBALES
int menuClientes();

int buscarClientePorDni(int dniCliente);
void listarClientePorDni();
void listarTodosLosClientes();
void agregarcliente();
void modificarFechaNacimiento();
void eliminarCliente();
void cargaMasivaClientesInicio();
///FIN PROTOTIPOS FUNCIONES GLOBALES

///FUNCIONES GLOBALES CLIENTE
int menuClientes(){
    int opc=0;

    cout<<"**** MENU CLIENTES ****"<<endl<<endl;
    cout<<"1. AGREGAR CLIENTE"<<endl;
    cout<<"2. LISTAR CLIENTE POR DNI"<<endl;
    cout<<"3. LISTAR TODOS LOS CLIENTES"<<endl;
    cout<<"4. MODIFICAR FECHA DE NACIMIENTO"<<endl;
    cout<<"5. ELIMINAR CLIENTE"<<endl;
    cout<<"****************************"<<endl;
    cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"SELECCIONES UNA DE LAS OPCIONES: ";
    cin>>opc;
    system("cls");

    switch (opc){
            //1. AGREGAR CLIENTE
        case 1: agregarcliente();
            system("pause");
            break;

            //2. LISTAR CLIENTE POR DNI
        case 2: listarClientePorDni();
            system("pause");
            break;

            //3. TODOS LOS CLIENTES
        case 3: listarTodosLosClientes();
            system("pause");
            break;

            //4. MODIFICAR FECHA DE NACIMIENTO
        case 4: modificarFechaNacimiento();
            system("pause");
            break;

            //5. ELIMINAR CLIENTE
        case 5: eliminarCliente();
            system("pause");
            break;

        default:
            return 0;
            break;
    }
    cout<<endl;
    system("pause");
    system("cls");
}
int buscarClientePorDni(int dniCliente){
    /******************************************
     Valores que retorna buscarArticuloPorCodigo():
     -1: NO ENCONTRÓ EL ARTICULO
      CUALQUIER OTRO: LO ENCONTRO Y DEVUELVE LA POSICION
    ******************************************/

    Cliente reg;
    int posDisco=0;

    while(reg.leerDeDisco(posDisco)==1){
        if(reg.getEstado()){
            if(reg.getDni()==dniCliente){
                return posDisco;
            }
        }
        posDisco++;
    }

    posDisco=-1;
    return posDisco;
}
void listarClientePorDni(){
    Cliente reg;
    int posDisco;
    int auxInt=0;

    cout<<"DNI A BUSCAR: ";
    cin>>auxInt;
    cout<<endl;

    posDisco=buscarClientePorDni(auxInt);

    if(posDisco!=-1){
        cout<<"***** CLIENTE ENCONTRADO *****"<<endl;
        reg.leerDeDisco(posDisco);
        reg.Mostrar();
    }
    else{
        cout<<"El cliente no existe."<<endl;
    }
}
void listarTodosLosClientes(){
    Cliente reg;
    int posDisco=0;
    int contador=0;

    cout<<"***** LISTADO DE CLIENTES *****"<<endl<<endl;

    while(reg.leerDeDisco(posDisco)==1){
        if(reg.getEstado()){
            reg.Mostrar();
            contador++;
        }
        posDisco++;
    }

    cout<<"Total "<<contador<< " clientes."<<endl;
}
void agregarcliente(){
    Cliente reg;
    int posDisco;
    int auxInt=0;

    cout<<"DNI (0 para cancelar): ";
    cin>>auxInt;

    if(auxInt==0){
        cout<<"Operacion cancelada."<<endl;
        return;
    }

    posDisco=buscarClientePorDni(auxInt);

    if(posDisco==-1){
        reg.Cargar(auxInt);
        if(reg.grabarEnDisco(posDisco)==1){
            cout<<"Cliente agregado!"<<endl<<endl;
        }
    }
    else{
        reg.leerDeDisco(posDisco);
        if(!reg.getEstado()){
            char respuesta;
            cout<<"El cliente ya existe pero estaba inhabilitado, desea reactivarlo? (S: si, N: no): ";
            cin>>respuesta;

            if(respuesta=='s' || respuesta=='S'){
                reg.setEstado(1);
                if(reg.grabarEnDisco(posDisco)==1){
                    cout<<"Cliente reactivado correctamente"<<endl;
                }
                else{
                    cout<<"El cliente no pudo reactivarse"<<endl;
                }
            }
        }
        else{
            cout<<"No se puede agregar, el dni de ese cliente ya existe."<<endl;
        }
    }
}
void modificarFechaNacimiento(){
    Cliente reg;
    int posDisco=0;
    int auxInt;
    Fecha auxFecha;

    cout<<"DNI DEL CLIENTE (0 para cancelar): ";
    cin>>auxInt;

    if(auxInt==0){
        cout<<"Operacion cancelada."<<endl;
        return;
    }

    posDisco=buscarClientePorDni(auxInt);

    if(posDisco==-1){
        cout<<"No existe el cliente, ingrese nuevo dni: ";
    }
    else{
        reg.leerDeDisco(posDisco);

        cout<<"**** CLIENTE A MODIFICAR ****"<<endl;
        reg.Mostrar();
        cout<<"******************************"<<endl<<endl;

        cout<<"INDIQUE LA NUEVA FECHA DE NACIMIENTO: "<<endl;
        auxFecha.CargarNacimiento();

        reg.setFechaNac(auxFecha);

        if(reg.grabarEnDisco(posDisco)==1){
            cout<<"Actualizacion de fecha exitosa!"<<endl;
        }
        else{
            cout<<"No se pudo modificar la fecha de nacimiento."<<endl;
        }
    }
}
void eliminarCliente(){
    Cliente reg;
    int posDisco=0;
    int auxInt=0;

    cout<<"Indique el dni del cliente a eliminar (0 para cancelar): ";
    cin>>auxInt;

    if(auxInt==0){
        cout<<"Operacion cancelada."<<endl;
        return;
    }

    posDisco=buscarClientePorDni(auxInt);

    if(posDisco!=-1){
        char respuesta;
        cout<<"**** DATOS DEL CLIENTE A BORRAR ****"<<endl;
        reg.leerDeDisco(posDisco);
        reg.Mostrar();
        cout<<"******************************"<<endl<<endl;

        cout<<"Esta seguro? (S: si - N: no): ";
        cin>>respuesta;
        if(respuesta=='s' || respuesta=='S'){
            reg.setEstado(0);
            reg.grabarEnDisco(posDisco);
            cout<<"Registro eliminado."<<endl;
        }
        else{
            cout<<"Operacion cancelada."<<endl;
        }
    }
    else{
        cout<<"El cliente no existe."<<endl;
    }
}
void cargaMasivaClientesInicio(){
    Cliente reg;
    int posDisco=-1;
    int auxInt=0;

    cout<<"DNI:  ";
    cin>>auxInt;

    while(auxInt!=-9){
        reg.Cargar(auxInt);
        if(reg.grabarEnDisco(posDisco)==1){
            cout<<"Cliente agregado!"<<endl<<endl;
        }

        cout<<"DNI:  ";
        cin>>auxInt;
    }
}
///FIN FUNCIONES GLOBALES CLIENTE

#endif // CLIENTEGLOBALES_H_INCLUDED
