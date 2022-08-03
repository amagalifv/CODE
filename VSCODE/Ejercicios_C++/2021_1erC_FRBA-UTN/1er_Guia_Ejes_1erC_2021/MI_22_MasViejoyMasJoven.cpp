#include <iostream>
using namespace std;

int main () {
 string nombre;
 string nombreMasJoven;
 string nombreMasGrande;
 int fechaNac;
 int masJoven=0;
 int masGrande=0;
 
 cout << "Ingrese el nombre de la persona, FIN para terminar" << endl;
 cin >> nombre;

 while ( nombre != "FIN"){
     cout << "Ingrese la respectiva fecha de nacimiento con el formato AAAAMMDD" << endl;
     cin>> fechaNac;


     if(fechaNac<masGrande || masGrande==0){
         masGrande=fechaNac;
         nombreMasGrande=nombre;
     }

     if(fechaNac>masJoven || masJoven==0){
         masJoven=fechaNac;
         nombreMasJoven=nombre;
     }
     
     cout << "Ingrese el nombre de la persona, FIN para terminar" << endl;
     cin >> nombre; 
 }

 cout << "La persona con mayor edad es " << nombreMasGrande << endl;
 cout << "La persona con menor edad es " << nombreMasJoven << endl;

 system("pause");
 return 0;
}