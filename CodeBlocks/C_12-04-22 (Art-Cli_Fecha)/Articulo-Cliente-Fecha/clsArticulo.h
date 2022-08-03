#ifndef CLSARTICULO_H_INCLUDED
#define CLSARTICULO_H_INCLUDED

#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;


class Articulo {
    private:
        char _codigo[5];
        char _descripcion[30];
        float _precio;
        int _stock;
        bool _estado;
    public:
        Articulo(const char *c="AAAA", const char *d="Sin descripcion", float precio=0, int stock=0, bool est=false){
            strcpy(_codigo, c);
            strcpy(_descripcion, d);
            _precio=precio;
            _stock=stock;
            _estado=est;
        }

        void Cargar();
        void Mostrar();
        // SETS
        void setCodigo(const char *cod){strcpy(_codigo, cod);}
        void setDescripcion(const char *desc){strcpy(_descripcion, desc);}
        void setPrecio(float precio){_precio=precio;}
        void setStock(int stock){if(stock>=0)_stock=stock;}
        void setEstado(bool est){_estado=est;}
        // GETS
        const char *getCodigo(){return _codigo;}
        const char *getDescripcion(){return _descripcion;}
        float getPrecio(){return _precio;}
        int getStock(){return _stock;}
        bool getEstado(){return _estado;}
};

void Articulo::Cargar(){
    char cod[5], desc[30];
    float precio;
    int stock;

    cout<<"INGRESE EL CODIGO: ";
    cargarCadena(cod, 4);
    setCodigo(cod);

    cout<<"INGRESE LA DESCRIPCION: ";
    cargarCadena(desc, 29);
    setDescripcion(desc);

    cout<<"INGRESE EL PRECIO: ";
    cin>>precio;
    setPrecio(precio);

    cout<<"INGRESE EL STOCK: ";
    cin>>stock;
    setStock(stock);

    _estado=true;
}

void Articulo::Mostrar(){
    cout<<"--------------------------------------\n";
    cout<<"CODIGO: ";
    cout<<getCodigo()<<endl;
    cout<<"DESCRIPCION: ";
    cout<<getDescripcion()<<endl;
    cout<<"PRECIO: ";
    cout<<getPrecio()<<endl;
    cout<<"STOCK: ";
    cout<<getStock()<<endl;
    cout<<"--------------------------------------\n";
}

//Asociadas a clase Articulo

void cargarDiezArts(Articulo *v,int tam){

    for (int i=0; i<tam; i++) {
        v[i].Cargar();
    }
}

void mostrarArts(Articulo *v,int tam){

    for (int i=0; i<tam; i++) {
        v[i].Mostrar();
    }
}

int buscarCodigo(Articulo *v,int tam, const char*cod){

    for (int i=0; i<tam; i++) {

        if(strcmp(v[i].getCodigo(),cod)==0){
            return i;
        }
    }
    return -1;
}

void buscarStockMenor(Articulo *v,int tam, int stock){

    for (int i=0; i<tam; i++) {

        if(v[i].getStock()<=stock){
            v[i].Mostrar();
        }
    }
}

void actualizarPrecio(Articulo *v,int tam, int porcent){
    float decim=((float)porcent/100)+1;
    float num;

    for (int i=0; i<tam; i++) {
        num=v[i].getPrecio()*decim;
        v[i].setPrecio(num);
    }
}
#endif // CLSARTICULO_H_INCLUDED
