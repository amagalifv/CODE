#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "prototipos.h"
#include "clsArticulo.h"
#include "clsFecha.h"
#include "clsCliente.h"
#include "funciones.h"

int main () {
    int opci;
    while(true){
    cout<<"---------------MENU--------------\n";
    cout<<"OPCION 1: MENU ARTICULOS         \n";
    cout<<"OPCION 2: MENU CLIENTES          \n";
    cout<<"OPCION 0: EXIT                   \n";
    cout<<"---------------------------------\n";
    cin>>opci;
    system("cls");

        switch(opci){

            case 1:
                menuArticulo();
                break;
            case 2:
                menuCliente();
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
--1.	Hacer una clase de nombre Articulo con las siguientes propiedades:
Código (char[5]), Descripción (char[30])
Precio (float), Stock(int), Estado(bool)

Y los siguientes métodos:
Cargar()
Mostrar()
Gets() para todas las propiedades
Sets() para todas las propiedades
Un constructor con parámetros por omisión
Un constructor para asignar valor sólo a la descripción

--2.	A partir de la clase Articulo del ejercicio anterior desarrollar las siguientes funciones:
a)    Cargar un vector de 10 artículos
b) Listar todos los artículos del vector.
c)     Listar todos los artículos cuyo precio sea mayor a un valor que se ingresa por teclado.
d)      A partir de un valor de código recibido como parámetro, devolver la posición del objeto que contiene ese código. De no encontrarlo devolver -1.
e)    Igual a la función del punto anterior, pero debe devolver el objeto completo que contiene el código. De no encontrar el código la función debe devolver un objeto Articulo con un valor de -1 en el precio unitario.
f)     Dado un valor de stock que se recibe como parámetro devolver la cantidad de artículos cuyo stock sea inferior a ese valor recibido.
g)     Dado un porcentaje de incremento que se recibe como parámetro, modificar el precio unitario de todos los objetos.
Todas las funciones reciben el vector de Articulos y la cantidad de elementos del vector, además de los parámetros específicos.
Desarrollar un proyecto de CodeBlock con un menú que llame a cada una de las funciones.

--3. Hacer una clase de nombre Fecha con las siguientes propiedades:
Día
Mes
Año
Y los siguientes métodos:
Cargar()
Mostrar()
gets() para todas las propiedades
sets() para todas las propiedades
Un constructor con valores por omisión para los parámetros.

--4. Hacer una clase de nombre Cliente con las siguientes propiedades:
DNI
Fecha de nacimiento
Nombre
Apellido
Email
Teléfono

Y los siguientes métodos:
Cargar()
Mostrar()
gets() para todas las propiedades
sets() para todas las propiedades
Un constructor con valores por omisión para los parámetros.
Un constructor para asignar valor sólo a la propiedad nombre.
La propiedad fecha de nacimiento debe ser un objeto de la clase Fecha

--5. A partir de la clase Cliente del ejercicio anterior desarrollar las siguientes funciones:
a)    Cargar un vector de 10 clientes
b) Listar todos los artículos del vector.
c)     Listar todos los clientes cuyo DNI sea mayor a un valor que se ingresa por teclado.
d)      A partir de un valor de DNI recibido como parámetro, devolver la posición del objeto que contiene ese DNI. De no encontrarlo devolver -1.
e)    Igual a la función del punto anterior, pero debe devolver el objeto completo que contiene el DNI. De no encontrar el código la función debe devolver un objeto Cliente con un valor de -1 en el DNI.
f)     Dado una fecha que se recibe como parámetro devolver la cantidad de clientes cuyo nacimiento sea anterior a ese valor recibido.

Todas las funciones reciben el vector de Clientes y la cantidad de elementos del vector, además de los parámetros específicos.
Desarrollar un proyecto de CodeBlock con un menú que llame a cada una de las funciones.

*/