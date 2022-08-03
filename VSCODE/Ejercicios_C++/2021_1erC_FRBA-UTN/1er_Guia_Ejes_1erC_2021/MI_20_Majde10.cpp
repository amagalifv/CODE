#include <iostream>
using namespace std;

int main () {
    int num =0;
    int mayor=0;
    int i=0;

    for (i=0 ; i < 10 ; i++) {
        cout << "Ingrese un valor" << endl;
        cin >> num;

        if (num>mayor || mayor==0){
        mayor = num;
        }

    }

    cout << "El mayor numero ingresado es " << mayor << endl;

    system("pause");
    return 0;
}
