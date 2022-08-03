#include <iostream>
using namespace std;

int main () {
 int tirosDeRuleta;
 int num=0;
 string color;
 string colorAnterior="blanco";
 int numAnterior=0;
 int contadorCero=0;
 int anteriorCeroNum=0;
 string anteriorCeroColor;
 int contadorNegro=0;
 int contadorNegroAux=1;
 int numMasRepetido=0;
 int contadorNumMasRepetido=0;
 int contadorNumMasRepetidoAux=1;
 int contadorAlternColor=0;
 int contadorAlternColorAux=1;
 int segundaDocenaAux=1;
 int segundaDocena=1;
 

 cout << "Ingrese la cantidad de tiros de ruleta a ingresar"<< endl;
 cin >> tirosDeRuleta;

 for (int i=0 ; i<tirosDeRuleta ; i++) {
     cout << "Ingrese el número que salió en la ruleta" << endl;
     cin >> num;
     cout << "Ingrese el color respectivo al número anterior" << endl; 
     cin >> color;

     if(num==0){
         contadorCero++;
         anteriorCeroNum=numAnterior;
         anteriorCeroColor=colorAnterior;

         if(colorAnterior == "blanco"){
           cout << "Este fue el  primer 0 ingresado" << endl;  
         }else{
             cout << "El número " << anteriorCeroNum << " " << anteriorCeroColor << " fue el anterior al 0" << endl;
         }
     }

     if (color =="negro" && colorAnterior =="negro"){
         contadorNegroAux++;

         if (contadorNegroAux>contadorNegro){
             contadorNegro=contadorNegroAux;
         } 
     }else{
         contadorNegroAux=1;
     }

     if (num==numAnterior){
         contadorNumMasRepetidoAux++;
         numMasRepetido=num;

         if(contadorNumMasRepetidoAux>contadorNumMasRepetido){
             contadorNumMasRepetido=contadorNumMasRepetidoAux;
         } 
     }else{
         contadorNumMasRepetidoAux=1;
     }

     if(color == "rojo" && colorAnterior=="negro" || color == "negro" && colorAnterior=="rojo"){
       contadorAlternColorAux++;

        if (contadorAlternColorAux>contadorAlternColor){
            contadorAlternColor=contadorAlternColorAux;
        }
     } else {
         contadorAlternColorAux=1;
     }

     if(num<25 && num>12){
         segundaDocenaAux++;

         if(segundaDocenaAux>segundaDocena){
             segundaDocena=segundaDocenaAux;
         }
     }else{
         segundaDocenaAux=1;
     }

     numAnterior=num;
     colorAnterior=color;
}

 cout << "El cero salió " << contadorCero << " veces " << endl;
 cout << "El negro llegó a repetirse " << contadorNegro << " veces seguidas" << endl;
 cout << "El número " << numMasRepetido << " llegó a repetirse " << contadorNumMasRepetido << " veces seguidas" << endl;
 cout << "El mayor número de veces que salió allternado el color rojo-negro o viceversa es " << contadorAlternColor << endl;
 cout << "El mayor número de veces que se negó la segunda docena es " << segundaDocena << endl;

 system("pause");
 return 0;
}
