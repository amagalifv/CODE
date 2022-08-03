#include <iostream>
using namespace std;

int fibonacci (int terminos);
void imprimirFibonacci(int numero);

int main () {
    int terminos=0;
    int serieFibonacci=0;

    cout<< "ingrese un valor"<< endl;
    cin>>terminos;

   // cout << fibonacci(terminos)<<endl;

    imprimirFibonacci(terminos);

 system("pause");
 return 0;
}

int fibonacci (int termino){
    if (termino<=1){
        return termino;
    } else {
    return fibonacci(termino-1)+fibonacci(termino-2);
    }      
}


void imprimirFibonacci(int numero){
    if (numero<=0){
        return;
    }else{
        cout<<fibonacci(numero-1)<<endl;
        imprimirFibonacci(numero-1);
    } 
}
