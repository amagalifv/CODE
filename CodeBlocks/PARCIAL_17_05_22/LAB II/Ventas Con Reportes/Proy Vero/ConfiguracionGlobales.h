#ifndef CONFIGURACIONESGLOBALES_H_INCLUDED
#define CONFIGURACIONESGLOBALES_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>

#include "Articulo.h"
#include "Venta.h"
#include "Cliente.h"

using namespace std;

///PROTOTIPOS DE FUNCIONES GLOBALES DE LA CLASE CONFIGURACION
void menuConfiguracion();
bool backupCliente();
bool restaurarBackupClientes();
bool cargarDatosInicioClientes();
bool backupArticulo();
bool restaurarBackupArticulos();
bool cargarDatosInicioArticulos();
bool backupVentas();
bool restaurarBackupVentas();
bool cargarDatosInicioVentas();
void establecerDatosDeInicio();
///FIN PROTOTIPOS DE FUNCIONES GLOBALES DE LA CLASE CONFIGURACION

///FUNCIONES GLOBALES DE LA CLASE CONFIGURACION
void menuConfiguracion(){
    int opc=0;

    cout<<"**** MENU CONFIGURACION ****"<<endl<<endl;
    cout<<"1. COPIA DE SEGURIDAD DEL ARCHIVO DE CLIENTES"<<endl;
    cout<<"2. COPIA DE SEGURIDAD DEL ARCHIVO DE ARTICULOS"<<endl;
    cout<<"3. COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS"<<endl;
    cout<<"4. RESTAURAR EL ARCHIVO DE CLIENTES"<<endl;
    cout<<"5. RESTAURAR EL ARCHIVO DE ARTICULOS"<<endl;
    cout<<"6. RESTAURAR EL ARCHIVO DE VENTAS"<<endl;
    cout<<"7. ESTABLECER DATOS DE INICIO"<<endl;
    cout<<"****************************"<<endl;
    cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"SELECCIONES UNA DE LAS OPCIONES: ";
    cin>>opc;
    system("cls");

    switch (opc){
        //1. COPIA DE SEGURIDAD DEL ARCHIVO DE CLIENTES
        case 1: backupCliente();
            system("pause");
            break;

        //2. COPIA DE SEGURIDAD DEL ARCHIVO DE ARTICULOS
        case 2: backupArticulo();
            system("pause");
            break;

        //3. COPIA DE SEGURIDAD DEL ARCHIVO DE VENTAS
        case 3: backupVentas();
            system("pause");
            break;

        //4. RESTAURAR EL ARCHIVO DE CLIENTES
        case 4: restaurarBackupClientes();
            system("pause");
            break;

        //5. RESTAURAR EL ARCHIVO DE ARTICULOS
        case 5: restaurarBackupArticulos();
            system("pause");
            break;

        //6. RESTAURAR EL ARCHIVO DE VENTAS
        case 6: restaurarBackupVentas();
            system("pause");
            break;

        //7. ESTABLECER DATOS DE INICIO
        case 7: establecerDatosDeInicio();
            system("pause");
            break;

        case 0: return;

        default:
            break;
    }
}
bool backupCliente(){
    FILE *clienteBkp;
    clienteBkp=fopen("Clientes.bak","wb");
    bool resultado=true;
    Cliente reg;
    int posDisco=0;

    if(clienteBkp==NULL){
        resultado=false;
    }

    while(reg.leerDeDisco(posDisco)==1){
    //    if(reg.getEstado()){
            fwrite(&reg, sizeof (Cliente), 1, clienteBkp);
      //  }
        posDisco++;
    }

    if (posDisco==0){
        resultado=false;
    }

    backupYRestore(resultado);

    fclose(clienteBkp);
    return resultado;
}
bool restaurarBackupClientes(){
    FILE *restaurarArchivoBkp;
    FILE *eliminarArchivoOrigen;
    bool restauro=true;
    int posDisco=0;
    Cliente reg;

    eliminarArchivoOrigen=fopen("Clientes.dat","wb");
    fclose(eliminarArchivoOrigen);

    restaurarArchivoBkp=fopen("Clientes.bak","rb");

    if(restaurarArchivoBkp==NULL){
        return false;
    }

    while(fread(&reg, sizeof reg, 1, restaurarArchivoBkp)==1){
        reg.grabarEnDisco(posDisco);
        posDisco++;
    }

    backupYRestore(restauro);

    fclose(restaurarArchivoBkp);
    return restauro;

}
bool cargarDatosInicioClientes(){
    FILE *datosInicioClientes;
    FILE *eliminarArchivoOrigen;
    bool restauro=true;
    int posDisco=0;
    Cliente reg;

    eliminarArchivoOrigen=fopen("Clientes.dat","wb");
    fclose(eliminarArchivoOrigen);

    datosInicioClientes=fopen("Clientes.ini","rb");

    if(datosInicioClientes==NULL){
        return false;
    }

    while(fread(&reg, sizeof reg, 1, datosInicioClientes)==1){
        reg.grabarEnDisco(posDisco);
        posDisco++;
    }

    fclose(datosInicioClientes);
    return restauro;
}
bool backupArticulo(){
    FILE *archivoBkp;
    archivoBkp=fopen("Articulos.bak","wb");
    bool resultado=true;
    Articulo reg;
    int posDisco=0;

    if(archivoBkp==NULL){
        resultado=false;
    }

    while(reg.leerDeDisco(posDisco)==1){
//        if(reg.getEstado() ){
            fwrite(&reg, sizeof (Articulo), 1, archivoBkp);
  //      }
        posDisco++;
    }

    if (posDisco==0){
        resultado=false;
    }

    backupYRestore(resultado);

    fclose(archivoBkp);
    return resultado;
}
bool restaurarBackupArticulos(){
    FILE *restaurarArchivoBkp;
    FILE *eliminarArchivoOrigen;
    bool restauro=true;
    int posDisco=0;
    Articulo reg;

    eliminarArchivoOrigen=fopen("Articulos.dat","wb");
    fclose(eliminarArchivoOrigen);

    restaurarArchivoBkp=fopen("Articulos.bak","rb");

    if(restaurarArchivoBkp==NULL){
        return false;
    }

    while(fread(&reg, sizeof reg, 1, restaurarArchivoBkp)==1){
        reg.grabarEnDisco(posDisco);
        posDisco++;
    }

    backupYRestore(restauro);

    fclose(restaurarArchivoBkp);
    return restauro;
}
bool cargarDatosInicioArticulos(){
    FILE *datosInicioArticulos;
    FILE *eliminarArchivoOrigen;
    bool restauro=true;
    int posDisco=0;
    Articulo reg;

    eliminarArchivoOrigen=fopen("Articulos.dat","wb");
    fclose(eliminarArchivoOrigen);

    datosInicioArticulos=fopen("Articulos.ini","rb");

    if(datosInicioArticulos==NULL){
        return false;
    }

    while(fread(&reg, sizeof reg, 1, datosInicioArticulos)==1){
        reg.grabarEnDisco(posDisco);
        posDisco++;
    }

    fclose(datosInicioArticulos);
    return restauro;
}
bool backupVentas(){
    FILE *archivoBkp;
    archivoBkp=fopen("ventas.bak","wb");
    bool resultado=true;
    Venta reg;
    int posDisco=0;

    if(archivoBkp==NULL){
        resultado=false;
    }

    while(reg.leerDeDisco(posDisco)==1){
//        if(reg.getEstado()){
            fwrite(&reg, sizeof reg, 1, archivoBkp);
  //      }
        posDisco++;
    }

    if (posDisco==0){
        resultado=false;
    }

    backupYRestore(resultado);

    fclose(archivoBkp);
    return resultado;
}
bool restaurarBackupVentas(){
    FILE *restaurarArchivoBkp;
    FILE *eliminarArchivoOrigen;
    bool restauro=true;
    Venta reg;
    int posDisco=0;

    eliminarArchivoOrigen=fopen("Ventas.dat","wb");
    fclose(eliminarArchivoOrigen);

    restaurarArchivoBkp=fopen("Ventas.bak","rb");

    if(restaurarArchivoBkp==NULL){
        return false;
    }

    while(fread(&reg, sizeof reg, 1, restaurarArchivoBkp)==1){
        reg.grabarEnDisco(posDisco);
        posDisco++;
    }

    backupYRestore(restauro);

    fclose(restaurarArchivoBkp);
    return restauro;
}
bool cargarDatosInicioVentas(){
    FILE *datosInicioVentas;
    FILE *eliminarArchivoOrigen;
    bool restauro=true;
    Venta reg;
    int posDisco=0;

    eliminarArchivoOrigen=fopen("Ventas.dat","wb");
    fclose(eliminarArchivoOrigen);

    datosInicioVentas=fopen("Ventas.ini","rb");

    if(datosInicioVentas==NULL){
        return false;
    }

    while(fread(&reg, sizeof reg, 1, datosInicioVentas)==1){
        reg.grabarEnDisco(posDisco);
        posDisco++;
    }

    fclose(datosInicioVentas);
    return restauro;
}
void establecerDatosDeInicio(){
    bool estado;

    estado=cargarDatosInicioClientes();
    if(!estado){
        return;
    }
    else{
        estado=cargarDatosInicioArticulos();
        if(!estado){
            return;
        }
        else{
            estado=cargarDatosInicioVentas();
            if(!estado){
                backupYRestore(estado);
            }
            else{
                backupYRestore(estado);
            }
        }
    }
}
///FIN FUNCIONES GLOBALES DE LA CLASE CONFIGURACION

#endif // CONFIGURACIONESGLOBALES_H_INCLUDED
