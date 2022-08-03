#include <iostream>
using namespace std;

typedef struct{
    int dia;
    int mes;
    int anio;
}ST_FECHA_NAC;

typedef struct{
    string apellido;
    string nombre;
}ST_APELL_NOMBRE;

typedef struct {
    ST_APELL_NOMBRE nombreCompleto;
    ST_FECHA_NAC fechaNacimiento;
    int legajo;

}ST_PERS;

void cargarFechaNac (ST_FECHA_NAC fechaNac){
     
     cout<<"Ingrese su dia de nacimiento "<<endl;
     cin>>fechaNac.dia;
     cout<<endl;

     cout<<"Ingrese el mes de su nacimiento "<<endl;
     cin>>fechaNac.mes;
     cout<<endl;

     cout<<"Ingrese el año su de nacimiento "<<endl;
     cin>>fechaNac.anio;
     cout<<endl;

 return;
}

void cargarApellNombre (ST_APELL_NOMBRE nombreEst) {
     cout<<"Ingrese su nombre "<<endl;
     cin>>nombreEst.nombre;
     cout<<endl;

     cout<<"Ingrese su apellido "<<endl;
     cin>>nombreEst.apellido;
     cout<<endl;

 return;
}

void imprimirDatosPers (ST_PERS persona){
    cout<<"El numero de legajo es: "<<persona.legajo<<endl;
    cout<<"Apellido y Nombre: "<<persona.nombreCompleto.apellido<<", "<<persona.nombreCompleto.nombre<<endl;
    cout<< "Su fecha de nacimieto es: " << persona.fechaNacimiento.dia<<"/"<< persona.fechaNacimiento.mes<< "/" << persona.fechaNacimiento.anio<<endl;

    return;
}

int main () {
 
 ST_FECHA_NAC fechaNac;
 ST_APELL_NOMBRE nombreEst;
 ST_PERS persona;

 cargarFechaNac(fechaNac);
 cargarApellNombre(nombreEst);
 
 cout<<"Ingrese el numero de legajo de la persona"<<endl;
 cin>>persona.legajo;
 
 imprimirDatosPers(persona);
 
 system("pause");
 return 0;
}