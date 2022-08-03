#include <iostream>
using namespace std;

int pedirNum (string mensaje);
int calcularFactorial (int num);
bool siDivisor (int num, int num2);

int main () {
 int num=0;
 bool esDivisor3;
 int contadorDiv3=0;
 bool esDivisor5;
 int contadorDiv5=0;
 int contadorDiv3y5=0;
 int div3=3;
 int div5=5;


 num= pedirNum ("Ingrese un numero, 0 para terminar");

 while (num!=0){
     int factorial= calcularFactorial(num);
     cout << "El factorial de " <<num<< " es "<< factorial<<endl;
     
     esDivisor3= siDivisor(num, div3);
     if (esDivisor3== true){
        contadorDiv3=contadorDiv3+1;
     }

     esDivisor5= siDivisor(num, div5);
     if (esDivisor5== true){
        contadorDiv5=contadorDiv5+1;
     }

     if (esDivisor3== true && esDivisor5== true){
         contadorDiv3y5=contadorDiv3y5+1;
     }
     
   num= pedirNum ("Ingrese un numero, 0 para terminar"); 
 }

  cout << "La cantidad de multiplos de 3 es "<< contadorDiv3 <<endl;
  cout << "La cantidad de multiplos de 5 es "<< contadorDiv5 <<endl;
  cout << "La cantidad de multiplos de 3 y 5 es "<< contadorDiv3y5 <<endl;
 

 system ("pause");
 return 0;
}

int pedirNum (string mensaje){
    int num;
    cout << mensaje<< endl;
    cin >> num;

    return num;
}

int calcularFactorial (int num){
    int fact=1;

    for (int i = num ; i !=0 ; i--)
    {
        fact=fact*i;
    }
    
    return fact;
}

bool siDivisor (int num,int num2){
   bool esMultiplo;
   
    if ( num % num2 == 0){
        esMultiplo=true;
    } else {
        esMultiplo=false;
    }
    
    return esMultiplo;
}
