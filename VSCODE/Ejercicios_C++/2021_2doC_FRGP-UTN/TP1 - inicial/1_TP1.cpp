#include <iostream>
using namespace std;

/*
Hacer un programa para ingresar por teclado la cantidad de horas trabajadas por un
operario y el valor que se le paga por hora trabajada y listar por pantalla el sueldo que le
corresponda.
*/

int main () {

    int cantHsTrab;
    float valorHora;
    float sueldo=0;

    cout <<"Ingrese la cantidad de horas trabajadas: "<< endl;
    cin>> cantHsTrab;

    cout <<"Ingrese el valor por hora: "<< endl;
    cin>> valorHora;

    sueldo=cantHsTrab*valorHora;

    cout<<"El sueldo para los datos ingresados es: "<<sueldo<< endl;

    system("pause");
    return 0;
}