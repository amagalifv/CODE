#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "clsArticulo.h"
#include "funciones.h"

int main () {
    Articulo art[10];
    int opc,aux;

    while(true){
        cout<<"-----------------MENU-----------------\n";
        cout<<"OPCION 1: CARGAR 10 ARTICULOS         \n";
        cout<<"OPCION 2: LISTAR TODOS LOS ARTICULOS  \n";
        cout<<"OPCION 3: BUSCAR POSICION DE ARTICULO \n";
        cout<<"OPCION 4: LISTAR STOCKS INFERIORES A  \n";
        cout<<"OPCION 5: MODIFICAR PRECIOS           \n";
        cout<<"OPCION 0: EXIT                        \n";
        cout<<"--------------------------------------\n";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                cargarDiezArts(art,3);
                break;
            case 2:
                mostrarArts(art,3);
                break;
            case 3:
                char cod[5];
                cout<<"Ingrese el codigo a buscar: ";
                cargarCadena(cod,4);
                aux=buscarCodigo(art,3,cod);
                if (aux!=-1) {
                    cout<<"El codigo se encontro en la posicion "<<aux<<endl;
                } else {cout<<"Codigo no encontrado"<<endl;}
                break;
            case 4:
                cout<<"Ingrese el stock a buscar: ";
                cin>>aux;
                cout<<"---------Productos-Con-Stock-Menor---------\n";
                buscarStockMenor(art,3,aux);
                break;
            case 5:
                cout<<"Ingrese el porcentaje a incrementar(Ej:10): ";
                cin>>aux;
                actualizarPrecio(art,3,aux);
                break;
            default:
                return 0;
                break;
        }
    }

    system("pause");
    return 0;
}
/*
TP 2
Ej 1
Hacer una clase de nombre Articulo con las siguientes propiedades:
Código (char[5]), Descripción (char[30])
Precio (float), Stock(int), Estado(bool)
Y los siguientes métodos:
Cargar()
Mostrar()
Gets() para todas las propiedades
Sets() para todas las propiedades
Un constructor con parámetros por omisión
Un constructor para asignar valor a la descripción

Ej2.
Cargar un vector de 10 Artículos. Luego hacer las siguientes funciones:
a)	Listar todos los artículos del vector.
b)	Listar todos los artículos cuyo precio sea mayor a un valor que se ingresa por teclado.
c)	A partir de un valor de código recibido como parámetro, devolver la posición del objeto que contiene ese código. De no encontrarlo devolver -1.
d)	Dado un valor de stock que se recibe como parámetro devolver la cantidad de artículos cuyo stock sea inferior a ese valor recibido.
e)	Dado un porcentaje de incremento que se recibe como parámetro, modificar el precio unitario de todos los objetos.
Todas las funciones reciben además el vector de Artículos.

Desarrollar el trabajo en un proyecto de software de CodeBlocks. Organizar los ejercicios en un menú.
*/
