#include <iostream>
using namespace std;

int pedirNum (string mensaje);

int main () {

 int temperatura=0;
 int precipitacion=0;
 int producto=0;
 int dia=1;
 int hora=0;
 int temperaturaMin=0;
 int temperaturaMinHora;
 int temperaturaMinDia;
 int sumLluvia=0;
 int sumLluviaMaj=0;
 int sumLluviaMajDia=0;
 


 for (int i = 1; i <=7; i++){
    
    for (int e = 0; e < 23; e++){
        temperatura= pedirNum ("Ingrese la temperatura de la hora");
        precipitacion=pedirNum ("Ingrese la precipitacion de la hora");
 
        if (temperaturaMin<temperatura || temperaturaMin==0){
            temperaturaMin=temperatura;
            temperaturaMinHora=e;
            temperaturaMinDia=i;
      }
      sumLluvia=sumLluvia+precipitacion;

    }
     
   if (sumLluvia>sumLluviaMaj || sumLluviaMaj==0 ){
      sumLluviaMaj=sumLluviaMaj;
      sumLluviaMajDia=i;
   }
     
 }
 
 
system("pause");
 return 0;
}

int pedirNum (string mensaje){
    int num;
    cout << mensaje << endl;
    cin >> num;

    return num;
}
