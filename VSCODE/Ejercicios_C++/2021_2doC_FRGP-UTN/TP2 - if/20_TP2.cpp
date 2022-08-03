#include <iostream>
#include<math.h>
#include <cstdlib>
using namespace std;

/*
20- Una fábrica abona a sus empleados un pago semanal a partir de las horas trabajadas y de
acuerdo a las siguientes escalas.
Las primeras 40 horas se pagan a un valor de $ 300 cada una.
Las horas excedentes de las 40 horas se pagan a un valor de $ 450 cada una.
Las horas excedentes de las 50 horas se pagan a un valor de $ 600 cada una.
Hacer un programa para que, dadas las horas trabajadas por un empleado, el programa calcule
e informe el total a pagar por las mismas.
Ejemplo 1. Si el empleado trabajó 40 horas, se le abonará 40 x 300 = 12.000
Ejemplo 2. Si el empleado trabajó 45 horas, se le abonará 40 x 300 + 5 x 450 = 14.250.
Ejemplo 3. Si el empleado trabajó 52 horas, se le abonará 40 x 300 + 10 x 450 + 2 x 600 =
17.700.
*/

int main () {
    int horasPepe;
    int aux=0;
    int tot=0;

    cout<<"Ingrese las horas trabajadas: "<<endl;
    cin>>horasPepe;

    aux=horasPepe;

    if (aux>50){
        tot=(aux-50)*600;
        aux=aux-(aux-50);
        tot+=(aux-40)*450;
        aux=aux-(aux-40);
        tot+=aux*300;
    } else if (40<aux &&  aux<=50){
        tot+=(aux-40)*450;
        aux=aux-(aux-40);
        tot+=aux*300;
    } else {
        tot+=aux*300;
    }

    cout<<"Sueldo: $"<<tot<<endl;

    system("pause");
    return 0;
}