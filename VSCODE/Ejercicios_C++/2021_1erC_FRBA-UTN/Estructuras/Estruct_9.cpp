#include <iostream>
using namespace std;

#define MAX_VEC 50

typedef struct {
int legajo;
int codigoMat;
string ApeNom;
}ST_MAESTRO;

typedef struct {
int legajo;
int codigoMat;
string ApeNom;
}ST_DIARIO;

typedef struct {
int legajo;
int codigoMat;
string ApeNom;
}ST_FINALES_ACT;

void cargarVectores(ST_MAESTRO vecMaestro[], int dimensionM, ST_DIARIO vecDia[], int dimensionD){
    
}

void ApareoFinales (ST_MAESTRO vecMaestro[], ST_DIARIO vecDia[],ST_FINALES_ACT vecActa[], int dimensionM, int dimensionD) {
    
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < dimensionM && j < dimensionD) {

        if (vecMaestro[i].codigoMat < vecDia[j].codigoMat) {

            vecActa[k] = vecMaestro[i];
            i++;
            
        } else {
            vecActa[k] = vecDia[j];
            j++;
        }

        k++;
    }

    while(i < dimensionM) {
        vecActa[k] = vecMaestro[i];
        i++;
        k++;
    }

    while(j < dimensionD) {
        vecActa[k] = vecDia[j];
        j++;
        k++;
    }

return;
}



int main () {
 ST_MAESTRO vecMaestro[2]={{2234,1,"Pepe"},{2240,4,"Pedro"}};
 ST_DIARIO vecDia[2]={{2237,1,"Gustavo"},{2241,3,"Gaston"}};
 ST_FINALES_ACT vecActa[2+2];

 ApareoFinales(vecMaestro,vecDia,vecActa,2,2);


 system("pause");
 return 0;
}