#include <iostream>
using namespace std;

int pedirNum (string mensaje);
int calcularFactorial (int num);
void imprimirFactorial (int num, int factorial);

int main () {
 int num=0;

 num= pedirNum ("Ingrese un numero");

 int factorial= calcularFactorial(num);

 cout << "El factorial de " <<num<< " es "<< factorial<<endl;

 imprimirFactorial(num , factorial);

system("pause");
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

void imprimirFactorial (int num, int factorial){
 cout <<"El factorial de "<<num<<" es " << factorial<< endl;
 return;
}