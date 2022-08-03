#include <iostream>
#include <stdio.h>
#include<stdlib.h>

using namespace std;

#include "funciones.h"
/*
Las materias que no tuvieron acceso de alumnos nunca
La materia que más cantidad de horas registro de acceso de alumnos
Por cada materia y día de marzo, la cantidad de alumnos que ingresaron a las aulas virtuales.
*/


///Número de materia ( 1 a 20), nombre , cantidad docentes, cantidad de alumnos



int main(){
    float horas[20]={0};
    int matDia[20][31];
    ponerCeroMatriz(matDia, 20, 31);
    char materias[20][30];
    int opc;
    while(true){
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"-----------------------"<<endl;
        cout<<"1. INGRESO MATERIAS"<<endl;
        cout<<"2. INGRESO MATERIAS"<<endl;
        cout<<"3. INGRESO DE ACCESOS"<<endl;
        cout<<"4. MATERIAS SIN ACCESOS"<<endl;
        cout<<"5. MATERIA CON MAS ALUMNOS"<<endl;
        cout<<"6. ESTADISTICAS MARZO"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cargarMaterias(materias);
                    break;
            case 2: mostrarMatrizCaracteres(materias, 5);
                    break;
            case 3: ingresarDatosAccesos(horas, matDia);
                    break;
            case 4: puntoA(horas);
                    break;
            case 5: puntoB(horas);
                    break;
            case 6: puntoC(matDia);
                    break;
            case 0: return 0;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
        }
        system("pause");
    }
    return 0;
}
