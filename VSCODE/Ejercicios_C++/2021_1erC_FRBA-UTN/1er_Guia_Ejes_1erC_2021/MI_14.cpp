#include <iostream>
using namespace std;

int main () {
 int num=0;
 int i=0;
 int sumPromedio=0;
 int promedio=0;
 int contadorProm=0;
 int sumaNeg=0;

 cout << "Ingrese un numero" << endl;
 cin >> num;

 for (i=0; i<4 ; i++) {
     if (num>100){
         contadorProm=contadorProm+1;
         sumPromedio=sumPromedio+num;
     }

     if (num < -10){
         sumaNeg=sumaNeg+num;
     }
     
     cout << "Ingrese un numero" << endl;
        cin >> num;
 }

 if (contadorProm != 0) {
    promedio = sumPromedio/contadorProm;
    cout << "El promedio de los mayores que 100 es " << promedio << endl;
 }else{
     cout << "No hay mayores a 100" << endl;
 }

cout << "La suma de los menores a -10 es " << sumaNeg;

 return 0;
}
