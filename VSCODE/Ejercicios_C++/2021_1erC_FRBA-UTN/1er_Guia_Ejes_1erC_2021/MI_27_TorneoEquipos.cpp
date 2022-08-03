#include <iostream>
using namespace std;

int main () {
 
 int cantEquipos;
 int cantEncuentrosXequipo;
 int nroEquipos;
 char resultado;
 int puntajeTotal=0;

 cout <<"Ingrese la cantidad de equipos que hay disputando el torneo"<< endl;
 cin>>cantEquipos;

 for(int i=0; i<cantEquipos;i++){
    cout << "Ingrese un codigo de equipo" << endl;
    cin >> nroEquipos;
    cantEncuentrosXequipo=cantEquipos-1;

    for (int e=1; e<cantEncuentrosXequipo;e++){
     cout << "Ingrese un codigo de resultado" << endl;
     cin >> resultado;   

      switch (resultado){
       case 'P':
          puntajeTotal=puntajeTotal;
          break;
       case 'E':
          puntajeTotal=puntajeTotal+1;
          break;
       case 'G':
          puntajeTotal=puntajeTotal+3;
          break;
      
       default:
        cout<<"Entrada invalida"<<endl;
          break;
      }
     }
  
     cout<<"El equipo "<<nroEquipos<<" obtuvo "<<puntajeTotal<<" puntos"<<endl;

     puntajeTotal=0;
 }


system("pause");
 return 0;
}