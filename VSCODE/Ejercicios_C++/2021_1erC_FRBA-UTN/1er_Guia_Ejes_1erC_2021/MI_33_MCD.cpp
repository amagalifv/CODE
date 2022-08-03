#include <iostream>
using namespace std;

int pedirNum (string mensaje);
int calcularMCD (int num1, int num2);
void imprimirMCD (string mensaje, int &mcd);

int main () {
    int num1 = 0;
    int num2 = 0;
    int mcd;

    num1= pedirNum ("Ingrese 1er nro");
    num2= pedirNum ("Ingrese 2do nro");

    mcd = calcularMCD (num1, num2);

 cout <<  "El MCD entre " << num1 << " y " << num2 << " es: " << mcd << endl;

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






