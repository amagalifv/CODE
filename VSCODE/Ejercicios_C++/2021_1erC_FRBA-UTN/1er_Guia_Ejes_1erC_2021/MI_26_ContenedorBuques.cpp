#include <iostream>
using namespace std;

int main () {
    int contenedores=5;
    string IDcontenedor;
    float pesoContenedor=0;
    int puertoArribo;
    float pesoTotal=0;
    string contenedorMayorPesoID;
    float contenedorMayorpeso=0;
    int sumPuerto1=0;
    int sumPuerto2=0;
    int sumPuerto3=0;

    for (int i = 0; i < contenedores ; i++){
        cout << "Ingrese el identificador del contenedor ingresado" << endl;
     cin >> IDcontenedor;
        cout << "Ingrese el peso en kilos del contenedor"<< endl;
        cin >> pesoContenedor;
        cout << "Ingrese el puerto destino del contenedor" << endl;
        cin >> puertoArribo;

        switch (puertoArribo){
            case 1: 
                sumPuerto1 = sumPuerto1+1;
                break;
            case 2: 
                sumPuerto2 = sumPuerto2+1;
                break;
            case 3: 
                sumPuerto3 = sumPuerto3+1;
                break;
    
            default:
                cout << "Entrada invalida"<< endl;
            break;
        }

        if (pesoContenedor>0){
            pesoTotal=pesoTotal+pesoContenedor;   
         }else{
            cout << "Entrada invalida"<< endl;
         }

         if (pesoContenedor>contenedorMayorpeso){
            contenedorMayorpeso=pesoContenedor;
            contenedorMayorPesoID=IDcontenedor;
         }
    }

    cout << "El peso total que el buque debe trasladar es " << pesoTotal <<" kg"<< endl;
    cout << "El identificador del contenedor de mayor peso es " << contenedorMayorPesoID << " y su peso es " << contenedorMayorpeso << " kg" << endl;
    cout << "La cantidad de contenedores con destino al puerto 1 es " << sumPuerto1 << " contenedores" << endl;
    cout << "La cantidad de contenedores con destino al puerto 2 es " << sumPuerto2 << " contenedores" << endl;
    cout << "La cantidad de contenedores con destino al puerto 3 es " << sumPuerto3 << " contenedores" << endl;
    
system("pause");
 return 0;
}
