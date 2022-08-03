#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "clsFecha.h"

/*
los socios menores que no se hayan inscripto en el 2020
DNI, nombre y apellido..
*/

class Socio{
    private:
        int _dni;
        char _nombre[30];
        char _apellido[30];
        char _email[40];
        char _telefono[20];
        int _tipo, _localidad;
        bool _estado;
    public:
        Socio(int dni=0, const char *nom="AAAA", const char *ape="AAAA", const char *email="aa@aa.aa",const char *tel="0"){//FALTA FECHA
            _dni=dni;
            strcpy(_apellido, ape);
            strcpy(_nombre, nom);
            strcpy(_email, email);
           strcpy(_telefono, tel);
           //_tipo, _localidad _estado;
        }
        void Cargar();
        void Mostrar();
        bool leerDeDisco(int);
        bool grabarEnDisco();
        //GETS
        int getDni(){return _dni;}
        const char *getApellido(){return _apellido;}
        const char *getNombre(){return _nombre;}
        const char *getEmail(){return _email;}
        const char *getTelefono(){return _telefono;}
        bool getEstado(){return _estado;}
        int getTipoSoc();
        // SETS
        void setDni(int dni){_dni=dni;}
        void setApellido(char nom[30]){strcpy(_apellido, nom);}
        void setNombre(char nom[30]){strcpy(_nombre, nom);}
        void setEmail(char nom[30]){strcpy(_email, nom);}
        void setTelefono(char tel[25]){strcpy(_telefono,tel);}
};

class Club{
    private:
        int _numero;
        int _disciplina, _anio, _localidad;
        char _nombre[45];
        int _dniPresidente;
        bool _estado;
    public:
        void Cargar();
        void Mostrar();
        bool leerDeDisco(int);
        bool grabarEnDisco();
        // GETS
        // SETS
};

class Inscripcion{
    private:
        int _dniSocio;
        int _numeroClub;
        int _tipoInscripcion;
        Fecha _fecha_inscripcion;
        bool _estado;
    public:
        bool leerDeDisco(int);
        bool grabarEnDisco();
        // GETS
        int getDni(){return _dniSocio;}
        bool getEstado(){return _estado;}
        Fecha getFechaInsc();
        // SETS
};

void Socio::Mostrar(){
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
    cout<<endl;
    ///siguen mas
}

#endif // CLASES_H_INCLUDED
