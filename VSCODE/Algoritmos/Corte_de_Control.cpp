#include <iostream>
using namespace std;
/* ORDENADO PREVIAMENTE POR EL CRITERIO QUE VOY A UTILIZAR
PERMITE OBTENER:
-listados, promedios, cantidades, etc.Agrupados por 
algun criterio, y aparte de la base de que los datos 
originales cumplen o se puede hacer que cumplan con 
el agrupamiento necesario para su procesamiento.

-obtener info a partir de un conj de datos de forma
eficiente realizando la menor cantidad de lecturas
posibles
*/

typedef struct {
 int dni;
 string  nombreApellido;
 int provincia;

}ST_HABITANTE;


void contarHabPorProv(ST_HABITANTE vec[], int n) {
 int i = 0;
 int contadorHab = 0;
 int key;

 while(i < n) {//para todo el vector

    key = vec[i].provincia;

    contadorHab = 0;

    while(i < n && key == vec[i].provincia) {//para el agrupamiento que quiero hacer

        contadorHab++;
        
        i++; 
    }

    cout << "Provincia: " << key << " habitantes: " << contadorHab << endl;
 }
 return;
}


int main () {




 
 system("pause");
 return 0;
}

struct MiEstructura{
 int codigo;
 //...
};

void corteDeControl(MiEstructura vec[],  int cantDeElem){
    int i=0;
    int resultados=0;
    int key;
    int terceraCondicion;//esta es la condicion extra

    while(i<cantDeElem){
        key=vec[i].codigo;

        resultados=0;

        while(i<cantDeElem && key == vec[i].codigo){
            resultados++;
            i++;

            //key2=...
            //resultado2=0; 

            //Con una condicion extra
            while(i<cantDeElem && key == vec[i].codigo && terceraCondicion){
                //... Se repiten las condiciones anteriores y se agrega la 
                // siguinte clave a evaluar.

                //LA VARIABLE QUE ME PERMITE AVANZAR SOLO LA
                //INCREMENTO EN EL WHILE MAS ANIDADO...
                // SERIA ACA
                //i++;
            }
            //Muestro resul pareciales cada vez q salgo de un while


            //cada vez que salgo de un while tengo que 
            //resetear mis acumuladores
        }
    }
}