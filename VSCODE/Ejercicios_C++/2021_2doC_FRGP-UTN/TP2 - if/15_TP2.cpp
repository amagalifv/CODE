#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
15- Hacer un programa para ingresar por teclado la fecha de nacimiento de una persona,
ingresando día, mes y año como 3 datos individuales. Luego ingresar la fecha actual
ingresando día, mes y año como 3 datos individuales. Calcular luego la edad en años de esa
persona y listarlo por pantalla.
Ejemplo 1. Si se ingresa como fecha de nacimiento: 3/12/2000 y la fecha actual es 26/2/2019
la edad de esa persona es 18 ya que los 19 recién los cumple en diciembre.
Ejemplo 2. Si se ingresa como fecha de nacimiento: 3/1/2000 y la fecha actual es 26/2/2019 la
edad de esa persona es 19.
Ejemplo 3. Si se ingresa como fecha de nacimiento: 28/2/2000 y la fecha actual es 26/2/2019
la edad de esa persona es 18 ya que le faltan 2 días para cumplir los 19 años.
*/

int main () {
    int dia;
    int mes;
    int anio;
    int diaAc;
    int mesAc;
    int anioAc;
    int consolid;
    int consolidAc;
    int edad;

    cout<<"Ingrese dia de nac"<<endl;
    cin>>dia;
    cout<<"Ingrese mes de nac"<<endl;
    cin>>mes;
    cout<<"Ingrese año de nac"<<endl;
    cin>>anio;
    cout<<"Ingrese dia actual"<<endl;
    cin>>diaAc;
    cout<<"Ingrese mes actual"<<endl;
    cin>>mesAc;
    cout<<"Ingrese año actual"<<endl;
    cin>>anioAc;

    consolid=anio*10000+mes*100+dia;
    consolidAc=anioAc*10000+mesAc*100+diaAc;

    edad=(consolidAc-consolid)/10000;

    cout<<"Edad: "<<edad<<endl;

    system("pause");
    return 0;
}