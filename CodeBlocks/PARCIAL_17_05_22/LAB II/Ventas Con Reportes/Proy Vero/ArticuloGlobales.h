#ifndef ARTICULOGLOBALES_H_INCLUDED
#define ARTICULOGLOBALES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Articulo.h"
#include "funciones.h"

using namespace std;

///PROTOTIPOS FUNCIONES GLOBALES
int menuArticulos();

void listarArticuloPorCodigo();
void listarTodosLosArticulos();
int buscarArticuloPorCodigoSinRestricciones(const char *codigo);
int buscarArticuloPorCodigo(const char *codigo);
void agregarArticulo();
void modificarPrecio();
void eliminarArticulo();
int actualizarStock(int cantidad, const char *codigo);
void cargaMasivaArticulosInicio();
///FIN PROTOTIPOS GLOBALES

///FUNCIONES GLOBALES
int menuArticulos(){
    int opc=0;

    cout<<"**** MENU ARTICULOS ****"<<endl<<endl;
    cout<<"1. AGREGAR ARTICULO"<<endl;
    cout<<"2. LISTAR ARTICULO POR CODIGO"<<endl;
    cout<<"3. LISTAR TODOS LOS ARTICULOS"<<endl;
    cout<<"4. MODIFICAR PRECIO"<<endl;
    cout<<"5. ELIMINAR ARTICULO"<<endl;
    cout<<"****************************"<<endl;
    cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"SELECCIONES UNA DE LAS OPCIONES: ";
    cin>>opc;
    system("cls");

    switch (opc){
            //1. AGREGAR ARTICULO"
        case 1: agregarArticulo();
            system("pause");
            break;

            //2. LISTAR ARTICULO POR CODIGO
        case 2: listarArticuloPorCodigo();
            system("pause");
            break;

            //3. LISTAR TODOS LOS ARTICULOS
        case 3: listarTodosLosArticulos();
            system("pause");
            break;

            //4. MODIFICAR PRECIO"
        case 4: modificarPrecio();
            system("pause");
            break;

            //5. ELIMINAR ARTICULO
        case 5: eliminarArticulo();
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
int buscarArticuloPorCodigoSinRestricciones(const char *codigo){
    /******************************************
     Valores que retorna buscarArticuloPorCodigo(const char *codigo):
     -1: NO ENCONTRÓ EL ARTICULO
     OTRO: ES LA POSICION DEL ARTICULO ENCONTRADO
    ******************************************/

    Articulo reg;
    int posDisco=0;

    while(reg.leerDeDisco(posDisco)==1){
        if(strcmp(reg.getCodigo(),codigo)==0){
            return posDisco;
        }
        posDisco++;
    }

    posDisco=-1;
    return posDisco;
}
int buscarArticuloPorCodigo(const char *auxChar){
    /******************************************
     Valores que retorna buscarArticuloPorCodigo():
     -1: NO ENCONTRÓ EL ARTICULO
      CUALQUIER OTRO: LO ENCONTRO Y DEVUELVE LA POSICION
    ******************************************/

    Articulo reg;
    int posDisco=0;

    while(reg.leerDeDisco(posDisco)==1){
        if(reg.getEstado()){
            if(strcmp(reg.getCodigo(),auxChar)==0){
                return posDisco;
            }
        }
        posDisco++;
    }

    posDisco=-1;
    return posDisco;
}
void listarArticuloPorCodigo(){
    Articulo reg;
    int posDisco;
    char auxChar[5]={0};

    cout<<"Indique el código de artículo a buscar: ";
    cargarCadena(auxChar,5);
    cout<<endl;

    posDisco=buscarArticuloPorCodigo(auxChar);

    if(posDisco!=-1){
        cout<<"***** ARTICULO ENCONTRADO *****"<<endl;
        reg.leerDeDisco(posDisco);
        reg.Mostrar();
    }
    else{
        cout<<"El articulo no existe."<<endl;
    }
}
void listarTodosLosArticulos(){
    Articulo reg;
    int posDisco=0;
    int contador=0;

cout<<"**** LISTADO DE ARTICULOS ****"<<endl<<endl;

    while(reg.leerDeDisco(posDisco)==1){
        if(reg.getEstado()){
            reg.Mostrar();
            contador++;
        }
        posDisco++;
    }

    cout<<"Total "<<contador<< " articulos."<<endl;
}
void agregarArticulo(){
    Articulo reg;
    int posDisco;
    char aux[5]={0};

    cout<<"CODIGO (máximo 4 dígitos / FIN para cancelar): ";
    cargarCadena(aux,5);

    if(strcmp(aux,"FIN")==0){
        cout<<"Operacion cancelada."<<endl;
        return;
    }

    posDisco=buscarArticuloPorCodigoSinRestricciones(aux);

    if(posDisco==-1){
        reg.Cargar(aux);
        if(reg.grabarEnDisco(posDisco)==1){
            cout<<"Articulo agregado!"<<endl<<endl;
        }
    }
    else{
        reg.leerDeDisco(posDisco);
        if(!reg.getEstado()){
            char respuesta;
            cout<<"El articulo ya existe pero estaba inhabilitado, desea reactivarlo? (S: si, N: no): ";
            cin>>respuesta;

            if(respuesta=='s' || respuesta=='S'){
                reg.setEstado(1);
                if(reg.grabarEnDisco(posDisco)==1){
                    cout<<"Articulo reactivado correctamente"<<endl;
                }
                else{
                    cout<<"El articulo no pudo reactivarse"<<endl;
                }
            }
        }
        else{
            cout<<"No se puede agregar, el código de ese artículo ya existe."<<endl;
        }
    }
}
void modificarPrecio(){
    Articulo reg;
    int posDisco=0;
    char auxChar[5]={0};
    float auxFloat=0;

    cout<<"Indique el código del articulo a modificar (FIN para cancelar): ";
    cargarCadena(auxChar,5);

    if(strcmp(auxChar,"FIN")==0){
        cout<<"Operacion cancelada."<<endl;
        return;
    }

    posDisco=buscarArticuloPorCodigo(auxChar);

    if(posDisco==-1){
        cout<<"El artículo no existe"<<endl;
    }
    else{
        reg.leerDeDisco(posDisco);

        cout<<"**** ARTICULO A MODIFICAR ****"<<endl;
        reg.Mostrar();
        cout<<"******************************"<<endl<<endl;

        cout<<"Indique el nuevo precio: $";
        cin>>auxFloat;

        reg.setPrecio(auxFloat);

        if(reg.grabarEnDisco(posDisco)==1){
            cout<<"Actualizacion de precio exitosa!"<<endl;
        }
        else{
            cout<<"No se pudo modificar el precio"<<endl;
        }
    }
}
void eliminarArticulo(){
    Articulo reg;
    int posDisco=0;
    char auxChar[5]={0};

    cout<<"Indique el código del articulo a eliminar (FIN para cancelar): ";
    cargarCadena(auxChar,5);

    if(strcmp(auxChar,"FIN")==0){
        cout<<"Operacion cancelada."<<endl;
        return;
    }

    posDisco=buscarArticuloPorCodigo(auxChar);

    if(posDisco!=-1){
        char respuesta;
        cout<<"**** DATOS DEL ARTICULO A BORRAR ****"<<endl;
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
        cout<<"El articulo no existe."<<endl;
    }
}
int actualizarStock(int cantidad, const char *codigo){
    Articulo reg;
    int posDisco=0;
    int okCambio=-1;

    posDisco=buscarArticuloPorCodigo(codigo);

    if(posDisco!=-1){
        reg.leerDeDisco(posDisco);
        reg.setStock(reg.getStock()-cantidad);
        if(reg.grabarEnDisco(posDisco)==1){
            okCambio=1;
        }
        else{
            okCambio=-1;
        }
    }
    return okCambio;
}
void cargaMasivaArticulosInicio(){
    Articulo reg;
    int posDisco=-1;
    char aux[5]={0};

    cout<<"CODIGO (máximo 4 dígitos): ";
    cargarCadena(aux,5);

    while(strcmp(aux,"nada")==-1 || strcmp(aux,"nada")==1){
        reg.Cargar(aux);
        if(reg.grabarEnDisco(posDisco)==1){
            cout<<"Articulo agregado!"<<endl<<endl;
        }

        cout<<"CODIGO (máximo 4 dígitos): ";
        cargarCadena(aux,5);
    }
}
///FIN FUNCIONES GLOBALES

#endif // ARTICULOGLOBALES_H_INCLUDED
