#ifndef CLSVENTAS_H_INCLUDED
#define CLSVENTAS_H_INCLUDED

#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

const char *AR_ID="generarid.dat";

class Venta{
    private:
        int _id;
        char _codigo[5];
        int _dniCli;
        int _cantidad;
        float _importe;
        Fecha _fecha;
        bool _estado;
    public:
    Venta(){
        _id=0;
    }
    int generarId();
    bool Cargar();
    void Mostrar();
    void SinRestricCargar();
    bool grabarEnDisco();
    bool grabarEnDisco(const char* nombreArchivo);
    bool sobrescribirDisco();
    int leerDeDisco(int pos);
    int leerDeDisco(int pos, const char *nombreArchivo);
    int modificarDeDisco(int pos);
    // GETS
    int getId() {return _id;}
    const char *getCodigo(){return _codigo;}
    int getDni() {return _dniCli;}
    int getCantidad() {return _cantidad;}
    float getImporte() {return _importe;}
    Fecha getFechaNac(){return _fecha;}
    bool getEstado(){return _estado;}
    // SETS
    bool setId(int ide);
    bool setCodigo(const char *cod);
    bool setDni(int d);
    void setCantidad(int c){if (c>0){_cantidad=c;}}
    bool setCantidad(int cant, const char *cod);
    void setImporte(float im) {_importe=im;}
    void setFechaNac(Fecha f){_fecha=f;}
    void setEstado(bool est){_estado=est;}
};

bool Venta::setId(int ide){
    if(ide>=0){
        _id=ide;
        return true;
    } else return false;
}
bool Venta::setCodigo(const char *cod){
    int pos;

    pos=buscarPosArt(cod);

    if (pos>=0) {
        strcpy(_codigo, cod);
        return true;
    }else{
        return false;
    }
}
bool Venta::setDni(int d){
    int pos;

    pos=buscarPosDni(d);
    if (pos>=0) {
        _dniCli=d;
        return true;
    }else{
        return false;
    }
}
bool Venta::setCantidad(int cant, const char *cod) {
    int pos;

    pos=buscarPosArt(cod);

    if(siStock(cant, pos)==true && cant>0){
        actualizarStock (cant, pos);
        _cantidad=cant;
        return true;
    }else{
        return false;
    }
}


/*
devuelve:
0 si aun no exist el archivo
-2 si error fseek
-1 si error lectura
nuevo id autoincrementado si exito
*/
int Venta::generarId(){
    FILE *pVen=NULL;
    int id;
    int leyo;

    pVen=fopen (AR_VENTAS, "rb+");
    if (pVen==NULL) {return 0;}// si el archivo no existia y no lo pudo abrir devuelve 0

    leyo=fseek(pVen,(-1)*sizeof(Venta),SEEK_END);
    if (leyo!=0) {return -1;}

    leyo=fread(&id,sizeof (int),1,pVen);
    if (leyo!=1) { return -2;}
    id++;
    fclose(pVen);
    return id;
}

void Venta::SinRestricCargar(){
    char codi[5];
    float importe;
    int denei, cant,id;

    cout<<"INGRESE EL ID: ";
    cin>>id;
    _id=id;

    cout<<"INGRESE EL CODIGO DEL PRODUCTO: ";
    cargarCadena(codi,4);
    strcpy(_codigo, codi);

    cout<<"INGRESE EL DNI DEL CLIENTE: ";
    cin>>denei;
    _dniCli=denei;


    cout<<"INGRESE LA CANTIDAD COMPRADA: ";
    cin>>cant;
    _cantidad=cant;

    cout<<"INGRESE EL IMPORTE: ";
    cin>>importe;
    _importe=importe;

    _fecha.Cargar();

    _estado=true;

}

bool Venta::Cargar(){
    char codi[5];
    float importe;
    int denei, cant,id;

    id=this->generarId();
    if (id>=0)setId(id);
    else return false;

    cout<<"INGRESE EL CODIGO DEL PRODUCTO: ";
    cargarCadena(codi, 4);
    if (!setCodigo(codi)) {return false;}
    else setCodigo(codi);

    cout<<"INGRESE EL DNI DEL CLIENTE: ";
    cin>>denei;
    if (!setDni(denei)) {return false;}
    else setDni(denei);

    cout<<"INGRESE LA CANTIDAD COMPRADA: ";
    cin>>cant;
    if (!setCantidad(cant,codi)) {return false;}
    else setCantidad(cant);

    importe=calcularImporte(cant, codi);
    setImporte(importe);

    _fecha.Cargar();

    _estado=true;

    return true;
}

void Venta::Mostrar(){
    cout<<"--------------------------------------\n";
    cout<<"ID: ";
    cout<<getId()<<endl;
    cout<<"CODIGO del ARTICULO: ";
    cout<<getCodigo()<<endl;
    cout<<"DNI DEL CLIENTE: ";
    cout<<getDni()<<endl;
    cout<<"CANTIDAD: ";
    cout<<getCantidad()<<endl;
    cout<<"IMPORTE: ";
    cout<<getImporte()<<endl;
    _fecha.Mostrar();
    cout<<"--------------------------------------\n";
}

/*
devuelve falso si NO pudo grabar
y verdadero si pudo
*/
bool Venta::grabarEnDisco(){
    FILE *pVent;
    bool escribio;

    pVent=fopen(AR_VENTAS,"ab");
    if (pVent==NULL){return false;}

    escribio=fwrite(this ,sizeof(Venta),1,pVent);
    fclose(pVent);

    return true;
}

/*
devuelve -1 si no lo pudo abrir archivo
carga en el obj de la cls la info que leyo y devuelve 1
Si no pudo leer devuelve 0
*/
int Venta::leerDeDisco(int pos){
    FILE *pVent;
    int leyo;

    pVent=fopen(AR_VENTAS,"rb");
    if (pVent==NULL){return -1;}

    fseek(pVent, sizeof(Venta)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Venta),1,pVent);
    fclose(pVent);

    return leyo;
}

/*
devuelve -1 si no lo pudo abrir archivo
carga en el obj de la cls la info que leyo y devuelve 1
Si no pudo leer devuelve 0
*/
int Venta::leerDeDisco(int pos, const char *nombreArchivo){
    FILE *pVent;
    int leyo;

    pVent=fopen(nombreArchivo,"rb");
    if (pVent==NULL){return -1;}

    fseek(pVent, sizeof(Venta)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Venta),1,pVent);
    fclose(pVent);

    return leyo;
}

/*
-1 si no pudo abrir
0 si no pudo escribir
1 si escribió exitosamente
*/
int Venta::modificarDeDisco(int pos){
    FILE *pVent;
    int escribio;

    pVent=fopen(AR_VENTAS,"rb+");
    if (pVent==NULL){return -1;}

    fseek(pVent, pos * sizeof(Venta),SEEK_SET);
    escribio=fwrite(this,sizeof (Venta),1,pVent);

    fclose(pVent);
    return escribio;
}

#endif // CLSVENTAS_H_INCLUDED
