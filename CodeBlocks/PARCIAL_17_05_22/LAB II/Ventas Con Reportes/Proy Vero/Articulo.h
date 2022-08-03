#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "funciones.h"

using namespace std;

class Articulo{

private:
    char _codigo[5]={0};
    char _descripcion[30]={0};
    float _precio;
    int _stock;
    bool _estado;

public:
    ///CONSTRUCTOR CON VALORES POR OMISI�N
    Articulo(const char *codigo="NADA", const char *pDescrip="NADA", float pPrecio=0, int pStock=0, bool pEstado=true){
        strcpy(_codigo,codigo);
        strcpy(_descripcion, pDescrip);
        _precio=pPrecio;
        _stock=pStock;
        _estado=pEstado;
    }

    ///CONSTRUCTOR DONDE S�LO CARGO LA DESCRIPCI�N
    Articulo(char *pDescrip){
        strcpy(_descripcion, pDescrip);
    }

    ///SETTERS
    void setCodigo(const char *codigo){strcpy(_codigo,codigo);}
    void setDescripcion(const char *pDescrip){strcpy(_descripcion,pDescrip);}
    void setPrecio(float pPrecio){
       /*  while(pPrecio<0){
            cout<<"PRECIO NEGATIVO INVALIDO, INGRESELO NUEVAMENTE: ";
            cin>>pPrecio;
        } */
        _precio=pPrecio;
    }
    void setStock(int pStock){
        /* while(pStock<0){
            cout<<"STOCK NEGATIVO INVALIDO, INGRESELO NUEVAMENTE: ";
            cin>>pStock;
        } */
        _stock=pStock;
    }
    void setEstado(bool pEstado){_estado=pEstado;}

    ///GETTERS
    const char *getCodigo(){return _codigo;}
    const char *getDescripcion(){return _descripcion;}
    float getPrecio(){return _precio;}
    int getStock(){return _stock;}
    bool getEstado(){return _estado;}

    ///METODOS
    void Cargar(const char *codigo="nada");
    void Mostrar();
    int leerDeDisco(int pos);
    int grabarEnDisco(int pos=-1);  //valor por defecto -1 si no se pasa parámetro
    //trabajo con el objeto que llama al método, a lo sumo modifico los valores de la propiedad a lo sumo 1 sola vez.
};

///METODOS DE LA CLASE ARTICULO
void Articulo::Cargar(const char *codigo){
    char auxCharCod[5]={0};
    char auxCharDesc[30]={0};
    int auxInt=0;
    float auxFloat=0;

    if(strcmp(codigo, "nada")==0){
        cout<<"CODIGO (máximo 4 dígitos):  ";
        cargarCadena(auxCharCod,5);
        setCodigo(auxCharCod);
    } else {
        setCodigo(codigo);
    }

    cout<<"DESCRIPCION: ";
    cargarCadena(auxCharDesc,30),
    setDescripcion(auxCharDesc);

    cout<<"PRECIO: $";
    cin>>auxFloat;
    setPrecio(auxFloat);

    cout<<"STOCK: ";
    cin>>auxInt;
    setStock(auxInt);

    setEstado(1);

    cout<<endl;
}
void Articulo::Mostrar(){
    cout<<"CODIGO: "<<getCodigo()<<endl;
    cout<<"DESCRIPCION: "<<getDescripcion()<<endl;
    cout<<"PRECIO: "<<getPrecio()<<endl;
    cout<<"STOCK: "<<getStock()<<endl;
    cout<<"ESTADO: "<<getEstado()<<endl;
    cout<<endl;
}
int Articulo::leerDeDisco(int pos){
    /******************************************
     Valores que retorna leerDeDisco(int pos):
     -1: NO ENCONTRÓ EL ARCHIVO
      1: LEYO EL ARCHIVO
      2:
    ******************************************/
    FILE *archivo;
    int leyo=-1;

    archivo=fopen("Articulos.dat","rb");

    if(archivo==NULL){
        return -1;
    }

    fseek(archivo, pos*sizeof(Articulo), 0);
    leyo=fread(this, sizeof(Articulo), 1, archivo);

    fclose(archivo);
    return leyo;
}
int Articulo::grabarEnDisco(int pos){
    /******************************************
     Valores que retorna grabarEnDisco(int pos):
     -1: NO PUDO GRABAR EN EL ARCHIVO
      1: ESCRIBIÓ EL ARCHIVO
      2:
    ******************************************/
FILE *archivo;
    int escribio;

    if(pos==-1){
        archivo=fopen("Articulos.dat", "ab");
        if(archivo==NULL){
            return -1;
        }
    }
    else{
        archivo=fopen("Articulos.dat", "rb+");
        if(archivo==NULL){
            return -1;
        }
        fseek(archivo, sizeof(Articulo)*pos, 0);
    }

    escribio=fwrite(this, sizeof(Articulo), 1, archivo);
    fclose(archivo);
    return escribio;
}
///FIN METODOS DE LA CLASE ARTICULO

#endif // ARTICULO_H_INCLUDED
