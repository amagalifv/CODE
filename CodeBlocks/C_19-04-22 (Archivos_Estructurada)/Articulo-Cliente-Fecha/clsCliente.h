#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#include "clsFecha.h"

const char *AR_CLIENTES="clientes.dat";

class Cliente{
    private:
        int _dni;
        char _nombre[20];
        char _apellido[20];
        char _email[30];
        char _telefono[25];
        Fecha _fechaNac ;
        bool estado;
    public:
        Cliente(int dni=0, const char *nom="AAAA", const char *ape="AAAA", const char *email="aa@aa.aa",const char *tel="0"){//FALTA FECHA
            _dni=dni;
            strcpy(_apellido, ape);
            strcpy(_nombre, nom);
            strcpy(_email, email);
           strcpy(_telefono, tel);
        }
        Cliente(char nom[30]){strcpy(_nombre, nom);}
        void Cargar(int dni=0);
        void Mostrar();
        int AgregarCliente();
        int buscarDni(int dni);
        int ListarClientes();
        //GETS
        int getDni(){return _dni;}
        const char *getApellido(){return _apellido;}
        const char *getNombre(){return _nombre;}
        const char *getEmail(){return _email;}
        const char *getTelefono(){return _telefono;}
        Fecha getFechaNac(){return _fechaNac;}
        // SETS
        void setDni(int dni){_dni=dni;}
        void setApellido(char nom[30]){strcpy(_apellido, nom);}
        void setNombre(char nom[30]){strcpy(_nombre, nom);}
        void setEmail(char nom[30]){strcpy(_email, nom);}
        void setTelefono(char tel[25]){strcpy(_telefono,tel);}
        void setFechaNac(Fecha f){_fechaNac=f;}

};

void Cliente::Cargar(int dni){
    char tex[20],texto[30];

    cout<<"--------------------------------------"<<endl;
    if (dni!=0){
        setDni(dni);
    }else{
        cout<<"INGRESE EL DNI                 :";
        cin>>dni;
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

    cout<<"---------FECHA-DE-NACIMIENTO----------"<<endl;
    _fechaNac.Cargar();
    cout<<"--------------------------------------"<<endl;
}

void Cliente::Mostrar(){
    cout<<"--------------------------------------"<<endl;
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
    cout<<"--------------------------------------"<<endl;
}

//Asociadas a clase Cliente

int buscarPosDni(int dni){
    FILE *pCli;
    Cliente cli;
    int devol=1;
    int i=0;

    pCli=fopen(AR_CLIENTES,"rb");
    if (pCli==NULL){return -2;}

    while (devol==1) {
        devol=fread(&cli ,sizeof(Cliente),1,pCli);
        if (cli.getDni()==dni) {
            return i;
            fclose(pCli);
        }
        i++;
    }
    fclose(pCli);
    return -1;
}

bool cargarEnArchivoCli(){
    FILE *pCli;
    Cliente cli;
    bool escribio;
    int dni;

    pCli=fopen(AR_CLIENTES,"ab");
    if (pCli==NULL){return false;}

    cout<<"INGRESE EL DNI: ";
    cin>>dni;

    if (buscarPosDni(dni)==-1) {
        cli.Cargar(dni);
        escribio=fwrite(&cli ,sizeof(Cliente),1,pCli);
        fclose(pCli);
    }else{
        cout<<"EL DNI INGRESADO YA EXISTE";
        return false;
    }
    return escribio;
}

void mostrarClientesDeArchivo(){
    FILE *pCli;
    Cliente cli;

    pCli=fopen(AR_CLIENTES,"rb");
    if (pCli==NULL){return;}

    while (fread(&cli ,sizeof(Cliente),1,pCli)==1) {
        cli.Mostrar();
    }
    fclose(pCli);
}

void listarDniMayores(int dni){
    FILE *pCli;
    Cliente cli;

    pCli=fopen(AR_CLIENTES,"rb");
    if (pCli==NULL){return;}

    while (fread(&cli ,sizeof(Cliente),1,pCli)==1) {
        if (cli.getDni()>dni) {
            cli.Mostrar();
        }
    }
    fclose(pCli);
}


void listarMenores(Fecha fNac){
    FILE *pCli;
    Cliente cli;

    pCli=fopen(AR_CLIENTES,"rb");
    if (pCli==NULL){return;}

    while (fread(&cli ,sizeof(Cliente),1,pCli)==1) {

        if (cli.getFechaNac().getConsol()<fNac.getConsol()) {
            cli.Mostrar();
        }
    }
    fclose(pCli);
}


#endif // CLSCLIENTE_H_INCLUDED
