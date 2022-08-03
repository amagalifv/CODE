#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "clsFecha.h"

class Cliente{
    private:
        int _dni;
        char _nombre[20];
        char _apellido[20];
        char _email[30];
        char _telefono[25];
        Fecha _fechaNac;
        bool _estado;
    public:
        Cliente(int dni=0, const char *nom="AAAA", const char *ape="AAAA", const char *email="aa@aa.aa",const char *tel="0", bool est=true){//FALTA FECHA
            _dni=dni;
            strcpy(_apellido, ape);
            strcpy(_nombre, nom);
            strcpy(_email, email);
           strcpy(_telefono, tel);
           _estado=est;
        }
        void Cargar(int dni=0);
        void Mostrar();
        bool grabarEnDisco();
        bool grabarEnDisco(const char *nombreArchivo);
        bool sobrescribirDisco();
        int leerDeDisco(int pos);
        int leerDeDisco(int pos, const char *nombreArchivo);
        int modificarDeDisco (int pos);
        //GETS
        int getDni(){return _dni;}
        const char *getApellido(){return _apellido;}
        const char *getNombre(){return _nombre;}
        const char *getEmail(){return _email;}
        const char *getTelefono(){return _telefono;}
        Fecha getFechaNac(){return _fechaNac;}
        bool getEstado(){return _estado;}
        // SETS
        void setDni(int dni){_dni=dni;}
        void setApellido(char nom[30]){strcpy(_apellido, nom);}
        void setNombre(char nom[30]){strcpy(_nombre, nom);}
        void setEmail(char nom[30]){strcpy(_email, nom);}
        void setTelefono(char tel[25]){strcpy(_telefono,tel);}
        void setFechaNac(Fecha f){_fechaNac=f;}
        void setEstado(bool est){_estado=est;}

};

void Cliente::Cargar(int dni){
    char tex[20],texto[30];

    if (dni==0){
        cout<<"INGRESE EL DNI                 :";
        cin>>dni;
        setDni(dni);
    }else{
        setDni(dni);
    }

    cout<<"INGRESE EL APELLIDO            :";
    cargarCadena(tex, 20);
    setApellido(tex);

    cout<<"INGRESE EL NOMBRE              :";
    cargarCadena(tex, 20);
    setNombre(tex);

    cout<<"INGRESE EL EMAIL               :";
    cargarCadena(texto, 30);
    setEmail(texto);

    cout<<"INGRESE EL TELEFONO            :";
    cargarCadena(texto,25);
    setTelefono(texto);

    cout<<"FECHA DE NACIMIENTO :     "<<endl;
    _fechaNac.CargarParaCli();

    /*cout<<"Estado               :";
    cin>>est;
    setEstado(est);*/
    setEstado(true);
}

void Cliente::Mostrar(){
    cout<<"DNI                 :";
    cout<<getDni()<<endl;
    cout<<"APELLIDO            :";
    cout<<getApellido()<<endl;
    cout<<"NOMBRE              :";
    cout<<getNombre()<<endl;
    cout<<"EMAIL               :";
    cout<<getEmail()<<endl;
    cout<<"TELEFONO            :";
    cout<<getTelefono()<<endl;
    cout<<"FECHA DE NACIMIENTO :";
    _fechaNac.Mostrar();
    cout<<endl;
}

/*
devuelve falso si NO pudo grabar
y verdadero si pudo
*/
bool Cliente::grabarEnDisco(){
    FILE *pCli;
    bool escribio;

    pCli=fopen(AR_CLIENTES,"ab");
    if (pCli==NULL){return false;}

    escribio=fwrite(this ,sizeof(Cliente),1,pCli);
    fclose(pCli);
    return escribio;
}

/*
devuelve -1 si no lo pudo abrir archivo
carga en el obj de la cls la info que leyo y devuelve 1
Si no pudo leer devuelve 0
*/
int Cliente::leerDeDisco(int pos){
    FILE *pCli;
    int leyo;

    pCli=fopen(AR_CLIENTES,"rb");
    if (pCli==NULL){return -1;}

    fseek(pCli, sizeof(Cliente)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Cliente),1,pCli);
    fclose(pCli);

    return leyo;
}

/*
devuelve -1 si no lo pudo abrir archivo
carga en el obj de la cls la info que leyo y devuelve 1
Si no pudo leer devuelve 0
*/
int Cliente::leerDeDisco(int pos, const char *nombreArchivo){
    FILE *pCli;
    int leyo;

    pCli=fopen(nombreArchivo,"rb");
    if (pCli==NULL){return -1;}

    fseek(pCli, sizeof(Cliente)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Cliente),1,pCli);
    fclose(pCli);

    return leyo;
}

/*
-1 si no pudo abrir
0 si no pudo escribir
1 si escribió exitosamente
*/
int Cliente::modificarDeDisco(int pos){
    FILE *pCli;
    int escribio;

    pCli=fopen(AR_CLIENTES,"rb+");
    if (pCli==NULL){return -1;}

    fseek(pCli, pos * sizeof(Cliente),SEEK_SET);
    escribio=fwrite(this,sizeof (Cliente),1,pCli);

    fclose(pCli);
    return escribio;
}

#endif // CLSCLIENTE_H_INCLUDED
