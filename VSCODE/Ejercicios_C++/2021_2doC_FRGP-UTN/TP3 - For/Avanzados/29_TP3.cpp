#include <iostream>
#include <cstdlib>
using namespace std;

/*
29- Se dispone de una lista de 10 grupos de números y cada uno de los grupos estará
compuesto por 5 números. Se pide determinar e informar:
a) Para cada uno de los 10 grupos el promedio de los números que lo componen. Se informa
un resultado para cada uno de los 10 grupos.
b) Determinar e informar el valor mínimo de todos los grupos, indicando en que grupo se
encontró y su posición relativa en el mismo. Se informan 2 resultados al final de todo.
c) Indicar cuál de los 10 grupos tiene el mayor de los promedios y cuál es ese valor
promedio. Se informan 2 resultados al final de todo.
*/

int main () {
    int num;
    float prom;
    int acum=0;
    int min;
    int grupoMin;
    bool primeraEnt1=true;
    bool primeraEnt2=true;
    int maxProm;
    int grupoMaxProm;

    for (int j=0; j<10; j++) {
        for (int i=0; i<5; i++) {
            cout<<"ingrese un numero"<<endl;
            cin>>num;

            acum+=num;

            if (primeraEnt1=true || min>num) {
                min=num;
                grupoMin=j+1;
            }
        }
        prom=(float)acum/5;
        cout<<"Promedio grupo "<<j+1<<" es: "<<endl;
        acum=0;

        if (primeraEnt2=true || maxProm<prom) {
            maxProm=prom;
            grupoMaxProm=j+1;
        }
    }

    cout<<"Minimo: "<<min<<endl;
    cout<<"Grupo del Min: "<<grupoMin<<endl;
    cout<<""<<endl;
    cout<<"--------------------"<<endl;
    cout<<""<<endl;
    cout<<"Promedio maximo: "<<maxProm<<endl;
    cout<<"Grupo del promedio maximo: "<<grupoMaxProm<<endl;

    system("pause");
    return 0;
}