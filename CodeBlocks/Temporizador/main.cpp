#include <iostream>
using namespace std;
#include "Temporizador.h"

int main(){

    Temporizador a(23,25,15);
    a.mostrar();

    cout<<"ldhfñksjhsrg"<<endl;

    return 0;
}

/*
Realizar una clase llamada Temporizador que permita almacenar segundos, minutos y horas.

a) Deberá tener un  CONSTRUCTOR que pueda recibir tres enteros y establezca los valores de segundos,minutos y horas  ( en caso de ser valores válidos de lo contrario asignará 0:0:0)

b)  Deberá tener un  CONSTRUCTOR que no reciba parametros y establezca los valores iniciales del temporizador en 0:0:0

c) Deberá tener un método llamado MOSTRAR que muestre el tiempo con el siguiente formato 00:00:00

d) Deberá tener un método llamado setTipo que definira como gestrionara el tiempo:
Tipo 1 - Aumenta un segundo por tic
Tipo 2 - Disminuye un segundo por tic

e) Deberá tener un método llamado tic que realice el paso del tiempo

f) Deberá tener un método llamado COMPARAR QUE reciba otro objeto del tipo Temporizador y devuelva un número entero a partir de las siguientes condiciones:
0 ----> Si ambos temporizadores don IGUALES
1 ----> Si el objeto recibido como parametro regidtra un MENOR tiempo
-1----> Si el objeto recibido como parametro regidtra un MAYOR tiempo
*/
