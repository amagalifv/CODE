#include <iostream>
#include<math.h>
using namespace std;

void imprimirInt (string mensaje, int dato) {

    cout<<mensaje<<dato<<endl;

    return;
}

int main () {
    string ingreso;
    int num;
    int i=0;
    int j=1;
    int contador=0;
    int binaroMin;
    bool primeraEntrada=true;
    int jMin;

    cout<<"Ingrese una letra para cargar un binario o FIN para terminar";
    cin>>ingreso;

    while (ingreso != "FIN") {
        
        cout<<"Ingrese un de a 1 numero el binario, -1 para pasar a otro";
        cin>>num;

        while (num>-1) {
    
            contador+=num*(pow((double)2,(double)i)); 
            
            i++;

            cout<<"Ingrese un de a 1 numero el binario, -1 para pasar a otro";
            cin>>num;
        }

        imprimirInt("El decimal es:", contador);


        if (primeraEntrada==true){
            binaroMin=contador;
            primeraEntrada=false;
        }else{
            if (contador<binaroMin){
                binaroMin=contador;
                jMin=j;
            }
        }
        
        j++;

        cout<<"Ingrese una letra para cargar un binario o FIN para terminar";
        cin>>ingreso;
    }

    imprimirInt("El menor numero decimal  ingresado es ", binaroMin);
    imprimirInt("Y su posicion es ", jMin);
 
    system("pause");
    return 0;
}