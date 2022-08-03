#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#include "clsCliente.h"
#include "clsArticulo.h"
#include "funciones.h"

int main(){

    Articulo arts;
    arts.Mostrar();
    arts.Cargar();
    arts.Mostrar();
    return 0;




    Cliente cli("Pepe");

    while(true){
        int opc;
        cout<<"-------------MENU-------------\n";
        cout<<"OPCION 1: CARGAR CLIENTE      \n";
        cout<<"OPCION 2: MOSTRAR CLIENTES    \n";
        cout<<"OPCION 3: BUSCAR CLIENTE      \n";
        cout<<"OPCION 0: EXIT                \n";
        cout<<"-------------MENU-------------\n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1: cli.Cargar();
                    if(cli.CargarRegistro()!=1){
                        cout<<"ERROR EN CARGA\n";
                        return -1;
                    }else{cout<<"CARGA EXITOSA\n";}
                break;

            default:
                return 0;
                break;
        }
    }


    return 0;
}
