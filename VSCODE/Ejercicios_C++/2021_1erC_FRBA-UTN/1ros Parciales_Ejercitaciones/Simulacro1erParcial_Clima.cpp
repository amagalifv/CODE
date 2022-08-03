#include <iostream>
using namespace std;

int pedirValor (string mensaje);
void findTempMax ( float valor, float &tempMax);
void findTempMin ( float valor, float &tempMin);
void promedioHume (float valor, int &contHume, float &sumaHume, float &promedio);

int main () {
 float num=0;
 char climaToH;
 float temperatura=0;
 int contHumedad=0;
 float sumaHumedad=0;
 float promedioHumedad=0;
 float tempMaxima=0;
 float tempMinima=0;

 cout << "Ingrese T para registrar temperatura, H para humedad y F para terminar"<<endl;
 cin >>climaToH;

 while (climaToH != 'F'){
    num=pedirValor ("Ingrese el valor a registrar");

    if (climaToH=='T'){
        findTempMax (num, tempMaxima);
        findTempMin (num, tempMinima);
    }else{
        if (climaToH=='H'){
           promedioHume(num, contHumedad, sumaHumedad, promedioHumedad);
        } 
    }
    
    cout << "Ingrese T para registrar temperatura, H para humedad y F para terminar"<<endl;
    cin >>climaToH;
 }

 cout << "El promedio de la humedad es " << promedioHumedad << endl;
 cout << "La temperatura maxima es " << tempMaxima << endl;
 cout << "La temperatura minima es " << tempMinima << endl;

system("pause");
 return 0;
}

int pedirValor (string mensaje){
    int num;
    cout<<mensaje<<endl;
    cin>>num;

    return num;
}

void promedioHume (float valor, int &contHume, float &sumaHume, float &promedio){
 
 sumaHume=sumaHume+valor;
 contHume=contHume+1;
 promedio=sumaHume/contHume;

 return;
}

void findTempMax ( float valor, float &tempMax){
    if (valor > tempMax || tempMax==0){
        tempMax=valor;
    }
return;
}

void findTempMin ( float valor, float &tempMin){
    if (valor < tempMin || tempMin==0){
        tempMin=valor;
    }
return;
}

