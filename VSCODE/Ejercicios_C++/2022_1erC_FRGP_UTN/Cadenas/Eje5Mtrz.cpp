#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

/*
5) Hacer un programa para cargar y mostrar una matriz de char de 5x10 de la siguiente manera:
- Con palabras de hasta 9 caracteres.
- Con palabras de 10 o más caracteres.
(NO SE PUEDE OMITIR LA CANT DE COLUMNAS EN UNA MATRIZ !!!! pq el compilador no sabe hasta donde saltan dentro de un for por ejemplo
las matrices en pemoria se cargan en "una tira o fila" y el compilador necesita saber cuantas posiciones saltar para ir a la proxima fila así evitamos acceder a posiciones de memoria que no están asignadas a mi programa o variable)
Analizar y explicar las diferencias que se producen al mostrar palabra por palabra el contenido de la matriz.
*/

// PARA MATRICES
void cargarCadenas(char *pal, int tam){
    int i;
    fflush(stdin);

    for(i=0;i<tam;i++){
        pal[i]=cin.get();

	    if(pal[i]=='\n') break;
	}

    pal[i]='\0';
    fflush(stdin);
}

void cargarCadenas2 (char mtrz[][10], int filas, int columnas){
    for (int i=0; i<filas; i++) {
        cargarCadenas(*(mtrz+i),columnas-1);
    }
}

void cargarCadenas3(char mtrz[][10], int filas){

    for(int i=0;i<filas;i++){
        cin.getline(mtrz[i],9);
    }
}

void mostrarCadenas(char mtrz[][10], int fila){

    for (int j=0; j<fila; j++) {

        cout<<mtrz[j]<<endl;

    }

    cout<<endl;
}

int main () {
    char vMtrz[5][10];/*={"uno","dos","tres","cuatro","cinco"};*/

    cargarCadenas2(vMtrz,5,10);
    //cargarCadenas3(vMtrz,2);

    mostrarCadenas(vMtrz,2);


    system("pause");
    return 0;
}