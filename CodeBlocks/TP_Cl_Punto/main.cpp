#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "funciones.h"

int main () {
    Punto dibu('.');

    //dibu.dibPunto(5,2);

    //dibu.dibLineaHoriz(0, 6, 20);

    dibu.dibRectangulo (3, 6, 20, 10);

    system("pause");
    return 0;
}