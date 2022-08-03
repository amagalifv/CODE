#include <iostream>
using namespace std;

// Declaración de funciones y/o procedimientos//

int solicDatosInt(string mensaje);
float solicDatosFloat(string mensaje);
void vueltaMasRapida(int durac, int vuel, int &duracMasRapi, int &vueltaMasRapi);
void vueltaMasLenta(int durac, int vuel, int &duracMasLento, int &vueltaMasLento);
float calcPorcReduccion(int duracMasRapi, int duracMasLenta);
void imprimirDatos (int valor1, int valor2, string mensaje);
int calcularTotalSeg (int duracion);

// Codigo principal //

int main(){

  // Variables //

  int cantidadRegistros = 0; 
  float kiloMetros = 0;
  int duracion = 0;
  int vuelta = 0;
  int vueltaRapida = 0;
  int vueltaLenta = 0;
  int tiempoMasRapido = 0;
  int tiempoMasLento = 0;
  float porcReduccion = 0;

  kiloMetros = solicDatosFloat("Ingrese los Kilometros del circuito cerrado");

  cantidadRegistros = solicDatosInt("Ingrese la cantidad de registros a evaluar");

  cout << "" << endl;
  
  while(cantidadRegistros > 20){

    cantidadRegistros = solicDatosInt("Ingrese una cantidad de vueltas menor o igual a 20");
    
  }

  cout<<"**************** Registro nro "<< 1 <<" ****************"<<endl;

  vuelta = solicDatosInt("Ingrese el numero de la vuelta");

  while(vuelta > 20){

    vuelta = solicDatosInt("Ingrese el numero de la vuelta (<=20)");

  }

  duracion = solicDatosInt("Ingrese el tiempo de la vuelta en formato MMSS");

  cout << "" << endl;

  vueltaRapida = vuelta;
  vueltaLenta = vuelta;
  tiempoMasRapido = duracion;
  tiempoMasLento = duracion;
  
  for(int i = 0; i < cantidadRegistros - 1; i++) {

    cout <<"**************** Registro nro " << i + 2 << " ****************"<< endl;
    vuelta = solicDatosInt("Ingrese el numero de la vuelta");
    duracion = solicDatosInt("Ingrese el tiempo de la vuelta en formato MMSS");
    cout << "" << endl;

    vueltaMasRapida(duracion, vuelta, tiempoMasRapido, vueltaRapida);
    vueltaMasLenta(duracion, vuelta, tiempoMasLento, vueltaLenta);

  }
  
  porcReduccion = calcPorcReduccion(tiempoMasRapido, tiempoMasLento);

  cout<<"***********************************************************"<<endl;
  cout<<"***********************************************************"<<endl;
  cout << "La vuelta mas rapida fue la nro " << vueltaRapida << "." <<endl;
  cout << "El tiempo de la vuelta mas rapida fue de " << calcularTotalSeg(tiempoMasRapido)/60 << " minutos y " << calcularTotalSeg(tiempoMasRapido)%60 << " segundos." << endl;

  cout << "La vuelta mas lenta fue la nro " << vueltaLenta << "."  << endl;
  cout << "El tiempo de la vuelta mas lenta fue de " << calcularTotalSeg (tiempoMasLento)/60 << " minutos y " << calcularTotalSeg (tiempoMasLento)%60 <<" segundos. "<< endl;

  cout << "El porcentaje de reduccion de tiempo entre el peor y el mejor tiempo fue del " << porcReduccion << "%" << "." << endl;
  
  system("pause");

  return 0;
}

// Funciones y/o procedimientos//

int solicDatosInt(string mensaje) {
  
  int datoInt = 0;
  cout << mensaje << endl;
  cin >> datoInt;

  return datoInt;
}

float solicDatosFloat(string mensaje){

  float datoFloat = 0;

  cout << mensaje << endl;
  cin >> datoFloat;

  return datoFloat;
}

void vueltaMasRapida(int durac, int vuel, int &duracMasRapi, int &vueltaMasRapi){

  if (durac<duracMasRapi){

    duracMasRapi=durac;
    vueltaMasRapi=vuel;

  }
  
  return;
}

void vueltaMasLenta(int durac, int vuel, int &duracMasLento, int &vueltaMasLento){

  if (durac>duracMasLento){
    duracMasLento=durac;
    vueltaMasLento=vuel;
  }
  
  return;
}

int calcularTotalSeg (int duracion){
  int mm, ss, totalSS;
  mm=duracion/100;
  ss=duracion-(mm*100);
  totalSS=ss+(mm*60);

  return totalSS;
}

float calcPorcReduccion(int duracMasRapi, int duracMasLenta){

  float porcRed = 0;
  float tMax=0;
  float tMin=0;

  tMin= calcularTotalSeg(duracMasRapi);
  tMax= calcularTotalSeg(duracMasLenta);

  porcRed=((tMin/tMax)-1)*-100;

  if (porcRed==0){
    porcRed=porcRed*-100;
  }

  return porcRed;
}
