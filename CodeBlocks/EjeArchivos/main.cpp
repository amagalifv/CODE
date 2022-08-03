#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "clsEmpresas.h"

int main () {
    int opc;

    Empresa obj;
    obj.Mostrar();
    obj.Cargar();
    //obj.cargarEnArchivo();
    obj.Mostrar();
    return 0;


    while (true) {
        cout<<"----------------------------MENU----------------------------"<<endl;
        cout<<"OPCION 1: LISTAR LA CANTIDAD DE EMPRESAS DE CADA MUNICIPIO"<<endl;
        cout<<"OPCION 2: LISTAR EMPRESAS CON MAS DE 200 EMPLEADOS"<<endl;
        cout<<"OPCION 3: MOSTRAR LA CATEGORIA DE EMPRESA CON MÁS EMPLEADOS"<<endl;
        cout<<"OPCION 0: SALIR "<<endl;
        cout<<"------------------------------------------------------------"<<endl;
        cin>>opc;

        switch (opc) {

            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            default:
                break;
        }
    }


    system("pause");
    return 0;
}

