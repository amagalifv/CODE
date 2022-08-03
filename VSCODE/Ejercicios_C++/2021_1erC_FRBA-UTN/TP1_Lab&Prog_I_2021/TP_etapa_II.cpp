#include <iostream>
using namespace std;

const int maxVueltas=3;

typedef struct{    
  int segundos;
  int minutos;
}ST_TEMPO;

typedef struct{    
  int dia;
  int mes;
  int anio;
}ST_FECHA;

int convertirAMetros(float distancia){
    return distancia*1000;
}

float calcularVelocidad(int mtrs, int seg){
return mtrs/seg;
}

void cargarDatosGrales (ST_FECHA &fecha, float &distanciaEnMtrs){
    float distancia;
    
    cout<<"Ingrese el dia del registro"<<endl;
    cin>>fecha.dia;
    cout<<"Ingrese el mes del registro"<<endl;
    cin>>fecha.mes;
    cout<<"Ingrese el anio del registro"<<endl;
    cin>>fecha.anio;

    cout<<"Ingrese la distancia del circuito en km"<<endl;
    cin>>distancia;
    distanciaEnMtrs=convertirAMetros(distancia);

    return;
}

void cargarVector (ST_TEMPO tiempo[maxVueltas], int maxVueltas, float &promVueta) {
    int vuelta=0;
    int sumTiempo=0;
    int duracion=0; 
    
    for (int i = 0; i < maxVueltas; i++) {
        cout<<"Ingrese el numero de vuelta"<<endl;
        cin>>vuelta;

        cout<<"Ingrese la duracion de la vuelta en MMSS"<<endl;
        cin>>duracion;
        tiempo[vuelta-1].minutos=duracion/100;
        tiempo[vuelta-1].segundos=duracion%100;
        
        sumTiempo+=tiempo[vuelta-1].minutos*60+tiempo[vuelta-1].segundos;
    }

    promVueta=sumTiempo/maxVueltas;

    return;
}

void imprimirVueltas(ST_TEMPO tiempo[], int maxVueltas){
    for (int i = 0; i < maxVueltas; i++) {
     cout<<"Vuelta "<<i+1<<", tiempo "<<tiempo[i].minutos<<"m "<<tiempo[i].segundos<<"s";
     cout<<endl;
    }
    cout<<"---------------------------------------------------------------------"<<endl;
    return;
}

void imprimirX(ST_TEMPO tiempo[], int x,  ST_FECHA fecha,float distanciaEnMtrs){
    
    cout<<"Vuelta "<<x<<": "<<endl;
    cout<<"Tiempo "<<tiempo[x-1].minutos<<"m "<<tiempo[x-1].segundos<<"s"<<endl;
    cout<<"Distancia: "<<distanciaEnMtrs<<"m"<<endl;
    cout<<"Fecha: "<<fecha.dia<<"-"<<fecha.mes<<"-"<<fecha.anio<<endl;

    return;
}

void comparacionVelMed(ST_TEMPO tiempo[],int maxVueltas, float velMed, float distanciaEnMtrs){
    float tiempoSeg=0;
    float velVuelta=0;
    
    for (int i = 0; i < maxVueltas; i++) {
        
        tiempoSeg=tiempo[i].minutos*60+tiempo[i].segundos;

        velVuelta=calcularVelocidad(distanciaEnMtrs, tiempoSeg);

        if (velVuelta>velMed){
            cout<<"La velocidad de la vuelta "<<i+1<<" ("<<velVuelta<<" m/s) fue mayor a la velocidad media ("<<velMed<<" m/s)"<<endl;
        }
    }
    return;
}

#include <iostream>
using namespace std;

int main () {
    ST_TEMPO tiempo[maxVueltas];
    ST_FECHA fecha;
    float distanciaEnMtrs;
    float promVueta=0;
    int x=0;
    float velMed=0;

    cargarDatosGrales(fecha, distanciaEnMtrs);
    cargarVector(tiempo, maxVueltas, promVueta);
    cout<<"-------------------------IMPRESION DE TODAS LAS VUELTAS-------------------------"<<endl;
    imprimirVueltas(tiempo, maxVueltas);

    cout<<"Ingrese el numero de vuelta que quiere visualizar"<<endl;
    cin>>x;
    cout<<"-------------------------IMPRESION DE LA VUELTA "<<x<<"-------------------------"<<endl;
    imprimirX(tiempo, x, fecha, distanciaEnMtrs);

    velMed=calcularVelocidad(distanciaEnMtrs, promVueta);

    cout<<"-------------------------VELOCIDADES SUPERIORES A LA MEDIA-------------------------"<<endl;
    comparacionVelMed(tiempo, maxVueltas, velMed, distanciaEnMtrs);

    system("pause");
    return 0;
}

/*
LOTE DE PRUEBAS
DIA: 14-6-2021
PISTA: 7,5 km (7500m)

3 vueltas
1° 10m 05s (12,4 m/s)
3° 11m 01s (11,35 m/s)
2° 09m 15s (13,51 m/s)

VEL MEDIA:
7500m/607s= 12,35 m/s
*/