#include <iostream>
using namespace std;

/*
6) Hacer un programa para que un comercio ingrese por teclado la recaudación en pesos para
cada una de las cuatros semanas del mes. El programa debe listar la recaudación promedio por
semana y el porcentaje de recaudación por semana.
Ejemplo. Si se ingresa $ 1600, $ 1200, $ 4800 y $ 400 se listara como recaudación promedio
$ 2000 y como porcentajes por semana: 20%, 15%, 60% y 5%.
*/

int main () {
    float sem1;
    float sem2;
    float sem3;
    float sem4;
    float cantTot;
    float recauPromSemana;
    float porcSem1;
    float porcSem2;
    float porcSem3;
    float porcSem4;

    //---------------ENTRADAS-------------------
    cout<<"Ingrese la recaudación de la semana 1"<<endl;
    cin>>sem1;
    cout<<"Ingrese la recaudación de la semana 2"<<endl;
    cin>>sem2;
    cout<<"Ingrese la recaudación de la semana 3"<<endl;
    cin>>sem3;
    cout<<"Ingrese la recaudación de la semana 4"<<endl;
    cin>>sem4;

    //---------------PROCESOS-------------------
    cantTot=sem1+sem2+sem3+sem4;
    recauPromSemana=cantTot/4;

    porcSem1=(sem1/cantTot)*100;
    porcSem2=(sem2/cantTot)*100;
    porcSem3=(sem3/cantTot)*100;
    porcSem4=(sem4/cantTot)*100;

    //--------------IMPRESIONES------------
    cout<<"Recaudación promedio: "<<recauPromSemana<<endl;
    cout<<"Porcentaje de recaudación semana 1: "<<porcSem1<<endl;
    cout<<"Porcentaje de recaudación semana 2: "<<porcSem2<<endl;
    cout<<"Porcentaje de recaudación semana 3: "<<porcSem3<<endl;
    cout<<"Porcentaje de recaudación semana 4: "<<porcSem4<<endl;


    system("pause");
    return 0;
}