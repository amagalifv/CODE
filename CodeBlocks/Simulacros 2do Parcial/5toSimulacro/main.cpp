# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

#include "Cls_Funcs.h"

int main(){
    Fecha f;

    devuelveFechaActualSistema(&f);

    f.Mostrar();

    system("pause");
    return 0;
}
