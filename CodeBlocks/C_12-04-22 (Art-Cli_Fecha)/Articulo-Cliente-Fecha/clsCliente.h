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
        void Cargar();
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

void Cliente::Cargar(){
    int dni;
    char tex[20],texto[30];

    cout<<"--------------------------------------"<<endl;
    cout<<"INGRESE EL DNI                 :";
    cin>>dni;
    setDni(dni);

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

void cargarDiezClis(Cliente *v,int tam){

    for (int i=0; i<tam; i++) {
        v[i].Cargar();
    }
}

void mostrarClis(Cliente *v,int tam){

    for (int i=0; i<tam; i++) {
        v[i].Mostrar();
    }
}

void listarDniMayores(Cliente *v,int tam, int dni){

    for (int i=0; i<tam; i++) {

        if(v[i].getDni()>dni){
            v[i].Mostrar();
        }
    }
}

int buscarPosDni(Cliente *v,int tam, int dni){

    for (int i=0; i<tam; i++) {

        if(v[i].getDni()==dni){
            return i;
        }
    }
    return -1;
}

void listarMenores(Cliente *v,int tam, Fecha fNac){

    for (int i=0; i<tam; i++) {
        if (v[i].getFechaNac().getConsol()<fNac.getConsol()) {
            v[i].Mostrar();
        }
    }
}


#endif // CLSCLIENTE_H_INCLUDED
