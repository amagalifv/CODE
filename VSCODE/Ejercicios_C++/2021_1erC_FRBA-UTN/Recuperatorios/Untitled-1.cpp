#include <iostream>
using namespace std;

#define MAX 33

typedef struct{
    int legajo;
    string email;
    string apellido;
    string nombre;
    int codigoMat;
    int nota;
}ST_ALUMNO;

void impresion (ST_ALUMNO laboratorio[], ST_ALUMNO programacion[], int dimeL, int dimeP){
    int i = 0, j = 0;
    int k = 0;
    ST_ALUMNO consolidado[dimeL+dimeP];
    int dimeC;

    while (i < dimeL && j < dimeP) {

        if (laboratorio[i].legajo < programacion[j].legajo) {

            consolidado[k] = laboratorio[i];
            i++;
            
        } else {
            consolidado[k] = programacion[j];
            j++;
        }

        k++;
    }

    while(i < dimeL) {
        consolidado[k] = laboratorio[i];
        i++;
        k++;
    }

    while(j < dimeP) {
        consolidado[k] = programacion[j];
        j++;
        k++;
    }

    dimeC=k;

    int l = 0;
    int contador = 0;
    int key;

    while(l < dimeC) {

        key = consolidado[l].legajo;

        contador = 0;

        while(l < dimeC && key == consolidado[l].legajo) {

            if (consolidado[l].nota>=6){
                contador++;
            }
            
            l++; 
        }

        if (contador>=1){
            cout<<"Legajo: "<<key<<"\t email: "<<consolidado[l-1].email<<"\t apellido: "<<consolidado[l-1].apellido<<endl;
        }

    }

    return;
}

int main () {
    int dimeL=3;
    int dimeP=3;
    ST_ALUMNO laboratorio[dimeL]={{010,"mail","pepe","pepe",1,6},{011,"email","arturo","arturo",1,5},{012,"email","juan","juan",1,5}};
    ST_ALUMNO programacion[dimeP]={{010,"mail", "pepe","pepe",2,6},{011,"email","arturo","arturo",2,4},{012,"email","juan","juan",2,6}};
    
    impresion(laboratorio,programacion,dimeL,dimeP);

    system("pause");
    return 0;