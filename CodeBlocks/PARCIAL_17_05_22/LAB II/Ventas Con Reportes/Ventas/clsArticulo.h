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
        float _precioU;
        int _stock;
        bool _estado;
    public:
        Articulo(const char *c="0000", const char *d="Sin descripcion", float precio=0, int stock=0, bool est=false){
            strcpy(_codigo, c);
            strcpy(_descripcion, d);
            _precioU=precio;
            _stock=stock;
            _estado=est;
        }

        void Cargar(const char* cod="0000");
        void Mostrar();
        bool grabarEnDisco();
        bool grabarEnDisco(const char* archivo);
        bool sobrescribirDisco();
        int leerDeDisco(int pos);
        int leerDeDisco(int pos, const char *nombreArchivo);
        int modificarDeDisco(int pos);
        // SETS
        void setCodigo(const char *cod){strcpy(_codigo, cod);}
        void setDescripcion(const char *desc){strcpy(_descripcion, desc);}
        void setPrecio(float precio){_precioU=precio;}
        void setStock(int stock){if(stock>=0)_stock=stock;}
        void setEstado(bool est){_estado=est;}
        // GETS
        const char *getCodigo(){return _codigo;}
        const char *getDescripcion(){return _descripcion;}
        float getPrecio(){return _precioU;}
        int getStock(){return _stock;}
        bool getEstado(){return _estado;}
};

void Articulo::Cargar(const char* cod){
    char desc[30], codi[5];
    float precio;
    int stock;

    if (strcmp(cod, "0000")==0) {
        cout<<"INGRESE EL CODIGO (4 dígitos): ";
        cargarCadena(codi, 4);
        setCodigo(codi);
    } else {
        setCodigo(cod);
    }

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

/*
devuelve falso si NO pudo grabar
y verdadero si pudo
*/
bool Articulo::grabarEnDisco(){
    FILE *pArt;
    bool escribio;

    pArt=fopen(AR_ARTICULOS,"ab");
    if (pArt==NULL){return false;}

    escribio=fwrite(this ,sizeof(Articulo),1,pArt);
    fclose(pArt);

    return escribio;
}

/*
devuelve falso si NO pudo grabar
y verdadero si pudo
*/
bool Articulo::grabarEnDisco(const char* archivo){
    FILE *pArt;
    bool escribio;

    pArt=fopen(archivo,"ab");
    if (pArt==NULL){return false;}

    escribio=fwrite(this ,sizeof(Articulo),1,pArt);
    fclose(pArt);

    return escribio;
}

/*
devuelve -1 si no lo pudo abrir archivo
carga en el obj de la cls la info que leyo y devuelve 1
Si no pudo leer devuelve 0
*/
int Articulo::leerDeDisco(int pos){
    FILE *pArt;
    int leyo;

    pArt=fopen(AR_ARTICULOS,"rb");
    if (pArt==NULL){return -1;}

    fseek(pArt, sizeof(Articulo)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Articulo),1,pArt);
    fclose(pArt);

    return leyo;
}
/*
devuelve -1 si no lo pudo abrir archivo
carga en el obj de la cls la info que leyo y devuelve 1
Si no pudo leer devuelve 0
*/
int Articulo::leerDeDisco(int pos, const char *nombreArchivo){
    FILE *pArt;
    int leyo;

    pArt=fopen(nombreArchivo,"rb");
    if (pArt==NULL){return -1;}

    fseek(pArt, sizeof(Articulo)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Articulo),1,pArt);
    fclose(pArt);

    return leyo;
}

/*
-1 si no pudo abrir
0 si no pudo escribir
1 si escribió exitosamente
*/
int Articulo::modificarDeDisco(int pos){
    FILE *pArt;
    int escribio;

    pArt=fopen(AR_ARTICULOS,"rb+");
    if (pArt==NULL){return -1;}

    fseek(pArt, pos * sizeof(Articulo),SEEK_SET);
    escribio=fwrite(this,sizeof (Articulo),1,pArt);

    fclose(pArt);
    return escribio;
}

#endif // CLSARTICULO_H_INCLUDED
