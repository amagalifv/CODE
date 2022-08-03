#include <iostream>
using namespace std;

int pedirNum (string mensaje);
int prod (int num1, int num2);

int main () {
 int M=0;
 int N=0;
 int producto=0;

 M= pedirNum ("Ingrese 1er numero");
 N= pedirNum ("Ingrese 2do numero");

 producto=prod (M , N);

 cout << "El producto es entre ambos por sumas sucesivas es: " << producto << endl;

 system ("pause");

 return 0;
}

int pedirNum (string mensaje){
    int num;
    cout << mensaje << endl;
    cin >> num;

    return num;
}

int prod (int num1, int num2){
 int prod=0;

 for (int i=0 ; i<num1 ; i++) {
     prod=prod+num2;
 }
 return prod;
}