#include <iostream>
using namespace std;

int pedirNum (string mensaje);
int recursivaDelProducto (int num, int veces);

int main () {
 int M=0;
 int N=0;
 int producto=0;

 M= pedirNum ("Ingrese 1er numero");
 N= pedirNum ("Ingrese 2do numero");

 producto=recursivaDelProducto(M , N);

 cout << "El producto es entre ambos por sumas sucesivas es: " << producto << endl;

system("pause");
 return 0;
}

int pedirNum (string mensaje){
    int num;
    cout << mensaje << endl;
    cin >> num;

    return num;
}

int recursivaDelProducto (int num, int veces){
    if (veces==1){
        return num;
    }else{
        return num+recursivaDelProducto(num,veces-1);
    }
}
