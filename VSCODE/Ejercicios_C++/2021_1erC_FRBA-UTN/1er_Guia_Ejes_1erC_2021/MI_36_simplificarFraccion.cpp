#include <iostream>
using namespace std;

int pedirNum (string mensaje);
int calcularMCD (int num1, int num2);

int main () {

    int nume = 0;
    int deno = 0;
    int mcd=0;

    nume= pedirNum ("Ingrese 1er nro");
    deno= pedirNum ("Ingrese 2do nro");

    while (deno != 1){
    mcd = calcularMCD (nume, deno);
    nume=nume/mcd;
    deno=deno/mcd;
    }

    cout <<  "El numerador de la fraccion simplificado queda en " << nume << " y el denominador en " << deno << endl;

    system("pause");
    return 0;
}

int pedirNum (string mensaje){
    int num;
    cout << mensaje << endl;
    cin >> num;

    return num;
}

int calcularMCD (int num1, int num2){
    int resto;

    resto= num1 % num2;

    while (resto != 0){
    num1 = num2;
    num2=resto;
    resto= num1 % num2;
    }
    return num2;
}