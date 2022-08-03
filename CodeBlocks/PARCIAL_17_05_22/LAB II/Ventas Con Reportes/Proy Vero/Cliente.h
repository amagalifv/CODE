#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "Fecha.h"
#include "funciones.h"

using namespace std;

class Cliente{

private:
    int _dni;
    char _nombre[20]={0};
    char _apellido[20]={0};
    char _email[30]={0};
    char _telefono[25]={0};
    Fecha _fechaNac;
    bool _estado;

public:
    ///CONSTRUCTOR CON VALORES POR OMISIÓN
    Cliente(int pDni=0, const char *pNombre="vacio", const char *pApellido="vacio", const char *pEmail="vacio", const char *pTelefono="vacio", Fecha pFechaNac=0, bool pEstado=true){
        _dni=pDni;
        strcpy(_nombre,pNombre);
        strcpy(_apellido,pApellido);
        strcpy(_email,pEmail);
        strcpy(_telefono,pTelefono);
        _fechaNac=pFechaNac;
        _estado=pEstado;
    }

    ///SETTERS
    void setDni(int pDni){_dni=pDni;}
    void setNombre(const char *pNombre){strcpy(_nombre,pNombre);}
    void setApellido(const char *pApellido){strcpy(_apellido,pApellido);}
    void setEmail(const char *pEmail){strcpy(_email, pEmail);}
    void setTelefono(const char *pTelefono){strcpy (_telefono, pTelefono);}
    void setFechaNac(Fecha pFecha){_fechaNac=pFecha;}
    void setEstado(bool pEstado){_estado=pEstado;}

    ///GETTERS
    int getDni(){return _dni;}
    const char *getNombre(){return _nombre;}
    const char *getApellido(){return _apellido;}
    const char *getEmail(){return _email;}
    const char *getTelefono(){return _telefono;}
    Fecha getFechaNac(){return _fechaNac;}
    int getEstado(){return _estado;}

    ///METODOS
    void Cargar(int dni=-1);
    void Mostrar();
    int leerDeDisco(int pos);
    int grabarEnDisco(int pos=0);

};

///FUNCIONES DE LA CLASE CLIENTE
void Cliente::Cargar(int dni){
    char auxChar[20]={0};
    int auxInt=0;

    if(dni==0){
        cout<<"DNI:  ";
        cin>>auxInt;
        setDni(auxInt);
    }
    else{
        setDni(dni);
    }
    cout<<"NOMBRE: ";
    cargarCadena(auxChar,20);
    setNombre(auxChar);

    cout<<"APELLIDO: ";
    cargarCadena(auxChar,20);
    setApellido(auxChar);

    cout<<"EMAIL: ";
    cargarCadena(auxChar,20);
    setEmail(auxChar);

    cout<<"TELEFONO: ";
    cargarCadena(auxChar,20);
    setTelefono(auxChar);

    _fechaNac.CargarNacimiento();

    setEstado(1);

    cout<<endl;

}
void Cliente::Mostrar(){

    cout<<"DNI:  "<<getDni()<<endl;
    cout<<"NOMBRE: "<<getNombre()<<endl;
    cout<<"APELLIDO: "<<getApellido()<<endl;
    cout<<"EMAIL: "<<getEmail()<<endl;
    cout<<"TELEFONO: "<<getTelefono()<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    _fechaNac.Mostrar();
    cout<<"ESTADO: "<<getEstado()<<endl<<endl;
}
int Cliente::leerDeDisco(int pos){
    /******************************************
     Valores que retorna leerDeDisco(int pos):
     -1: NO ENCONTRÓ EL ARCHIVO
      1: LEYO EL ARCHIVO
      2:
    ******************************************/
    FILE *archivo;
    int leyo=-1;

    archivo=fopen("Clientes.dat","rb");

    if(archivo==NULL){
        return -1;
    }

    fseek(archivo, pos*sizeof(Cliente), 0);
    leyo=fread(this, sizeof(Cliente), 1, archivo);

    fclose(archivo);
    return leyo;
}
int Cliente::grabarEnDisco(int pos){
    /******************************************
     Valores que retorna grabarEnDisco(int pos):
     -1: NO PUDO GRABAR EN EL ARCHIVO
      1: ESCRIBIÓ EL ARCHIVO
      2:
    ******************************************/
FILE *archivo;
    int escribio;

    if(pos==-1){
        archivo=fopen("Clientes.dat", "ab");
        if(archivo==NULL){
            return -1;
        }
    }
    else{
        archivo=fopen("Clientes.dat", "rb+");
        if(archivo==NULL){
            return -1;
        }
        fseek(archivo, sizeof(Cliente)*pos, 0);
    }

    escribio=fwrite(this, sizeof(Cliente), 1, archivo);
    fclose(archivo);
    return escribio;
}
///FIN FUNCIONES DE LA CLASE CLIENTE

#endif // CLIENTE_H_INCLUDED
