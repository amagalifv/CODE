#include <iostream>
using namespace std;

bool esNumeroPrimo (int num);

int main () {
 int numeroEnt;
 int numAnterior=0;
 int cantIterac=0;
 int contAscendente=0;
 int contDescendente=0;

 cout << "Ingrese un numero" <<endl;
 cin >> numAnterior; 


 while (numeroEnt != 0){

    cantIterac=cantIterac+1;
    
    if (numeroEnt<numAnterior || numAnterior==0){
       contDescendente=contDescendente+1;
       numAnterior=numeroEnt;
    }
     
    if (numeroEnt>numAnterior || numAnterior==0){
        contAscendente=contAscendente+1;
        numAnterior=numeroEnt;  
    }
    
    cout << "Ingrese un numero" <<endl;
    cin >> numeroEnt;
 }

 if (cantIterac==contAscendente || cantIterac==contDescendente){
    cout << "La secuencia esta ordenada"<<endl;
 }else{
    cout << "La secuencia NO esta ordenada"<<endl;
 }

 if (cantIterac==contAscendente){
     cout << "La secuencia es ascendente"<<endl;
 }else{
     if (cantIterac==contDescendente){
       cout << "La secuencia es descendente"<<endl;
     }
 }
 
 
 system("pause");
 return 0;
}

bool esNumeroPrimo (int num){
   
   for (int i = 0; i < num; i++){
      if (num % i == 0){
         return false;
      }
   }

  return true; 
}

