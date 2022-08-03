#include <iostream>
#include <cstring>
#include <cstdlib>
#include<ctime>
using namespace std;

/*
Nivel obligatorio para aprobar:
-Modo 2 jugadores
-mostrar puntuación máxima
-modo simulado
*/

#define MAX_JUG 10

typedef struct {
    string nombre;
    char dado6;
    char dado5;
    char dado4;
    int trip;
    int cantTiradas;
} ST_PLAYER;

void RodarDados (int cantDados, int arr[]){
    int j=0;

    for (int i=0; i<cantDados; i++) {
        arr[j]=(rand() % 6)+1;

        j++;
    }

    return;
}

void imprimirTirada (int cantDados, int arr[]) {

    cout<<"TIRADA: ";
    for (int i=0; i<cantDados; i++) {
        cout<<arr[i]<<"\t";
    }

    return;
}

void imprimirDado (int dado, string mensaje) {
    if (dado==1) {
        cout<<" _____"<<endl;
        cout<<"|     |"<<endl;
        cout<<"|  *  |"<<endl;
        cout<<"|     |"<<endl;
        cout<<" _____"<<endl;
    } else if (dado==2) {
        cout<<" _____"<<endl;
        cout<<"| *   |"<<endl;
        cout<<"|     |"<<endl;
        cout<<"|   * |"<<endl;
        cout<<" _____"<<endl;
    } else if (dado==3) {
        cout<<" _____"<<endl;
        cout<<"| *   |"<<endl;
        cout<<"|  *  |"<<endl;
        cout<<"|   * |"<<endl;
        cout<<" _____"<<endl;
    } else if (dado==4) {
        cout<<" _____"<<endl;
        cout<<"| * * |"<<endl;
        cout<<"|     |"<<endl;
        cout<<"| * * |"<<endl;
        cout<<" _____"<<endl;
    }else if (dado==5) {
        cout<<" _____"<<endl;
        cout<<"| * * |"<<endl;
        cout<<"|  *  |"<<endl;
        cout<<"| * * |"<<endl;
        cout<<" _____"<<endl;
    } else if (dado==2) {
        cout<<" _____"<<endl;
        cout<<"| * * |"<<endl;
        cout<<"| * * |"<<endl;
        cout<<"| * * |"<<endl;
        cout<<" _____"<<endl;
    }

    return;
}

void msjEntreJugadas (/* parameters */) {

    return;
}

void impMsjMenu(int dato) {
    cout<<"____________________________________________________________"<<endl;
    cout<<"\n\n\n\tBIENVENIDOS A SEIS, CINCO, CUATRO\n\n\n";
    cout<<"____________________________________________________________"<<endl;
    cout<<"Ingrese:\n\t1-Juego nuevo entre dos participantes\n\t2-Juego nuevo entre x participantes\n\t3-Juego nuevo contra la maquina\n\t4-Juego nuevo contra x maquinas\n\t5-Mostrar puntuacion mas alta\n\t6-Modo simulado\n\t7-Salir\n"<<endl;
    cin>>dato;

    return;
}

void cinString (string mensaje, string dato) {
    cout<<mensaje<<endl;
    cin>>dato;

    return;
}

int main () {
    ST_PLAYER jugadores[MAX_JUG];
    int menu;
    int cantTiradas=3;
    int cantDados=5;
    int tirada[cantDados-1];
    int puntuacionMasAlta=0;

    impMsjMenu(menu);

    switch (menu){
        system("cls");

        case 1:
            cinString("Ingrese el nombre del primer jugador", jugadores[0].nombre);
            cinString("Ingrese el nombre del segundo jugador", jugadores[1].nombre);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            cout<<"\tADIOS!!!"<<endl;
            break;

        default:
            break;
    }





    system("pause");
    return 0;
}