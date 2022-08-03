#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_D 5

/*
///a) Listar todas las notas
///b) Dado un valor que se ingresa por teclado, informar cuántas veces se repite ese valor
/// dentro de las notas
///c) Listar las notas de los examenes aprobados (mayor igual a 6)
///d) Informar cuántos alumnos aprobaron.
///e) Informar cuántos alumnos desaprobaron
*/

int main () {

    int nota[MAX_D];
    float prom;
    int acu=0;
    int cont=0;
    int cont2=0;
    int contAp=0;
    int contDesAp=0;
    int notaX;
    int max;
    int min;

    //carga del vector
    for (int i=0; i<MAX_D; i++) {
        cout<<"Ingrese una nota"<<endl;
        cin>>nota[i];
        acu+=nota[i];
    }

    prom=(float)acu/(float)MAX_D;

    //cuenta mayores al prom
    for (int i=0; i<MAX_D; i++) {
        if (nota[i]>=prom) {
            cont++;
        }
    }
    cout<<"Cantidad mayor al promedio: "<<endl;

    //Imprime todas las notas
    cout<<"IMPRESION DE TODAS LAS NOTAS"<<endl;
    for (int i=0; i<MAX_D; i++) {
        cout<<nota[i]<<endl;
    }

    //Imprime dado un valor
    cout<<"Ingrese una nota"<<endl;
    cin>>notaX;
    cout<<"CONTADOR DE NOTAS MAYORES A LA INGRESADA"<<endl;
    for (int i=0; i<MAX_D; i++) {
        if (nota[i]==notaX) {
           cont2++;
        }
    }
    cout<<"EL valor ingresado aparece "<<cont2<<" veces"<<endl;

    ///c) Listar las notas de los examenes aprobados (mayor igual a 6)
    cout<<"IMPRESION DE NOTAS APROBADAS"<<endl;
    for (int i=0; i<MAX_D; i++) {
        if (nota[i]>=6) {
            cout<<nota[i]<<endl;
            contAp++;
        }
    }
    ///d) Informar cuántos alumnos aprobaron.
    cout<<"La cantidad de aprobados es: "<<contAp<<endl;

    ///d) Informar cuántos alumnos aprobaron.
    for (int i=0; i<MAX_D; i++) {
        if (nota[i]<6) {
            contDesAp++;
        }
    }
    cout<<"La cantidad de desaprobados es: "<<contDesAp<<endl;

    //MAX
    max=nota[0];
    for (int i=1; i<MAX_D; i++) {
        if (nota[i]>max) {
            max=nota[i];
        }
    }
    cout<<"EL máximo es: "<<max<<endl;

    //MIN
    min=nota[0];
    for (int i=1; i<MAX_D; i++) {
        if (nota[i]<min) {
            min=nota[i];
        }
    }
    cout<<"El mínimo es: "<<min<<endl;

    //system ("cls"); para borrar toda la pantalla
    system("pause");
    return 0;
}