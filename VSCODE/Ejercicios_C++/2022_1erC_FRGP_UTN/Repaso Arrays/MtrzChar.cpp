#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

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

void mostrarMatrizCadenas(char mCadenas[][21], int filas){

    for (int i=0; i<filas; i++) {
        int j=0;

        while(mCadenas[i][j]!='\0'){
            cout<<mCadenas[i][j];
            j++;
        }
    }

}

int main () {
    char mCadenas[5][21];

    cargarCadenas(*mCadenas,5);

    mostrarMatrizCadenas(mCadenas,5);

    system("pause");
    return 0;
}