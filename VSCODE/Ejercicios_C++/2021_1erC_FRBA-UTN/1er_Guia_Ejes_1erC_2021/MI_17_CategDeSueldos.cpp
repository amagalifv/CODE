#include <iostream>
using namespace std;

int main () {
    float sueldo;
    int empCat1520=0;
    int empCat2780=0;
    int empCat5999=0;
    int empCat5999Mas=0;

    cout << "Ingrese el sueldo de un empleado, 0 para terminar" << endl;
    cin >> sueldo;

    while (sueldo!=0) {
        if (sueldo < 0) {
            cout << "Entrada invalida" << endl;
        } else {
            if (sueldo < 1520) {
                empCat1520=empCat1520+1;
            } else {
                if (sueldo < 2780) {
                    empCat2780=empCat2780+1;
                } else {
                    if (sueldo < 5999) {
                        empCat5999=empCat5999+1;
                    } else {
                        empCat5999Mas=empCat5999Mas+1;
                    }
                }
            }
        }

        cout << "Ingrese el sueldo de un empleado, 0 para terminar" << endl;
        cin >> sueldo;
    }

    cout << "La cantidad de empleados con sueldo de hasta $1520 es: " << empCat1520 << endl;
    cout << "La cantidad de empleados con sueldo de hasta $2780 es: " << empCat2780 << endl;
    cout << "La cantidad de empleados con sueldo de hasta $5999 es: " << empCat5999 << endl;
    cout << "La cantidad de empleados con sueldo superior a $5999 es: " << empCat5999Mas << endl;

    return 0;
}
