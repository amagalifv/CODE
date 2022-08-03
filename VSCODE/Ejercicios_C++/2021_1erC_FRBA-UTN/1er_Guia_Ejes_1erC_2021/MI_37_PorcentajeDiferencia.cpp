#include <iostream>
using namespace std;

int pedirNumero (string mensaje);
float calcularPorctDif (int num1, int num2);

int main () {
 int numA=0;
 int numB=0;
 float porcentajeDif=0;


 numA=pedirNumero("Ingrese un valor");
 numB=pedirNumero("Ingrese otro valor");

 porcentajeDif=calcularPorctDif (numA, numB);

 cout << "El porcentaje diferencia entre los dos valores es %"<< porcentajeDif<< endl;

 system("pause");
 return 0;
}

int pedirNumero (string mensaje){
    int num;
    cout << mensaje << endl;
    cin >> num;

    return num;
}

float calcularPorctDif (int num1, int num2){
    float porctDif=0;
    porctDif=(num2-num1)*100/(num1+num2);

    return porctDif;
}