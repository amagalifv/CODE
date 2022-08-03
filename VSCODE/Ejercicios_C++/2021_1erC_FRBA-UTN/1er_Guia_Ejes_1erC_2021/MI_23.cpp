#include <iostream>
using namespace std;

int main () {
 
float num;
float maximoNeg=0;
float minimoPos=0;
float numMinRango=0;
float sumaPromedio=0;
float iPromedio=0;
float promedio=0;

 cout << "Ingrese un valor" << endl;
 cin >> num;
 
 while(num != 0){
     sumaPromedio=sumaPromedio+num;
     iPromedio++;

     if (num>0){
         if(num<minimoPos || minimoPos==0){
             minimoPos=num;
         }
     } else{
         if (num>maximoNeg || maximoNeg==0){
             maximoNeg=num;
         }
     }

     if (num < 26.9 && num < -17.3){
         if(num<numMinRango || numMinRango==0){
             numMinRango=num;
         }
     }

     cout << "Ingrese un valor" << endl;
     cin >> num;

 }

 if (iPromedio>0){
     promedio=sumaPromedio/iPromedio;
     cout << "El valor maximo negativo ingresado es: " << maximoNeg << endl;
     cout << "El valor minimo positivo ingresado es: " << minimoPos << endl;
     cout << "El promedio de los numeros ingresados es: " << promedio << endl;
     cout << "El menor valor ingresado entre -17.3 y 26.9 es " << numMinRango << endl;
 } else {
     cout << "No se ingresaron numeros" << endl;
 }


 system("pause");
 return 0;
}