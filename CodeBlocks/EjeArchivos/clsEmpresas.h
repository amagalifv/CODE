#ifndef CLSEMPRESAS_H_INCLUDED
#define CLSEMPRESAS_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
using namespace std;

class Empresa{

    private:
        int _id;
        char _nombre[30];
        short _cantEmple;
        short _categoria;
        short _nroMuncipio;
        bool _estado;

    public:
        Empresa(int ide=0, const char*nom="aaaa", short cant=0, short cate=0, short muni=0, bool estad=true ){
         _id=ide;
        strcpy(_nombre,nom);
        _cantEmple=cant;
        _categoria=cate;
        _nroMuncipio=muni;
        _estado=estad;
        }
        int getId(){return _id;}
        const char *getNombre(){return _nombre;}
        int getCantEmpleados(){return _cantEmple;}
        short getCategoria(){return _categoria;}
        short getNroMunicipio(){return _nroMuncipio;}
        short getEstado(){return _estado;}
        void setId(int id){_id=id;}
        void setNombre(const char *nom[30]){strcpy(_nombre,nom);}
        void setCantEmpleados(int cant){_cantEmple=cant;}
        void setCategoria(short cat){_categoria=cat;}
        void setNroMunicipio(short nro){_nroMuncipio=nro;}
        void setEstado(bool est){_estado=est;}
        int cargarEnArchivo();
        int leerRegistros();
        void Cargar();
        void Mostrar();
};

int Empresa::leerRegistros(){
    FILE *ptrArchivo;
    //Empresa reg;
    int leyo;

    ptrArchivo=fopen("cliente.dat", "rb");
    if(ptrArchivo==NULL){return -1;};

    leyo=fread(this, sizeof (Empresa), 1, ptrArchivo);

    //reg.Mostrar();

    fclose(ptrArchivo);

    return leyo;
}

int Empresa::cargarEnArchivo(){
    FILE *pEmp;
    int siEscrib;

    pEmp=fopen("empresas.dat", "ab");
    if (pEmp==NULL) {
        return -1;
    }

    //reg.Cargar();

    siEscrib=fwrite(this, sizeof(Empresa), 1, pEmp);

    fclose(pEmp);

    return siEscrib;
}//CHEQUEAR EN LA LLAMADA SI DEVUELVE ALGO =! A 1

void Empresa::Cargar(){
    short var1;
    int var2;
    const char nom[30];

    cout<<"ID                   :";
    cin>>var2;
    setId(var2);

    cout<<"NOMBRE               :";
    cin.getline(nom, 29);
    setNombre(nom);

    cout<<"CANTIDAD DE EMPLEADOS:";
    cin>>var1;
    setCantEmpleados(var1);

    cout<<"CATEGORIA            :";
    cin>>var1;
    setCategoria(var1);

    cout<<"NRO DE MUNICIPIO     :";
    cin>>var1;
    setNroMunicipio(var1);

    setEstado(true);
}

void Empresa::Mostrar(){
    cout<<"-----------------------------------------------------------------"<<endl;

    cout<<"ID                   :";
    cout<<getId()<<endl;

    cout<<"NOMBRE               :";
    cout<<getNombre()<<endl;

    cout<<"CANTIDAD DE EMPLEADOS:";
    cout<<getCantEmpleados()<<endl;

    cout<<"CATEGORIA            :";
    cout<<getCategoria()<<endl;

    cout<<"NRO DE MUNICIPIO     :";
    cout<<getNroMunicipio()<<endl;

    cout<<"-----------------------------------------------------------------"<<endl;
}

#endif // CLSEMPRESAS_H_INCLUDED
