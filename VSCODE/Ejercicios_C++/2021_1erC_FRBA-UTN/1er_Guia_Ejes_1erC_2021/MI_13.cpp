#include <iostream>
using namespace std;

int main () {
 int i=0;
 int M=0;
 int N=0;
 int producto=0;

 cout << "Ingrese un numero";
 cin >> M;
 cout << "Ingrese otro numero";
 cin >> N;

 for (i=0 ; i<M ; i++) {
     producto=producto+N;
 }

 cout << "El producto es: " << producto << endl;

system ("pause");

 return 0;
}



