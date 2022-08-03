#include <iostream>
using namespace std;

int main () {
    int valores=0;
    int sumValores=0;

    cout << "Ingrese un valor" << endl;
    cin >> valores;

    while (valores >= 0) {
        sumValores=sumValores+1;
        cout << "Ingrese un valor" << endl;
        cin >> valores;
    }

    cout << "La cantidad de valores no negativos ingresados es " << sumValores << endl;

    return 0;
}
