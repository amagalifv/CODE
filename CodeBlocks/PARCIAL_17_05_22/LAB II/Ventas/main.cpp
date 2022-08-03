#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#include "prototipos.h"
#include "clsFecha.h"
#include "clsCliente.h"
#include "clsArticulo.h"
#include "clsVentas.h"
#include "Func.h"
#include "funcCli.h"
#include "funcArt.h"
#include "funcVent.h"

int main () {
    int opc;

    while(true){
        cout<<"        MENU PRINCIPAL          \n";
        cout<<"--------------------------------\n";
        cout<<endl;
        cout<<"1) MENU CLIENTES                \n";
        cout<<"2) MENU ARTICULOS               \n";
        cout<<"3) MENU VENTAS                  \n";
        cout<<"4) REPORTES                     \n";
        cout<<"5) CONFIGURACION                \n";
        cout<<"--------------------------------\n";
        cout<<"0) FIN DEL PROGRAMA             \n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                menuClientes();
                break;
            case 2:
                menuArticulos();
                break;
            case 3:
                menuVentas();
                break;
            case 4:
                return 4;
                break;
            case 5:
                return 5;
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