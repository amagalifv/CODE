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

//ACTUALIZA DATOS DE TIRADA JUG
void actializarDatosJug (int vDados[], ST_PLAYER jug[], int jugador, int &cantidadDadosDeTirada, int nroTirada, bool &pararTiradas) {
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

    // PARA LA CARGA -que no es ultima tirada //
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

//ACTUALIZA DATOS DE TIRADA EN PC
void actializarDatosPC (int vDados[], ST_PLAYER jug[], int jugador, int &cantidadDadosDeTirada, int nroTirada, bool &pararTiradas) {
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

    // PARA LA CARGA -//juega hasta cargar más de 6 o hasta que no le queden tiradas//
    if (nroTirada<2 && jug[jugador].dado4=='x' &&  jug[jugador].dado5=='x' && jug[jugador].dado6=='x'){

        for (int j=0; j<cantidadDadosDeTirada; j++) {
            if (iDeCopiado4!=j && iDeCopiado5!=j && iDeCopiado6!=j) {
                sum+=vDados[j];
            }
        }
        if (sum>=6) {
            pararTiradas=true;
        }

    }

    cantidadDadosDeTirada=cantProxTir;

    jug[jugador].carga=sum;

    return;
}

//CUENTA PUNTOS
void cuentaPuntaje (ST_PLAYER jug[], int jugador) {

    jug[jugador].puntaje+=jug[jugador].carga;

    return;
}

//CAMBIA DE JUGADOR
int cambioJugador (int jugActual) {

    if (jugActual==0) {
        jugActual=1;
    } else if (jugActual==1) {
        jugActual=0;
    }

    return jugActual;
}

// IMPRIME EL GANADOR
void busqGanador (ST_PLAYER jug2[]) {
    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;
    if (jug2[1].puntaje>jug2[0].puntaje) {
        cout<<"EL GANADOR ES: "<<jug2[1].nombre<<endl;
        cout<<"Puntaje: "<<jug2[1].puntaje<<endl;
        cout<<"Cantidad de tiradas: "<<jug2[1].cantTiradas<<endl;

    } else if (jug2[1].puntaje<jug2[0].puntaje) {
        cout<<"EL GANADOR ES: "<<jug2[0].nombre<<endl;
        cout<<"Puntaje: "<<jug2[0].puntaje<<endl;
        cout<<"Cantidad de tiradas: "<<jug2[0].cantTiradas<<endl;

    }else{
        if (jug2[1].cantTiradas>jug2[0].cantTiradas) {
            cout<<"EL GANADOR ES: "<<jug2[1].nombre<<endl;
            cout<<"Puntaje: "<<jug2[1].puntaje<<endl;
            cout<<"Cantidad de tiradas: "<<jug2[1].cantTiradas<<endl;
        }
        if (jug2[1].cantTiradas<jug2[0].cantTiradas) {
            cout<<"EL GANADOR ES: "<<jug2[0].nombre<<endl;
            cout<<"Puntaje: "<<jug2[0].puntaje<<endl;
            cout<<"Cantidad de tiradas: "<<jug2[0].cantTiradas<<endl;
        }
        if (jug2[1].cantTiradas==jug2[0].cantTiradas && jug2[1].cantTiradas==jug2[0].cantTiradas) {
            cout<<"ES UN EMPATE !!!!! "<<endl;
        }
    }
    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;

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

// EVALUA LA TIRADA MAXIMA
void evTirMax (ST_PLAYER jug2[], int jugAct,  int ronda, int jug, int &maxTir, string &nomMaxTir, int &ronMaxTir) {

    if (ronda==0 && jug==0) {
        maxTir=jug2[jugAct].carga;
        nomMaxTir=jug2[jugAct].nombre;
        ronMaxTir=ronda;
    } else if (maxTir<jug2[jugAct].carga) {
        maxTir=jug2[jugAct].carga;
        nomMaxTir=jug2[jugAct].nombre;
        ronMaxTir=ronda;
    }

    return;
}

int main () {
    ST_PLAYER jug2[2]={"",'-','-','-',0,0,0};
    int cantTiradas=3;
    int vDados[5]={0};
    int dado;
    int cantDados=5;
    int rondas;
    int jugActual=0;
    bool pararTiradas=false;
    int i=0;
    int maxTir;
    string nomMaxTir;
    int ronMaxTir;

    cinInt("Ingrese la cantidad de rondas que desea jugar", rondas);

    jug2[0].nombre="MaquinaBob";

    cout<<"Ingrese el nombre del segundo jugador"<<endl;
    cin>>jug2[1].nombre;

    for (int k=0; k<rondas; k++) {

        for (int j=0; j<2; j++) {

            // MENSAJE ENTRE RONDAS
            impMsjEntreJugadas(k,jug2,jugActual);
            system("pause");
            system("cls");

            while (i<3 && pararTiradas==false){

                // MENSAJE HEADER
                impMsjHeader(k,jug2,jugActual,i);

                cargarAleatorio(vDados,cantDados,6);

                // IMP DADOS
                imprimirVec(vDados,cantDados);
                cout<<endl;
                system("pause");

                algorOrdBurbujeo(vDados,cantDados);

                if (jugActual==1) {
                    actializarDatosJug(vDados,jug2,jugActual,cantDados, i, pararTiradas);
                } else if (jugActual==0) {
                    actializarDatosPC(vDados,jug2,jugActual,cantDados, i, pararTiradas);
                }

                cuentaPuntaje(jug2, jugActual);

                // IMP OBJETIVOS
                impMsjObjetivos(jug2, jugActual);

                jug2[jugActual].cantTiradas++;
                i++;

                system("pause");
                system("cls");
            }
            // EVALUA LA TIRADA MAXIMA
            evTirMax(jug2, jugActual,k,j, maxTir,nomMaxTir,ronMaxTir);

            //BLANQUEO DE VARIABLES PARA PROXIMO TURNO DE JUGADOR
            jug2[jugActual].dado6='-';
            jug2[jugActual].dado5='-';
            jug2[jugActual].dado4='-';

            //BLANQUEO DE VARIABLES PARA CAMBIAR DE JUGADOR
            jugActual=cambioJugador(jugActual);
            pararTiradas=false;
            i=0;
            cantDados=5;
        }

    }

    // IMPRIME GANADOR
    busqGanador(jug2);

    system("pause");
    return 0;
}