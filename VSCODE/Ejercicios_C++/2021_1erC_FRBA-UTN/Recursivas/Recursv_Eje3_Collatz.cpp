#include <iostream>
using namespace std;

int recursvCollatz(int numero);

int main () {
    int num=0;
    int serieCollatz=0;

    cout<< "ingrese un valor"<< endl;
    cin>>num;

   serieCollatz=recursvCollatz(num);

   cout << "El resultado de la serie es " <<serieCollatz<<endl;

system("pause");
 return 0;
}

int recursvCollatz(int numero){
    cout << numero << endl;
    if (numero==1){
        return 1;
    }
    int n;
    if (numero%2==0){
       n=numero/2; 
    }else{
      n=(numero*3)+1;  
    }
    return recursvCollatz(n);
}