#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED

#include <cstring>
#include "clsFecha.h"

class Cliente{
    private:
        int _dni;
        Fecha _fechaNac ;
        char _apellido[20];
        char _nombre[20];
        char _email[30];
        char _telefono[25];
    public:
        Cliente(int dni=0, const char *ape="AAAA", const char *nom="AAAA",const char *email="aa@aa.aa",const char *tel="0"){//FALTA FECHA
            strcpy(_apellido, ape);
            strcpy(_nombre, nom);
            strcpy(_email, email);
           strcpy(_telefono, tel);
        }
        Cliente(char nom[30]){ _nombre[30] = nom[30];}
        void Cargar();
        void Mostrar();
        int CargarRegistro();
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
    int dni,tel;
    char tex[20],texto[30];

    cout<<"INGRESE EL DNI                 :";
    cin>>dni;
    setDni(dni);

    cout<<"INGRESE EL APELLIDO            :";
    cin.getline(tex, 20);
    setApellido(tex);

    cout<<"INGRESE EL NOMBRE              :";
    cin.getline(tex, 20);
    setNombre(tex);

    cout<<"INGRESE EL EMAIL               :";
    cin.getline(texto, 30);
    setEmail(texto);

    cout<<"INGRESE EL TELEFONO            :";
    cin.getline(texto,25);
    setTelefono(texto);

    cout<<"INGRESE LA FECHA DE NACIMIENTO :";
    _fechaNac.Cargar();
}

void Cliente::Mostrar(){
    cout<<"DNI                 :";
    cout<<getDni<<endl;
    cout<<"FECHA               :";
    _fechaNac.Mostrar();
    cout<<"APELLIDO            :";
    cout<<getApellido<<endl;
    cout<<"NOMBRE              :";
    cout<<getNombre<<endl;
    cout<<"EMAIL               :";
    cout<<getEmail<<endl;
    cout<<"TELEFONO            :";
    cout<<getTelefono<<endl;
    cout<<"FECHA DE NACIMIENTO :";
    _fechaNac.Mostrar();
}

int Cliente::CargarRegistro(){
    FILE *pCli;
    int siEscrib;
    Cliente reg;

    pCli=fopen("clientes.dat", "ab");
    if (pCli==NULL) {
        return -2;
    }

    reg.Cargar();

    if (buscarRegistros(this->getDni())==-1) {
        siEscrib=fwrite(this, sizeof (Cliente), 1, pCli);
        fclose(pCli);

        return siEscrib;
    }else{
        cout<<"Registro ya existente";
    }

    fclose(pCli);
    return -1;
}

#endif // CLSCLIENTE_H_INCLUDED
