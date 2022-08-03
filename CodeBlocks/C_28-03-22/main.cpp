#include <iostream>
#include "funciones.h"
using namespace std;

int main(){
    int mtrz[10][10];
    int opc;

    while(true){
        imprimirMenu(opc);
        int respuesta;
        int fila;
        switch (opc) {
            case 1:
                fila=pedirFila();
                cargarMatriz(mtrz,fila);
                break;
            case 2:
                fila=pedirFila();
                respuesta=maxFila(mtrz, fila);
                cout<<"MAXIMO DE LA FILA:"<<respuesta<<endl;
                break;
            case 3:
                fila=pedirFila();
                respuesta=posMaxFila(mtrz, fila);
                cout<<"COLUMNA DEL MÁXIMO:"<<respuesta<<endl;
                break;
            case 4:
                fila=pedirFila();
                respuesta=sumaDeFila(mtrz, fila);
                cout<<"SUMA DE LA FILA:"<<respuesta<<endl;
                break;
            case 5:
                fila=pedirFila();
                respuesta=contarPositivosDeFila(mtrz, fila);
                cout<<"CANTIDAD DE POSITIVOS DE LA FILA:"<<respuesta<<endl;
                break;
            case 6:
                respuesta=sumaDeMatriz(mtrz);
                cout<<"TOTAL SUMA MATRIZ:"<<respuesta<<endl;
                break;
            case 7:
                //SALIR!!!!!
                break;
            default: cout<<"Opcion Incorrecta, vuelva a intentarlo"<<endl;
                break;
        }
    }


    return 0;
}
