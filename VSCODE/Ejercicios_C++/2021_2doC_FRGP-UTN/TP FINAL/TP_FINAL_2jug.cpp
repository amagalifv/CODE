#include <iostream>
#include <cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

typedef struct {
    string nombre;
    char dado6;
    char dado5;
    char dado4;
    int carga;
    int cantTiradas;
    int puntaje;
} ST_PLAYER;

//CIN VARIABLE INT
void cinInt (string mensaje, int &dato) {
    cout<<mensaje<<endl;
    cin>>dato;

    return;
}

//CARGA VECTOR CON NUMEROS RANDOM DEL 1 AL 6
void cargarAleatorio(int v[], int tam, int limite){

    int i;
    srand(time(NULL));

    for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
    }

    return;
}

//IMPRIME VECTOR
void imprimirVec(int v[], int tam){

    for (int i=0; i<tam; i++) {
        cout<<v[i]<<"\t";
    }

    return;
}

//ORDENA DE MAYOR A MENOR
void algorOrdBurbujeo(int arr[], int n){
    int aux;
    int i=0;
    bool ordenado = false;

    while (i < n && !ordenado){

        ordenado= true;

        for (int j = 0; j < n-i-1 ; j++){

            if (arr[j]<arr[j+1]){
                aux = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=aux;
                ordenado = false;
            }
        }

        i++;
    }

}

//BUSQUEDA BINARIA
int busqBinaria (int vDados[],int cantidadDadosDeTirada, int valorBusq) {
    int inicio=0;
    int fin = cantidadDadosDeTirada -1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        //si el elemento es el del medio, devolvemos la posicion
        if (vDados[mitad]==valorBusq){
            return mitad;
        }

         //si el elemento es mayor entonces solo puede estar en la primera mitad
         if ( vDados[mitad]<valorBusq){
             fin=mitad - 1; //Cambio el limite superior
         }else{
             inicio=mitad+1; //Cambio el limite inferior
         }
    }

    return -1;
}

//ACTUALIZA DATOS DE TIRADA EN JUGADORES
void actializarDatos (int vDados[], ST_PLAYER jug[], int jugador, int &cantidadDadosDeTirada, int nroTirada, bool &pararTiradas) {
    int sum=0;
    int cantProxTir;
    int iDeCopiado6=-1;
    int iDeCopiado5=-1;
    int iDeCopiado4=-1;
    char resp=0;

    //copio cant en otra variable para que no me modifique la dimension actual del vec
    cantProxTir=cantidadDadosDeTirada;

    if (jug[jugador].dado6!='x') {
        iDeCopiado6=busqBinaria(vDados, cantidadDadosDeTirada,6);
        if (iDeCopiado6!=-1) {
            jug[jugador].dado6='x';
            cantProxTir--;
        }
    }//busca el 6 y actualiza datos si lo encuantra

    if (jug[jugador].dado5!='x' && jug[jugador].dado6=='x') {
        iDeCopiado5=busqBinaria(vDados, cantidadDadosDeTirada,5);
        if (iDeCopiado5!=-1) {
            jug[jugador].dado5='x';
            cantProxTir--;
        }
    }//busca el 5, si el 6 ya está, y actualiza datos si lo encuantra

    if (jug[jugador].dado4!='x' && jug[jugador].dado6=='x'&& jug[jugador].dado5=='x') {
        iDeCopiado4=busqBinaria(vDados, cantidadDadosDeTirada,4);
        if (iDeCopiado4!=-1) {
            jug[jugador].dado4='x';
            cantProxTir--;
        }
    }//busca el 4, si el 5 y 6 ya están, y actualiza datos si lo encuantra

    // PARA LA CARGA -que no es ultima tirada //
    if (nroTirada!=2 && jug[jugador].dado4=='x' &&  jug[jugador].dado5=='x' && jug[jugador].dado6=='x'){

        cout<<"Desea tirar una vez mas para mejorar puntaje de la carga? (S para si y N para no)"<<endl;
        cin>>resp;

        if (resp=='N'||resp=='n') {
            pararTiradas=true;

            for (int j=0; j<cantidadDadosDeTirada; j++) {
                if (iDeCopiado4!=j && iDeCopiado5!=j && iDeCopiado6!=j) {
                    sum+=vDados[j];
                }
            }
        }
    }//Pregunta por la carga y actualiza según respuesta

    // PARA LA CARGA -que es ultima tirada //
    if (nroTirada==2 && jug[jugador].dado4=='x' &&  jug[jugador].dado5=='x' && jug[jugador].dado6=='x'){

        for (int j=0; j<cantidadDadosDeTirada; j++) {
            if (iDeCopiado4!=j && iDeCopiado5!=j && iDeCopiado6!=j) {
                sum+=vDados[j];
            }
        }
    }//si es ultima tirada y tiene 4,5 y 6 sumo carga

    cantidadDadosDeTirada=cantProxTir;

    jug[jugador].carga=sum;

    return;
}

// MENSAJE ENTRE RONDAS
void impMsjEntreJugadas(int ronda, ST_PLAYER jug2[], int jugAct) {

    cout<<"-------------------------------------------"<<endl;
    cout<<"\t\tRONDA Nro "<<ronda+1<<endl;
    cout<<"\tPROXIMO TURNO: "<<jug2[jugAct].nombre<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"\tPUNTAJE "<<jug2[jugAct].nombre<<": "<<jug2[jugAct].puntaje<<" PUNTOS"<<endl;
    cout<<"\tCANTIDAD DE TIRADAS: "<<jug2[jugAct].cantTiradas<<endl;
    cout<<"-------------------------------------------"<<endl;

    return;
}

// MENSAJE HEADER
void impMsjHeader(int ronda, ST_PLAYER jug2[], int jugAct, int tirada) {

    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;
    cout<<"TURNO DE "<<jug2[jugAct].nombre<<" | ";
    cout<<"RONDA Nro "<<ronda+1<<" | ";
    cout<<"PUNTAJE ACUMULADO: "<<jug2[jugAct].puntaje<<" puntos";
    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;
    cout<<"TIRADA Nro "<<tirada+1;
    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;

    return;
}

// MENSAJE OBJETIVOS
void impMsjObjetivos (ST_PLAYER jug2[], int jugAct) {

    cout<<"*******************\n";
    cout<<"|    Objetivos    |\n";
    cout<<"-------------------\n";
    cout<<"| Barco:       | "<<jug2[jugAct].dado6<<" |\n";
    cout<<"| Capitan:     | "<<jug2[jugAct].dado5<<" |\n";
    cout<<"| Tripulacion: | "<<jug2[jugAct].dado4<<" |\n";
    cout<<"*******************\n";

    return;
}

//CUENTA PUNTOS
void cuentaPuntaje (ST_PLAYER jug[]) {

    if (jug[1].carga>jug[0].carga || (jug[1].carga==jug[0].carga && jug[1].cantTiradas<jug[0].cantTiradas)) {
        jug[1].puntaje++;

    } else if (jug[0].carga>jug[1].carga || (jug[0].carga==jug[1].carga && jug[0].cantTiradas<jug[1].cantTiradas)) {
        jug[0].puntaje++;
    }

    return;
}

// BUSCA EL GANADOR
int resultado (ST_PLAYER jug2[]) {

    if (jug2[1].puntaje>jug2[0].puntaje || (jug2[1].puntaje==jug2[0].puntaje && jug2[1].cantTiradas<jug2[0].cantTiradas)) {
        return 1;

    } else if (jug2[0].puntaje>jug2[1].puntaje || (jug2[0].puntaje==jug2[1].puntaje && jug2[0].cantTiradas<jug2[1].cantTiradas)) {
        return 0;

    }else{
        return -1;
    }
}

// IMPRIME RESULTADO
void impResultado (ST_PLAYER jug2[], int iPosGan) {

    if (iPosGan>-1) {
        cout<<"**************************************\n";
        cout<<"\t   |  GANADOR  |\n";
        cout<<"--------------------------------------\n";
        cout<<"| Jugador:       | "<<jug2[iPosGan].nombre<<endl;
        cout<<"| Puntaje :        | "<<jug2[iPosGan].puntaje<<endl;
        cout<<"| Tiradas:         | "<<jug2[iPosGan].cantTiradas<<endl;
        cout<<"**************************************\n";
    }

    if (iPosGan==-1) {
        cout<<"**************************************\n";
        cout<<"\t   |  ES UN EMPATE !!!!!  |\n";
        cout<<"**************************************\n";
    }

    return;
}

int main () {
    ST_PLAYER jug2[2]={"",'-','-','-',0,0,0};
    jug2[0]={"",'-','-','-',0,0,0};
    jug2[1]={"",'-','-','-',0,0,0};
    int cantTiradas=3;
    int vDados[5]={0};
    int cantDados=5;
    int rondas;
    bool pararTiradas=false;
    int i=0;
    int maxTir;
    string nomMaxTir;
    int cantMaxTir;
    int posGanador;

    cinInt("Ingrese la cantidad de rondas que desea jugar", rondas);

    cout<<"Ingrese el nombre del primer jugador"<<endl;
    cin>>jug2[0].nombre;

    cout<<"Ingrese el nombre del segundo jugador"<<endl;
    cin>>jug2[1].nombre;

    system("cls");

    for (int k=0; k<rondas; k++) {

        for (int j=0; j<2; j++) {

            // MENSAJE ENTRE RONDAS
            impMsjEntreJugadas(k,jug2,j);
            system("pause");
            system("cls");

            while (i<3 && pararTiradas==false){

                // MENSAJE HEADER
                impMsjHeader(k,jug2,j,i);

                cargarAleatorio(vDados,cantDados,6);

                // IMP DADOS
                imprimirVec(vDados,cantDados);
                cout<<endl;
                system("pause");

                algorOrdBurbujeo(vDados,cantDados);

                actializarDatos(vDados,jug2,j,cantDados, i, pararTiradas);

                // IMP OBJETIVOS
                impMsjObjetivos(jug2, j);

                jug2[j].cantTiradas++;
                i++;

                system("pause");
                system("cls");
            }

            //BLANQUEO DE VARIABLES PARA PROXIMO TURNO DE JUGADOR
            jug2[j].dado6='-';
            jug2[j].dado5='-';
            jug2[j].dado4='-';

            pararTiradas=false;
            i=0;
            cantDados=5;
        }

        cuentaPuntaje(jug2);
    }

    posGanador=resultado(jug2);
    impResultado(jug2, posGanador);

    system("pause");
    return 0;
}