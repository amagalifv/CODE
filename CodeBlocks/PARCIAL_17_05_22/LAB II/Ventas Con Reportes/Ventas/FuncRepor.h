#ifndef FUNCREPOR_H_INCLUDED
#define FUNCREPOR_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "prototipos.h"
#include "clsCliente.h"
#include "clsArticulo.h"
#include "clsVentas.h"


int menuReportes () {
    int opc;


    while(true){

        cout<<"                 MENÚ REPORTES              \n";
        cout<<"--------------------------------------------\n";
        cout<<endl;
        cout<<"1) MOSTRAR POR CADA CLIENTE LA CANTIDAD     \n";
        cout<<"DE VENTAS REGISTRADAS A ESE CLIENTE         \n";
        cout<<endl;
        cout<<"2) INFORMAR LA CANTIDAD DE CLIENTES         \n";
        cout<<"ACTIVOS Y LA CANTIDAD DE CLIENTES INACTIVOS \n";
        cout<<endl;
        cout<<"---------------------------------------------\n";
        cout<<"0) VOLVER AL MENÚ PRINCIPAL                  \n";


        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cout<<"En construccion...";
                break;
            case 2:
                cout<<"En construccion...";
                break;
            default:
                return 0;
                break;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }


    system("pause");
    return 0;
}


#endif // FUNCREPOR_H_INCLUDED
