///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cstring>


/*
Hacer un proyecto de nombre Clientes, para gestionar un archivo de clientes con el formato
visto en el ejercicio anterior.

El programa debe tener las siguientes opciones de men�

1. AGREGAR CLIENTE
2- LISTAR CLIENTES
0- FIN DEL PROGRAMA

La opci�n 1 agrega 1 registro al archivo de clientes; la opci�n 2 lista todo el archivo de clientes.

*/

using namespace std;

# include "fecha.h"
# include "cliente.h"
# include "func_clientes.h"


int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"-------MENU CLIENTES--------"<<endl;
        cout<<"1. AGREGAR CLIENTE"<<endl;
        cout<<"2- LISTAR CLIENTES"<<endl;
        cout<<"3- LISTAR CLIENTES DINAMICO"<<endl;
        cout<<"0- FIN DEL PROGRAMA"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: if(agregarCliente()==1)cout<<"REGISTRO AGREGADO";
                    else cout<<"NO SE PUDO AGREGAR EL REGISTRO";
                    break;
            case 2: listarClientes();
                    break;
            case 3: listarClientesDinamico();
                    break;
            case 4: listarClientesDNI();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;
        system("pause");
    }

    return 0;
}
