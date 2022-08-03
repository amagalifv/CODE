#include <iostream>
using namespace std;

int pedirHHMMSS (string mensaje);
int partirHora(int);
int sumaHorasSeg(int,int);
int conversionHHMMSS(int);

int main () {
    int horaActual=0;
    int tiempoTrans=0;
    int horaActualSeg=0;
    int totHoraEnSeg=0;
    int tiempoTransSeg=0;
    int nuevaHora=0;

    horaActual= pedirHHMMSS ("Ingrese la hora actual con el formato HHMMSS");
    tiempoTrans= pedirHHMMSS ("Ingrese un tiempo a agregar con el formato HHMMSS");

    horaActualSeg = partirHora(horaActual);
    tiempoTransSeg = partirHora(tiempoTrans);

    totHoraEnSeg = sumaHorasSeg (horaActualSeg, tiempoTransSeg);

    nuevaHora = conversionHHMMSS (totHoraEnSeg);

    cout << "La hora luego del tiempo transcurrido es "<< nuevaHora << endl;

    system("pause");
    return 0;
}

int pedirHHMMSS (string mensaje){
    int HHMMSS=0;
    cout<<mensaje<<endl;
    cin>> HHMMSS;

    return HHMMSS;
}

int partirHora(int hora){
    int horas=0;
    int min=0;
    int seg=0;
    int horaEnSegundos=0;

    horas=hora/10000;
    min=(hora % 10000)/100;
    seg= hora % 100;

    horaEnSegundos=horas*3600+min*60+seg;

    return horaEnSegundos;
}

int sumaHorasSeg(int horaActualSeg, int tiempoTransSeg){
    int suma=0;
    suma=horaActualSeg+tiempoTransSeg;

    return suma;
}

int conversionHHMMSS(int horaEnSegundos){
    int horaHHMMSS=0;

    horaHHMMSS= ((horaEnSegundos/3600)%24)*10000;
    horaHHMMSS+= ((horaEnSegundos%3600)/60)*100;
    horaHHMMSS+= horaEnSegundos%60;

    return horaHHMMSS;
}
