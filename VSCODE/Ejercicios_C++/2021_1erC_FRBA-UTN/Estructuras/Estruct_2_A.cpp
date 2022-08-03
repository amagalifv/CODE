#include <iostream>
using namespace std;

typedef struct{
    int dia;
    int mes;
    int anio;
}ST_FECHA_NAC;

typedef struct {
    string nombre;
    ST_FECHA_NAC fechaNac;
}ST_PERS;

void cargarEstructura (ST_PERS persona){
     
     cout<<"Ingrese su dia de nacimiento "<<endl;
     cin>>persona.fechaNac.dia;
     cout<<endl;

     cout<<"Ingrese el mes de su nacimiento "<<endl;
     cin>>persona.fechaNac.mes;
     cout<<endl;

     cout<<"Ingrese el año su de nacimiento "<<endl;
     cin>>persona.fechaNac.anio;
     cout<<endl;

      cout<<"Ingrese el nombre de la persona"<<endl;
      cin>>persona.nombre;
      cout<<endl;

 return;
}

int main () {
 
 ST_FECHA_NAC fechaNac;
 ST_PERS persona;

 cargarEstructura(persona);
 
 system("pause");
 return 0;
}