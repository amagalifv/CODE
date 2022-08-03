#include <iostream>
using namespace std;

int pedirValor (string mensaje){
    int valor;
    cout<<mensaje<<endl;
    cin>>valor;

 return valor;
}

void vueltaRapida(int durac, int vuel, int &duracMasRapi, int &vueltaMasRapi){
  if (durac<duracMasRapi || duracMasRapi==0 ){
     duracMasRapi=durac;
     vueltaMasRapi=vuel;
    }
 return;
}

void vueltaMasLenta(int durac, int vuel, int &duracMasLento, int &vueltaMasLento){
    if (durac>duracMasLento || duracMasLento==0 ){
     duracMasLento=durac;
     vueltaMasLento=vuel;
    }
 return;
}

float velocidadMedia(float distan, int duracMasRapi, int duracMasLenta){
 float prom=0;
 float distEnMetros=0;
 int tiempoEnSeg=0;

 distEnMetros=distan*1000;

 tiempoEnSeg=((duracMasLenta/100)*60+duracMasLenta%100)-((duracMasRapi/100)*60+duracMasRapi%100);

 prom=distEnMetros/tiempoEnSeg;
 
 //promedio en mtrs/seg;
 return prom;
}

void imprimirValor (int valor, int valor2, string mensaje, string mensaje2){
    cout<<mensaje<<valor<<mensaje2<<valor2<<endl;
 return;
}

int main () {
 int cantidadRegistros=0;
 int vuelta=0;
 int duracion=0;
 float distancia=0;
 int vueltaMasRapida=0;
 int tiempoMasRapido=0;
 int vueltaMasLento=0;
 int tiempoMasLento=0;
 float velocidadMed=0;

 cantidadRegistros=pedirValor("Ingrese la cantidad de registros a evaluar");
 cout<<"Ingrese la longitud de la vuelta"<<endl;
 cin>>distancia;

 for (int i = 0; i < cantidadRegistros; i++){
     vuelta=pedirValor("Ingrese el numero de vuelta");
     
     duracion=pedirValor("Ingrese la duracion de la  vuelta en formato MMSS");

     vueltaRapida(duracion, vuelta, tiempoMasRapido, vueltaMasRapida);

     vueltaMasLenta(duracion, vuelta, tiempoMasLento, vueltaMasLento);
 }

 velocidadMed=velocidadMedia(distancia,tiempoMasRapido,tiempoMasLento);

 imprimirValor(tiempoMasRapido, vueltaMasRapida, "El tiempo record fue ", " en la vuelta ");
 imprimirValor(tiempoMasLento, vueltaMasLento, "El peor tiempo fue ", " en la vuelta ");
 cout<<"La velocidad media fue "<< velocidadMedia<< "m/s" << endl;
 
 system("pause");
 return 0;
}