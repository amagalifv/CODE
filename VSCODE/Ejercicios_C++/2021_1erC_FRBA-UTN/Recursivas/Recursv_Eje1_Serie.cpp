/*
tipo_de_dato miFuncionRecursiva(lista_de_argumentos){
    //termino_de_corte
    return valor;

    //termino_de_recursivo
    return miFuncionRecursiva(lista_de_argumentos_prima);
}
*/
/*
int factorial(int numero){
    if (numero==0){
        return 1;
    }else{
        return numero*factorial(numero-1);
    }
}
*/

#include <iostream>
using namespace std;

int serieRecursv (int num);

int main () {
   int num=0;
   int serieR=0;

    cout<< "ingrese un valor"<< endl;
    cin>>num;

   serieR=serieRecursv(num);

   cout << "El resultado de la serie es " <<serieR<<endl;
 
system("pause");
 return 0;
}

int serieRecursv (int num){
    if (num==0){
        return 0;
    }else{
        return num+serieRecursv(num-1);
    }
}