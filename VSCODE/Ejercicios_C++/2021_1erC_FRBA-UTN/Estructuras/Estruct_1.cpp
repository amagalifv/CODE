#include <iostream>
using namespace std;

typedef struct {
    int legajo;
    string apellidoNombre;
    float nota;
} ST_ALUMNO;

void cargarDatos(ST_ALUMNO &alumno){
    cout<< "Ingrese el  numero de legajo del alumno";
    cin>>alumno.legajo;
    cout<<endl;
    
    cout<< "Ingrese el  apellido y nombre del alumno";
    cin>>alumno.apellidoNombre;
    cout<<endl;
 
    cout<< "Ingrese la nota del alumno";
    cin>>alumno.nota;
    cout<<endl;
}

void impEstr (ST_ALUMNO &alumno){
    cout<< "Alumno: "<< alumno.apellidoNombre<<endl;
    cout<< "Legajo: "<< alumno.legajo <<endl;
    cout<< "Nota: "<< alumno.nota <<endl;
}

int main () {

 ST_ALUMNO alumno;

 cargarDatos(alumno);
 impEstr (alumno);
 
 system("pause");
 return 0;
}