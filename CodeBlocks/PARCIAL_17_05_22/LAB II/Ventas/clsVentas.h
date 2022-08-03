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
    int Cargar(int id);
    void Mostrar();
    bool grabarEnDisco();
    int leerDeDisco(int pos);
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
    void setId(int ide) {_id=ide;}// ¿Debería ponerlo como privado?
    void setCodigo(const char *cod){strcpy(_codigo, cod);}
    void setDni(int d) {_dniCli=d;}
    void setCantidad(int c) {if (c>0){_cantidad=c;}}
    void setImporte(float im) {_importe=im;}
    void setFechaNac(Fecha f){_fecha=f;}
    void setEstado(bool est){_estado=est;}
};

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
    if (pVen==NULL) {
        return 0;// si el archivo no existia y no lo pudo abrir devuelve 0
    }

    leyo=fseek(pVen,(-1)*sizeof(Venta),SEEK_END);
    if (leyo!=0) {
        return -1;
    }

    leyo=fread(&id,sizeof (int),1,pVen);
    if (leyo!=1) {
        return -2;
    }
    id++;
    fclose(pVen);
    return id;
}

int Venta::Cargar(int id){
    char codi[5];
    float importe;
    int pos1, pos2, denei, cant;

    _id=id;

 //se fija si existe el codigo de art en articulos
    cout<<"INGRESE EL CODIGO DEL PRODUCTO: ";
    cargarCadena(codi, 4);
    pos1=buscarPosArt(codi);
    if (pos1>=0) {
        setCodigo(codi);
    }else{
        cout<<"codigo inexistente, vuelva a intentarlo mas tarde"<<endl;
        return -1;
    }
 //se fija si existe el dni en clientes
    cout<<"INGRESE EL DNI DEL CLIENTE: ";
    cin>>denei;
    pos2=buscarPosDni(denei);
    if (pos2>=0) {
        setDni(denei);
    }else{
        cout<<"DNI inexistente, vuelva a intentarlo mas tarde"<<endl;
        return -1;
    }

    cout<<"INGRESE LA CANTIDAD COMPRADA: ";
    cin>>cant;
    if(siStock(cant, pos1)==true){
        actualizarStock (cant, pos1);
        setCantidad(cant);
    }else{
        cout<<"No hay stock suficiente, vuelva a intentarlo mas tarde"<<endl;
        return -1;
    }

    importe=calcularImporte(cant, pos1);
    setImporte(importe);

    _fecha.Cargar();

    _estado=true;

    return 0;
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
    int id;

    //autogenera el id
    id=this->generarId();
    if (id>=0) {
        setId(id);
    }else{ return false;}

    pVent=fopen(AR_VENTAS,"ab");
    if (pVent==NULL){return false;}

    this->Cargar(id);

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
