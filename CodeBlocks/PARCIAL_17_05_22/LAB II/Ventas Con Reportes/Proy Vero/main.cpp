#include <iostream>
#include <cstdlib>
#include <cstring>

//paquete de idiomas
#include <locale>
#include <windows.h>

//Bibliotecas
#include "ArticuloGlobales.h"
#include "VentaGlobales.h"
#include "ClienteGlobales.h"
#include "ReporteGlobales.h"
#include "ConfiguracionGlobales.h"
#include "funciones.h"

using namespace std;

int main()
{
    /////setlocale(LC_ALL, "Spanish_Argentina.850" );
    //setlocale(LC_ALL, "spanish.850");
    // Cambia la salida
    //SetConsoleOutputCP(1255);
    //SetConsoleOutputCP(850);

    ////locale::global(("spanish"))

    // Y la entrada
    //SetConsoleCP(850);
    //setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para máquinas Linux

    ////cout<<"ñññáá´"<<endl;
    ////system("pause");

    int opc;

    while(true){
        system("cls");
        cout<<"****** MENU PRINCIPAL ******"<<endl<<endl;
        cout<<"1. MENU CLIENTES"<<endl;
        cout<<"2. MENU ARTICULOS"<<endl;
        cout<<"3. MENU VENTAS"<<endl;
        cout<<"4. REPORTES"<<endl;
        cout<<"5. CONFIGURACION"<<endl;
        cout<<"****************************"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl<<endl;
        cout<<"SELECCIONES UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");

        switch(opc){
            //1. MENU CLIENTES
            case 1: menuClientes();
                break;

            //2. MENU ARTICULOS
            case 2: menuArticulos();
                break;

            //3. MENU VENTAS
            case 3: menuVentas();
                break;

            //4. MENU REPORTES
            case 4: menuReportes();
                break;

            //5. MENU CONFIGURACION
            case 5: menuConfiguracion();
                break;

            case 0:
                return 0;

            default:
                break;
        }
    }
    return 0;
}

