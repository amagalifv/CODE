#include <iostream>
using namespace std;

#define CANT_ALU 50

void cargarVector (int vecEdades[CANT_ALU], int dimension) {
 
    for (int i = 0; i < dimension; i++){
        cout<<"Ingrese la edad"<< endl;
        cin>> vecEdades[i];
        cout<<endl;    
    }

 return; 
}

float promedioEdades (int vecEdades[CANT_ALU], int dimension){
 float promedioEd=0;
 int sumEd=0;

 for (int i = 0; i < dimension; i++){
    sumEd+=vecEdades[i];    
 }
 
 promedioEd=sumEd/dimension;

return promedioEd;
}

int masDelPromedio (int vecEdades[CANT_ALU], int dimension, float promedio){
 int cont=0;

 for (int i = 0; i < dimension; i++){
    if (vecEdades[i]>promedio) {
        cont++;   
    }   
 }
return cont;
}

void imprimir (int variable, string mensaje) {

 cout<<mensaje<<variable<<endl;

 return;
}

int main () {
 int vecEdades[CANT_ALU]={0};
 int dimension;
 float promedioEdads;
 int masQueElPromedio;


 cout<<"Ingrese la cantidad de alumnos que se inscribieron";
 cin>>dimension;
 cout<<endl;

 cargarVector(vecEdades, dimension);

 promedioEdads=promedioEdades(vecEdades, dimension);

 masQueElPromedio=masDelPromedio(vecEdades, dimension, promedioEdads);

 imprimir(masQueElPromedio, "La cantidad de alumnos que superan la edad promedio es:  ");
 
 system("pause");
 return 0;
}
