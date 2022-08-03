#include <iostream>
#include <cstdlib>
using namespace std;

int main () {
    int nroPais;
    char genero;
    int cantAtle;
    int mejorPuesto;
    int acuAtletasTot=0;
    int acuAtletas=0;
    int contComp25=0;
    int contGanadas25=0;
    float porce25;
    int compMax;
    int iCompMax;
    bool bandPrimIng=true;


    for (int i=1; i<=3; i++) {
        cout<<"----------------------Competencia "<<i<<"----------------------"<<endl;

        cout<<"Ingrese el número de país(0 para finalizar la carga de datos de la competencia): "<<endl;
        cin>>nroPais;

        while (nroPais!=0) {
            cout<<"Género de la competencia: "<<endl;
            cin>>genero;
            cout<<"Cantidad de atletas participantes del país: "<<endl;
            cin>>cantAtle;
            cout<<"Mejor puesto obtenido: "<<endl;
            cin>>mejorPuesto;

            acuAtletasTot+=cantAtle;
            acuAtletas+=cantAtle;

            if (nroPais==25) {
                contComp25++;
                if (mejorPuesto==1) {
                    contGanadas25++;
                }
            }

            cout<<"Ingrese el número de país(0 para finalizar la carga de datos de la competencia): "<<endl;
            cin>>nroPais;
        }

        if (acuAtletas>compMax || bandPrimIng==true) {
            bandPrimIng=false;
            compMax=acuAtletas;
            iCompMax=i;
        }

        acuAtletas=0;
    }

    porce25=((float)contGanadas25/(float)contComp25)*100;

    //---------A---------
    cout<<"Cantidad total de atletas participantes entre todas las competencias: "<<acuAtletasTot<<endl;
    //---------B---------
    cout<<"Número de competencia con mayor cantidad de atletas: "<<iCompMax<<endl;
    //---------C---------
    cout<<"El porcentaje de competencias ganadas en las que participó en país 25 es: "<<porce25<<endl;

    system("pause");
    return 0;
}