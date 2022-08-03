#include <iostream>
using namespace std;

int main () {
    int valPositivos=0;
    int subLotes=0;
    int sumPromedio=0;
    float promedio=0;
    int contadorProm=0;
    int maximoSubLote=0;
    int contadorSubLote=0;
    int minimoSublote=0;
    int iSubLotes=0;
    int iPosicion=0;
    int iPosicionMaj=0;

    cout << "Ingrese un valor positivo, 0 para cambiar de sublote y negativo para finalizar";
    cin >> valPositivos;

    while (valPositivos>=0){
        while ( valPositivos > 0 ){
            sumPromedio=sumPromedio+valPositivos;
            contadorProm ++;
            iPosicion ++;


            if ( valPositivos > maximoSubLote || maximoSubLote==0 ){
            maximoSubLote=valPositivos;
            iPosicionMaj=iPosicion;
            }

            if ( valPositivos < minimoSublote || minimoSublote==0 ){
                minimoSublote=valPositivos;
            }

            cout << "Ingrese otro valor, 0 para cambiar de sublote y negativo para finalizar";
            cin >> valPositivos;
        }

        iSubLotes=iSubLotes+1;
        

        if(contadorProm>0){
            promedio= sumPromedio/contadorProm;
            cout << "El promedio del sublote es " << promedio << endl;
        }

        cout << "El maximo del sublote es: " << maximoSubLote << " y su posicion relativa es " << iPosicionMaj << endl;
        cout << "El minimo del sublote es: " << minimoSublote << endl;

        valPositivos=0;
		subLotes=0;
		sumPromedio=0;
		promedio=0;
		contadorProm=0;
		maximoSubLote=0;
		contadorSubLote=0;
		minimoSublote=0;
		iPosicion=0;
		iPosicionMaj=0;

        cout << "Ingrese un valor positivo, 0 para cambiar de sublote y negativo para finalizar";
        cin >> valPositivos;
    }
 
    cout << "La cantidad de sublotes, incluidos los lotes vacios, ingresados es " << iSubLotes << endl;
    
 system("pause");
 return 0;
}