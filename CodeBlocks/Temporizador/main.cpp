#include <iostream>
using namespace std;
#include "Temporizador.h"

int main(){

    Temporizador a(23,25,15);
    a.mostrar();

    cout<<"ldhf�ksjhsrg"<<endl;

    return 0;
}

/*
Realizar una clase llamada Temporizador que permita almacenar segundos, minutos y horas.

a) Deber� tener un  CONSTRUCTOR que pueda recibir tres enteros y establezca los valores de segundos,minutos y horas  ( en caso de ser valores v�lidos de lo contrario asignar� 0:0:0)

b)  Deber� tener un  CONSTRUCTOR que no reciba parametros y establezca los valores iniciales del temporizador en 0:0:0

c) Deber� tener un m�todo llamado MOSTRAR que muestre el tiempo con el siguiente formato 00:00:00

d) Deber� tener un m�todo llamado setTipo que definira como gestrionara el tiempo:
Tipo 1 - Aumenta un segundo por tic
Tipo 2 - Disminuye un segundo por tic

e) Deber� tener un m�todo llamado tic que realice el paso del tiempo

f) Deber� tener un m�todo llamado COMPARAR QUE reciba otro objeto del tipo Temporizador y devuelva un n�mero entero a partir de las siguientes condiciones:
0 ----> Si ambos temporizadores don IGUALES
1 ----> Si el objeto recibido como parametro regidtra un MENOR tiempo
-1----> Si el objeto recibido como parametro regidtra un MAYOR tiempo
*/
