#include <iostream>
using namespace std;

int busquedaBinaria (ST_VENTAS arr[], int n, int x){
    //Cuando arranco evaluo todo elvector de 0 a n-1
    int inicio=0;
    int fin = n-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        //si el elemento es el del medio, devolvemos la posicion
        if (arr[mitad]==x){
            return mitad;
        }

         //si el elemento es menor entonces solo puede estar en la primera mitad
         if (arr[mitad]>x){
             fin=mitad - 1; //Cambio el limite superior
         }else{
             inicio=mitad+1; //Cambio el limite inferior
         }
    }
    // Si llegamos hasta aca es que el elemento no estaba
    return -1;
}

//*BENEFICIOS*
//Eficiente
//Simple
//Requiere que el conjunto se encuenre ordenando
//No impone otras condiciones sobre el conjunto de datos

int busquedaBinariaEstructuras (ST_VENTAS arr[], int cant, int nro_factura){
    //Cuando arranco evaluo todo elvector de 0 a n-1
    int inicio=0;
    int fin = cant -1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        //si el elemento es el del medio, devolvemos la posicion
        if (arr[mitad].nro_factura==nro_factura){
            return mitad;
        }

         //si el elemento es menor entonces solo puede estar en la primera mitad
         if (arr[mitad].nro_factura>nro_factura){
             fin=mitad - 1; //Cambio el limite superior
         }else{
             inicio=mitad+1; //Cambio el limite inferior
         }
    }
}

int main () {


system("pause");
 return 0;
}