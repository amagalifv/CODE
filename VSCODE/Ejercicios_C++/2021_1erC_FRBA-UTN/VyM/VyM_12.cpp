#include <iostream>
using namespace std;

#define N_VALORES 40

void cargarVector (int vector[], int dimension);
void siEsIgual(int vector[], int dimension, int pesquisa, int &esIgualPos, bool &esIgual);
void entrePosiciones(int vector[], int dimension, int pesquisa);
void mayorMenor(int vector[], int dimension, int pesquisa);

int main () {

 int dimension=0;
 int pesquisa=0;
 int vector[N_VALORES]={0};
 int esIgualPosicion=0;
 bool esIgual=false;


 cout<<"Ingresar la longitud del conjunto"<<endl;
 cin>>dimension;

 cargarVector(vector, dimension);

 cout<<"Ingresar el valor pesquisa"<<endl;
 cin>>pesquisa;


 siEsIgual(vector, dimension, pesquisa, esIgualPosicion, esIgual);
 if (esIgual==true){
     cout<<"La pesquisa -"<<pesquisa<<"- es igual al "<<esIgualPosicion+1<< " ingreso"<<endl;
 }else{
     entrePosiciones(vector, dimension, pesquisa);
     mayorMenor(vector, dimension, pesquisa);
 }
 
 system("pause");
 return 0;
}

void cargarVector (int vector[], int dimension){
 for (int i = 0; i < dimension; i++){
     cout<<"Ingrese un valor del conjunto"<<endl;
     cin>>vector[i];
 }
}

void siEsIgual(int vector[], int dimension, int pesquisa, int &esIgualPos, bool &esIgual){
 
  for (int i = 0; i < dimension; i++){
     if (vector[i]==pesquisa){
         esIgualPos=i;
         esIgual=true;
     }
 }
}

void entrePosiciones(int vector[], int dimension, int pesquisa){
 
    for (int i = 0; i < dimension; i++){
  
        if (vector[i]<pesquisa && pesquisa<vector[i+1]){
            cout<<"El valor de pequisa se encuentra entre la posicion "<<i+1<<" y "<<i+2<<endl;
        }
    }
}

void mayorMenor(int vector[], int dimension, int pesquisa){
    if (pesquisa<vector[0]){
        cout << "La pesquisa es menor que la primera entrada"<<endl;
    }else{
        if (pesquisa>vector[dimension-1]){
            cout << "La pesquisa es mayor a la ultima entrada"<<endl;
        }  
    } 
}