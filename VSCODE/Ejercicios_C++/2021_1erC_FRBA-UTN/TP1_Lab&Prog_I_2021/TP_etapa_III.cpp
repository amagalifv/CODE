#include <iostream>
using namespace std;

#define MAX 31

typedef struct{ 
    int dia;   
    int segundos;
    int minutos;
    float velocidad;
}ST_TEMPO;

typedef struct{    
    float disPista;
    int mes;
    int anio;
}ST_REGISTRO;

void leerInt (string mensaje, int &dato) {

    cout<<mensaje<<endl;
    cin>>dato;

    return;
}

void leerFloat (string mensaje, float &dato) {

    cout<<mensaje<<endl;
    cin>>dato;

    return;
}

float calcularVelocidad(float kms, ST_TEMPO tiempo){

    return (kms*1000)/((tiempo.minutos*60)+tiempo.segundos);
}

void cargarVueltas (ST_TEMPO tiempos[], ST_REGISTRO &registro, int dimension){
    int vuelta;
    int MMSS;

    leerInt("Ingrese el mes que desea registrar", registro.mes);
    leerInt("Ingrese el año que desea registrar", registro.anio);
    leerFloat("La distancia del circuito", registro.disPista);

    for (int i = 0; i < dimension; i++) {
    
        leerInt("Ingrese la dia a registrar", vuelta);
        tiempos[vuelta-1].dia=vuelta;
        
        leerInt("Ingrese la duracion de la vuelta en MMSS", MMSS);

        tiempos[vuelta-1].minutos=MMSS/100;
        tiempos[vuelta-1].segundos=MMSS%100;

       tiempos[vuelta-1].velocidad=calcularVelocidad(registro.disPista, tiempos[vuelta-1]);
    }


    return;
}

void ordenarPorVelocidad (ST_TEMPO tiempos[],int dimension){
    int j;
    ST_TEMPO aux;
    int i=0;
    bool ordenado = false;

    while (i < dimension && !ordenado){
        
        ordenado= true; 

        for (int j = 0; j < dimension -i-1 ; j++){
            
            if (tiempos[j].velocidad>tiempos[j+1].velocidad){
                aux = tiempos[j];
                tiempos[j]=tiempos[j+1];
                tiempos[j+1]=aux;
                ordenado = false; 
            }
        }

        i++;
    }
}

void imprimir(ST_TEMPO tiempos[], int posicion, string mensaje, ST_REGISTRO registro) {

    cout<<mensaje<<tiempos[posicion].dia<<"/"<<registro.mes<<"/"<<registro.anio<<endl;
    cout<<"Su tiempo fue: "<<tiempos[posicion].minutos<<" min "<< tiempos[posicion].segundos<<" seg"<<endl;
    cout<<"Su velocidad media fue: "<<tiempos[posicion].velocidad<<" m/s "<<endl;
    cout<<"Distncia del circuito: "<<registro.disPista<<" km "<<endl;

    return;
}

int main () {
    ST_REGISTRO registro;
    ST_TEMPO tiempos[MAX];
    int dimension;

    cout<<"Ingrese la cantidad de dias a registrar"<<endl;
    cin>>dimension;

    cargarVueltas(tiempos, registro,dimension);

    ordenarPorVelocidad(tiempos,dimension);

    cout<<endl;
    cout<<"----------------------------------------------------"<<endl;
    imprimir(tiempos, 0, "La vueta mas LENTA es la del dia: ", registro);
    cout<<endl;

    cout<<"----------------------------------------------------"<<endl;
    imprimir(tiempos, dimension-1 , "La vueta mas RAPIDA es la del dia: ", registro);
    cout<<endl;
 
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