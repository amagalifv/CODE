#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool fechavalida(int d, int m, int a){
    bool bandera=true;
    int v[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int anioActual;

    //chequear dia segun mes
    if(d>=v[m-1]){
        if (d==29 && m==2 && a%4==0) {
            //chequear febrero y año bisiesto
            if (a%100==0 && a%400!=0){bandera=false;}
            else{ bandera=true;}
        }else{bandera=false;}
    }

    //chequear mes
    if (m<1 || m>12){bandera=false;}

    //chequear año
    time_t fechaActual; // tipo de dato de tiempo de la libreria ctime
    time(&fechaActual); //guarda el tiempo del sistema en la variable de tipo tiempo
    struct tm *pST_tiempo = localtime(&fechaActual); // uso la estructura de la libreria para separar la hora del dia mes y año
    anioActual=pST_tiempo->tm_year+1900; // le sumo 1900 pq nos da la cant de años que transcurrieron desde ese año
    if (a<1900 || a>anioActual) {bandera=false;}

    return bandera;
}

int main () {
    int aux;
    //bool aux;
    //aux=fechavalida(29,2,2000);
    //cout<<aux<<endl;

    time_t fechaActual; // tipo de dato de tiempo de la libreria ctime
    time(&fechaActual); //guarda el tiempo del sistema en la variable de tipo tiempo
    struct tm *pST_tiempo = localtime(&fechaActual); // uso la estructura de la libreria para separar la hora del dia mes y año
    aux=pST_tiempo->tm_year+1900;// le sumo 1900 pq nos da la cant de años que transcurrieron desde ese año
    cout<<aux<<endl;

    system("pause");
    return 0;
}