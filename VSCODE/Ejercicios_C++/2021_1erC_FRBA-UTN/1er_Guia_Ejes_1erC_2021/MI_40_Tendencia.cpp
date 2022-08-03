#include <iostream>
using namespace std;

int pedirValor (string mensaje);
void tendencia (int A, int B, string &mensaje);

int main () {
 int A=0;
 int B=0;
 string mensaje;

 A= pedirValor("ingrese e primer dato");
 B= pedirValor("ingrese el segundo dato");

 tendencia(A, B, mensaje);

 cout << "La tendencia es " << mensaje << endl;

system("pause");
 return 0;
}

int pedirValor (string mensaje){
    int num;
    cout<<mensaje<<endl;
    cin>>num;

    return num;
}

void tendencia (int A, int B, string &mensaje){
 int resta=0;
 resta=B-A;

 if (resta<0){
     mensaje= "Decreciente";
 }else{
     if (resta<A*0.05){
         mensaje="Leve ascenso";
     }else{
         if (resta< A*0.02){
             mensaje="Estable";
         }else{
             mensaje="En ascenso";
         }
     }
 }
 
 return;
}