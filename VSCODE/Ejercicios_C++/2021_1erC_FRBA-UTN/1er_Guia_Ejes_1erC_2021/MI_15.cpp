#include <iostream>
using namespace std;

int main () {
 float tipoInf;
 float valorM;
 float totalLeves=0;
 float totalMod=0;
 float totalGraves=0;
 float contadorClausura=0;
 string motivoInf;
 char gravedadInf;
 int cantInf;
 int i=0;

 cout << "Ingrese la cantidad de infracciones a cargar" << endl;
 cin >> cantInf;

 for (i=0; i<cantInf ; i++) {
     cout << "Ingrese el tipo de infraccion (1,2,3 o 4)" << endl;
     cin >> tipoInf;
     cout << "Ingrese el motivo de la infraccion" << endl;
     cin >> motivoInf;
     cout << "Ingrese el valor de la multa" << endl;
     cin >> valorM;
     cout << "Ingrese la gravedad de la infraccion (L, M o G)" << endl;
     cin >> gravedadInf;

     if (gravedadInf== 'L'){
         totalLeves=totalLeves + valorM;
     }

     if (gravedadInf== 'M'){
         totalMod=totalMod + valorM;
     }

     if (gravedadInf== 'G'){
         totalGraves=totalGraves + valorM;
     }
     
     if (tipoInf==3 !! tipoInf==4 && gravedadInf == 'G') {
         contadorClausura=contadorClausura+1;
     }
 }
 
 cout << "El valor total  de multas leves es $" << totalLeves << endl;
 cout << "El valor total  de multas moderadas es $" << totalMod << endl;
 cout << "El valor total  de multas graves es $" << totalGraves << endl;

if ( contadorClausura>3) {
    cout << "Clausurar fábrica" << endl;
}

 return 0;

}
