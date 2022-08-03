#include <iostream>
using namespace std;

void bateriaDisp (int avance, int &bate);
int avanceMtrs ( char dire, int avance, int avanceMetros);
void trayectoMasLargo ( char dire, int avanceA, int &contadorF, int &contadorB, int &contadorR, int &contadorL);
void cualTrayectoMasLargo (int contadorF, int contadorB, int contadorR, int contadorL, string &mensajeTrayMasLargo);

int main () {
    char direccion;
    int cantMetrosAvanzar=0;
    int metrosRecorridos=0;
    int metrosAvanzados=0;
    int bateria=1000;
    int contadorF=0;
    int contadorB=0;
    int contadorR=0;
    int contadorL=0;
    string mensajeTrayecto;
    

    cout << "Ingresar direccion, F/B/R/L "<< endl;
    cin >>direccion;
    cout <<"Ingresar cant m a avanzar"<<endl;
    cin >> cantMetrosAvanzar;

    bateriaDisp(cantMetrosAvanzar, bateria);

    while ( bateria>=0 && direccion !='E'){

        metrosRecorridos=metrosRecorridos+cantMetrosAvanzar;

        metrosAvanzados= avanceMtrs(direccion, cantMetrosAvanzar, metrosAvanzados);

        trayectoMasLargo(direccion, cantMetrosAvanzar, contadorF, contadorB, contadorR, contadorL);

        cout << "Ingresar direccion, F/B/R/L "<< endl;
        cin >>direccion;
        cout <<"Ingresar cant m a avanzar"<<endl;
        cin >> cantMetrosAvanzar;

        bateriaDisp(cantMetrosAvanzar, bateria);
    }

    
    cout << "Los metros recorridos son "<< metrosRecorridos<< endl;
    cout << "Los metros avanzados son "<< metrosAvanzados<< endl;
    cualTrayectoMasLargo (contadorF, contadorB, contadorR, contadorL, mensajeTrayecto);


    system("pause");
    return 0;
}

void bateriaDisp (int avance, int &bate){
    if (avance>=0){
        if (avance%2==0){
            bate=bate-(avance/4);
        } else {
            bate=bate-(avance/3);
        }
    }

    return;
}

int avanceMtrs ( char dire, int avance, int avanceMetros){
    int avanceY;
    int avanceX;

    switch (dire){
        case 'F':
            avanceY+=avance;
            break;
        case 'B':
            avanceY=avanceY-avance;
            break;
        case 'R':
            avanceX+=avance;
            break;
        case 'L':
            avanceX=avanceX-avance;
            break;
        default:
            break;
    }
    avanceMetros=avanceX+avanceY;

    return avanceMetros;
}

void trayectoMasLargo ( char dire, int avanceA, int &contadorF, int &contadorB, int &contadorR, int &contadorL){
 
    switch (dire){
        case 'F':
            contadorF=contadorF+avanceA;
            break;
        case 'B':
            contadorB=contadorB+avanceA;
            break;
        case 'R':
            contadorR=contadorR+avanceA;
            break;
        case 'L':
            contadorL=contadorL+avanceA;
            break;
        default:
            break;
    }

    return;
}

void cualTrayectoMasLargo (int contadorF, int contadorB, int contadorR, int contadorL, string &mensajeTrayMasLargo){    
if (contadorF>contadorB && contadorF>contadorL && contadorF>contadorR){
 mensajeTrayMasLargo="El trayecto mas largo es hacia adelante";
 }else{
     if (contadorB>contadorF && contadorB>contadorL && contadorB>contadorR){
        mensajeTrayMasLargo="El trayecto mas largo es hacia atras";
     } else {
         if (contadorL>contadorF && contadorL>contadorB && contadorL>contadorR){
            mensajeTrayMasLargo="El trayecto mas largo es hacia la izquierda";
         }else{
            mensajeTrayMasLargo="El trayecto mas largo es hacia la derecha";
         }   
     }  
 }

 return;
}

 
 
  