#include <iostream>
using namespace std;

#define MAX_ENT 1000

void cargarVector(int vec[], int dimension){
 
    for (int i = 0; i < dimension; i++) {
        cout<<"Ingrese un valor "<< endl;
        cin>>vec[i];
    }

return;
}

void buscarMayor (int vec[], int dimension, int &mayor, int &posMayor) {
 bool primeraEntrada=true;

 for (int i = 0; i < dimension; i++) {
     
    if (primeraEntrada==true || vec[i]>mayor){
        mayor=vec[i];

        posMayor=i;
        if (posMayor<i ) {
            posMayor=i;
        }
        primeraEntrada=false;
    }
 }

 return;
}

void contarPosMaj (int vec[], int dimension, int mayor, int vecPos[]) {
 int j=0;

 for (int i = 0; i < dimension; i++) {
     
    if (mayor==vec[i]){
        vecPos[j]=i;
        j++;
    }
 }

 return;
}

void imprimirVector (int vector[], int dimension, string mensaje) {
 
 cout<<mensaje;
 for (int i = 0; i < dimension; i++) {
  cout<<vector[i]<<"  ";
 }


return;
}

int main () {
 int vec[MAX_ENT]={0};
 int dimension=0;
 int mayor;
 int posMayor=-1;
 int vecPos[MAX_ENT]={0};

 cout<<"Ingrese la dimension "<<endl;
 cin>>dimension;

 cargarVector(vec, dimension);
 imprimirVector(vec, dimension, "Vector: ");
 cout<<endl;
 cout<<"-----------------------------------------------"<<endl;
 
 
 buscarMayor(vec, dimension, mayor, posMayor);
 cout<<"El mayor ingreso fue: "<<mayor<<" y su primer aparicion fue "<<posMayor<<endl;
 cout<<"-----------------------------------------------"<<endl;
 
 contarPosMaj(vec, dimension, mayor, vecPos);
 imprimirVector(vecPos, dimension, "El mayor aparecio en las posiciones: ");
 cout<<endl;
 cout<<"-----------------------------------------------"<<endl;
 
 system("pause");
 return 0;
}