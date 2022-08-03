#include <iostream>
using namespace std;

int factorialRecursv(int numero);

int main () {
    int numero=0;
    int factorial=0;

    cout<< "ingrese un valor"<< endl;
    cin>>numero;

   factorial=factorialRecursv(numero);

   cout << "El resultado es " <<factorial<<endl;

system("pause");
 return 0;
}

int factorialRecursv(int numero){
    if (numero==0){
        return 1;
    }else{
        return numero*factorialRecursv(numero-1);
    }
}
/*
el --n se ejecuta antes de entrar a la linea donde se ejecuta el factorial
por lo tanto siempre va a calcular mal pq la primer iteracion ya está mal
*/