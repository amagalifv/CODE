#include <iostream>
using namespace std;

bool SiEsPrimo(int x){
    int divisor;
    int contDivisiones=0;
    bool resultante=false;

    divisor=x;

    for (int i = 0; i < x; i++) {
        
        if (x % divisor == 0){
            contDivisiones++;
        }

        divisor--;
    }

    if (contDivisiones==2){
        resultante=true;
    }

    return resultante;
}

int main () {
    int num;
    bool esPrimo;

    cout<<"Ingrese un numero para evaluar si es primo"<<endl;
    cin>>num;

    while (num!=0) {
    
        esPrimo=SiEsPrimo(num);

        if (esPrimo==true){

            cout<<"Es primo"<<endl;

        }else{
           
            if (esPrimo==false){
                cout<<"No es primo"<<endl;
            } 
        }
        
        cout<<"Ingrese un numero para evaluar si es primo"<<endl;
        cin>>num;
    }

    system("pause");
    return 0;
}