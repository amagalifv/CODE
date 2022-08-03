#include <iostream>
#include<math.h>
using namespace std;

int main () {

    int cantLibre;
    int cantOcup;
    float libre=0;
    float ocupado=0;
    int totAsientos=0;

    cout<<"Ingrese la cantidad de asientos disponibles del vuelo"<<endl;
    cin>>cantLibre;

    cout<<"Ingrese la cantidad de asientos ocupados del vuelo"<<endl;
    cin>>cantOcup;

    totAsientos=cantLibre+cantOcup;

    libre=((float)cantLibre/(float)totAsientos)*100;
    ocupado=((float)cantOcup/(float)totAsientos)*100;

    cout<<"El porcentaje de asientos libres es: "<<libre<<"%"<<endl;
    cout<<"El porcentaje de asientos ocupados es: "<<ocupado<<"%"<<endl;

    system("pause");

    return 0;
}