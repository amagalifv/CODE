#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "Articulo.h"
#include "Fecha.h"
#include "funciones.h"
#include "Cliente.h"

using namespace std;

class Venta{
private:
    int idVenta=0;              //autonumerico
    char codArticulo[5]={0};
    int dniCliente;
    int cantUnidades;
    float importe;
    Fecha fechaVenta;
    bool estado;

public:
    ///CONSTRUCTOR CON VALORES POR OMISIÓN
    Venta(int pIdVenta=0, const char *pCodArticulo="NADA", int pDniCliente=0, int pCantUnidades=0, float pImporte=0, Fecha pFechaVenta=0, bool pEstado=true){
        strcpy(codArticulo, pCodArticulo);
        dniCliente=pDniCliente;
        cantUnidades=pCantUnidades;
        importe=pImporte;
        fechaVenta=pFechaVenta;
        estado=pEstado;
    }

    ///SETTERS
    void setIdVenta(int proxNum){idVenta=proxNum;}
    void setCodArticulo(const char *pCodArticulo){strcpy(codArticulo, pCodArticulo);}
    void setDniCliente(int pDniCliente){dniCliente=pDniCliente;}
    void setCantUnidades(const char *pCodArticulo, int pCantUnidades){
        cantUnidades=pCantUnidades;
    }
    void setImporte(float pImporte){importe=pImporte;}
    void setFechaVenta(Fecha pFechaVenta){fechaVenta=pFechaVenta;}
    void setEstado(bool pEstado=true){estado=pEstado;}

    ///GETTERS
    int getIdVenta(){return idVenta;}
    const char *getCodArticulo(){return codArticulo;}
    int getDniCliente(){return dniCliente;}
    int getCantUnidades(){return cantUnidades;}
    float getImporte(){return importe;}
    Fecha getFechaVenta(){return fechaVenta;}
    bool getEstado(){return estado;}

    ///METODOS
    void Cargar(int pDniCliente=-1, const char *pCodigoArticulo="nada", int pCantUnidades=-1, float pImporte=0);
    void Mostrar();
    int leerDeDisco(int pos);
    int grabarEnDisco(int pos=-1);
    //float calcularImporte(int auxInt, const char *auxChar);
    int proximaVenta();
};

///METODOS DE LA CLASE VENTA
void Venta::Cargar(int pDniCliente, const char *pCodigoArticulo, int pCantUnidades, float pImporte){
    setIdVenta(proximaVenta());
    setDniCliente(pDniCliente);
    setCodArticulo(pCodigoArticulo);
    setCantUnidades(pCodigoArticulo,pCantUnidades);
    setImporte(pImporte);
    fechaVenta.Cargar();
    setEstado(1);
    cout<<endl;
}
void Venta::Mostrar(){
    //Articulo reg;

    //reg.leerDeDisco(buscarArticuloPorCodigo(getCodArticulo()));

    cout<<"ID VENTA: "<<getIdVenta()<<endl;
    cout<<"DNI CLIENTE: "<<getDniCliente()<<endl;
    cout<<"CODIGO DEL ARTICULO: "<<getCodArticulo()<<endl;
    //cout<<"ARTICULO: "<<reg.getDescripcion()<<endl;
    cout<<"CANTIDAD: "<<getCantUnidades()<<endl;
    cout<<"IMPORTE: $"<<getImporte()<<endl;
    cout<<"FECHA: ";
    fechaVenta.Mostrar();
    cout<<endl;
}
int Venta::leerDeDisco(int pos){
    /******************************************
     Valores que retorna leerDeDisco(int pos):
     -1: NO ENCONTRÓ EL ARCHIVO
      1: LEYO EL ARCHIVO
      2:
      NOTA: SI PARAMETRO == -8, LEE DESDE EL FINAL AL INICIO DEL ARCHIVO
    ******************************************/
    FILE *archivo;
    int leyo=-1;

    archivo=fopen("Ventas.dat","rb");

    if(archivo==NULL){
        return -1;
    }

    if( pos == -8){
        fseek(archivo, (-1)*sizeof(Venta), SEEK_END);
        leyo=fread(this, sizeof(Venta), 1, archivo);
    }
    else{
        fseek(archivo, pos*sizeof(Venta), 0);
        leyo=fread(this, sizeof(Venta), 1, archivo);
    }

    fclose(archivo);
    return leyo;
}
int Venta::grabarEnDisco(int pos){
    /******************************************
     Valores que retorna grabarEnDisco(int pos):
     -1: NO PUDO GRABAR EN EL ARCHIVO
      1: ESCRIBIÓ EL ARCHIVO
      2:
    ******************************************/
FILE *archivo;
    int escribio;

    if(pos==-1){
        archivo=fopen("Ventas.dat", "ab");
        if(archivo==NULL){
            return -1;
        }
    }
    else{
        archivo=fopen("Ventas.dat", "rb+");
        if(archivo==NULL){
            return -1;
        }
        fseek(archivo, sizeof(Venta)*pos, 0);
    }

    escribio=fwrite(this, sizeof(Venta), 1, archivo);
    fclose(archivo);
    return escribio;
}

int Venta::proximaVenta(){
    ///DEVUELVE EL PROXIMO NRO DE VENTA (AUTOINCREMENTABLE)
/*     int posDisco=0;

    while(leerDeDisco(posDisco)==1){
        posDisco++;
    }

    return posDisco+1; */

    leerDeDisco(-8);

    return getIdVenta()+1;
}
///FIN METODOS DE LA CLASE VENTA

#endif // VENTA_H_INCLUDED
