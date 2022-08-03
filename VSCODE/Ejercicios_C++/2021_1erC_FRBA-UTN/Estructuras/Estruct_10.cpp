#include <iostream>
using namespace std;

typedef struct {
int codigoLib;
string autor;
int stockLocal;
string titulo;
string editorial;
string genero;
}ST_LOCAL;

typedef struct {
int codigoLibro;
int stockDepo;
}ST_DEPO;

void lista_Stock (ST_LOCAL vectorL[], ST_DEPO vectorD[],int dimensionL, int dimensionD){
  int i = 0, j = 0;
    int k = 0;

    while (i < dimensionL && j <dimensionD) {

        if (vectorL[i].stockLocal==0 && vectorD[j].stockDepo==0) {
        
        
        
        }

        if (vectorL[i].codigoLib < vectorD[j].codigoLibro) {

            cout<<"Falta en Local"<<endl;
            i++;
            
        } else {
            cout<<"Falta en Deposito"<<endl;
            j++;
        }

        k++;
    }

    while(i < dimensionL) {
        vecC[k] = vectorL[i];
        i++;
        k++;
    }

    while(j < dimensionD) {
        vecC[k] = vectorD[j];
        j++;
        k++;
    }

return;
}

int main () {
 int dimensionL=5;
 int dimensionD=4;
 //cout << "Ingrese la cantidad de libros en inventario"<<endl; 
 //cin >> dimension;

 ST_LOCAL vectorL[5]={{1010,"Pepe",1,"Juegos","Estrada","Cuento"},{1011,"Alberto",0,"La jugada","Biblos","Suspenso"},{1012,"Juan",0,"Los coders","BCG","Comedia"},{1013,"Pedro",3,"La pegada","Sudameriacana","Aventura"}};
 ST_DEPO vectorD[4]={{1010,0},{1011,1},{1012,0},{1013,2},{1014,0}};

 
 
 system("pause");
 return 0;
}