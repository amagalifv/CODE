#include <iostream>
#include <cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

/*
EN MODO MULTI-JUGADOR:
SI HAY EMPATE SE LE ASIGNA 0,5 PUNTOS
Y SI GANA SOLO SE LE ASIGNA 1 PUNTOS
*/

#define MAX_JUG 10

typedef struct {
    string nombre;
    char dado6;
    char dado5;
    char dado4;
    int carga;
    int cantTiradas;
    float puntaje;
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

//CUENTA PUNTOS
void cuentaPuntajeMultiJug (ST_PLAYER jug[], int jugadores) {
    int iGan=-1;
    int gan=-1;
    int cont=0;

    for (int i=0; i<jugadores; i++) {

        if (jug[i].carga>gan) {
            iGan=i;
            gan=jug[i].carga;
        } else if (jug[i].carga==gan) {
            if (jug[i].cantTiradas<jug[iGan].cantTiradas) {
                iGan=i;
            }
        }
    }

    for (int i=0; i<jugadores; i++) {
        if (jug[i].carga==gan && jug[iGan].cantTiradas==jug[i].cantTiradas) {
            cont++;
        }
    }

    if (iGan != -1 && cont==1) {
        jug[iGan].puntaje++;
    } else if (cont>1) {
        for (int i=0; i<jugadores; i++) {
            if (jug[i].carga==gan && jug[i].cantTiradas==jug[iGan].cantTiradas) {
                jug[i].puntaje+=0,5;
            }
        }
    }

    return;
}

// IMPRIME EL GANADOR
void busqGanador (ST_PLAYER jug[], int cantJug) {
    int ganador=-1;
    int iGanador=-1;
    int cont=0;
    int vPosGanadores[MAX_JUG]={0};
    int dimeGanadores=-1;

    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;

    for (int i=0; i<cantJug; i++) {

        if (jug[i].puntaje>ganador) {
            ganador=jug[i].puntaje;
            iGanador=i;
            vPosGanadores[MAX_JUG]={-1};
            dimeGanadores=-1;

        } else if (jug[i].puntaje==ganador) {

            if (jug[i].cantTiradas<jug[iGanador].cantTiradas) {
                ganador=jug[i].puntaje;
                iGanador=i;
                vPosGanadores[MAX_JUG]={0};
                dimeGanadores=-1;
            }

            if (jug[i].cantTiradas==jug[iGanador].cantTiradas) {
                dimeGanadores++;
                vPosGanadores[dimeGanadores]=i;
            }
        }
    }

    for (int i=0; i<dimeGanadores; i++) {
        if (vPosGanadores[i]>=0) {
            cont++;
        }
    }

    if (iGanador>-1 && cont==1) {
        cout<<"EL GANADOR ES: "<<jug[iGanador].nombre<<endl;
        cout<<"Puntaje: "<<jug[iGanador].puntaje<<endl;
    } else if (cont>1) {
        cout<<"ES UN EMPATE entre ";
        jug[iGanador].nombre;
        for (int i=0; i<dimeGanadores; i++) {
            jug[vPosGanadores[i]].nombre;
        }
        cout<<endl;
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

// EVALUA EL MAXIMO
void evaluaMax (ST_PLAYER jug[], int cantJug, int &max, string &nomMax) {
    max=0;

    for (int i=0; i<cantJug; i++) {
        if (jug[i].puntaje>max) {
            max=jug[i].puntaje;
            nomMax=jug[i].nombre;
        }
    }

    return;

    /*
    int ganador=-1;
    int iGanador=-1;
    int cont=0;
    int vPosGanadores[MAX_JUG]={-1};
    int dimeGanadores=-1;

    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;

    for (int i=0; i<cantJug; i++) {

        if (jug[i].puntaje>ganador) {
            ganador=jug[i].puntaje;
            iGanador=i;
            vPosGanadores[MAX_JUG]={-1};
            dimeGanadores=-1;

        } else if (jug[i].puntaje==ganador) {

            if (jug[i].cantTiradas<jug[iGanador].cantTiradas) {
                ganador=jug[i].puntaje;
                iGanador=i;
                vPosGanadores[MAX_JUG]={-1};
                dimeGanadores=-1;
            }

            if (jug[i].cantTiradas==jug[iGanador].cantTiradas) {
                dimeGanadores++;
                vPosGanadores[dimeGanadores]=i;
            }
        }
    }

    for (int i=0; i<dimeGanadores; i++) {
        if (vPosGanadores[i]>=0) {
            cont++;
        }
    }

    if (iGanador>-1 && cont==1) {
        cout<<"EL GANADOR ES: "<<jug[iGanador].nombre<<endl;
        cout<<"Puntaje: "<<jug[iGanador].puntaje<<endl;
    } else if (cont>1) {
        cout<<"ES UN EMPATE entre ";
        jug[iGanador].nombre;
        for (int i=0; i<dimeGanadores; i++) {
            jug[vPosGanadores[i]].nombre;
        }
        cout<<endl;
    }

    cout<<"\n----------------------------------------------------------------------------------\n"<<endl;

    return;
    */
}

// IMPRIME LA TIRADA DE PUNTUACION MAS ALTA
void impTiradaMax (int max, string nomMax) {

    cout<<"**************************************\n";
    cout<<"\t |  MAXIMO PUNTAJE  |\n";
    cout<<"--------------------------------------\n";
    cout<<"| Jugador:       | "<<nomMax<<endl;
    cout<<"| Puntaje :      | "<<max<<endl;
    cout<<"**************************************\n";

    return;
}

int main () {
    ST_PLAYER jugadores[MAX_JUG]={"",'-','-','-',0,0,0};
    int cantTiradas=3;
    int vDados[5]={0};
    int cantDados=5;
    int rondas;
    int jugActual=0;
    bool pararTiradas=false;
    int i=0;
    int max;
    string nomMax;
    int cantJug;

    cinInt("Ingrese la cantidad de jugadores que desean jugar (de 3 a 10)", cantJug);
    cinInt("Ingrese la cantidad de rondas que desea jugar", rondas);


    for (int i=0; i<cantJug; i++) {
        cout<<"Ingrese el nombre jugador"<<endl;
        cin>>jugadores[i].nombre;
    }

    for (int k=0; k<rondas; k++) {

        for (int j=0; j<cantJug; j++) {

            // MENSAJE ENTRE RONDAS
            impMsjEntreJugadas(k,jugadores,j);
            system("pause");
            system("cls");

            while (i<3 && pararTiradas==false){

                // MENSAJE HEADER
                impMsjHeader(k,jugadores,j,i);

                cargarAleatorio(vDados,cantDados,6);

                // IMP DADOS
                imprimirVec(vDados,cantDados);
                cout<<endl;
                system("pause");

                algorOrdBurbujeo(vDados,cantDados);

                actializarDatos(vDados,jugadores,j,cantDados, i, pararTiradas);

                // IMP OBJETIVOS
                impMsjObjetivos(jugadores, j);

                jugadores[j].cantTiradas++;
                i++;

                system("pause");
                system("cls");
            }

            cout<<"\n  ~CARGA~ "<<jugadores[j].carga<<"\n"<<endl;

            //BLANQUEO DE VARIABLES PARA PROXIMO TURNO DE JUGADOR
            jugadores[j].dado6='-';
            jugadores[j].dado5='-';
            jugadores[j].dado4='-';
            jugadores[j].cantTiradas=0;

            //BLANQUEO DE VARIABLES PARA CAMBIAR DE JUGADOR
            pararTiradas=false;
            i=0;
            cantDados=5;
        }

        cuentaPuntajeMultiJug(jugadores, cantJug);
    }

    // IMPRIME GANADOR
    busqGanador(jugadores, cantJug);

    cout<<endl;

    // EVALUA EL MAXIMO PUNTAJE
    evaluaMax(jugadores,cantJug,max,nomMax);

    //IMPRIME EL MAXIMO PUNTAJE
    impTiradaMax(max,nomMax);

    system("pause");
    return 0;
}