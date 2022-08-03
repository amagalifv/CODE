#include <iostream>
#include <cstdlib>
using namespace std;

/*
32- Se ingresan los datos de los 10 artículos que vende una empresa. Cada registro
contiene:
- Número de artículo (1 a 10)
- Precio Unitario
- Clase de artículo (1, 2 o 3)
Se pide determinar e informar:
a- El número del artículo más caro para cada una de las 3 clases. Se listan 3 resultados, uno
para cada una de las 3 clases.
b- La clase de artículo con el mayor precio promedio.
*/

int main () {
    int numArt;
    float precio;
    int claseArt;
    float masCaro1=-1;
    float masCaro2=-1;
    float masCaro3=-1;
    int contCant1=0;
    int contCant2=0;
    int contCant3=0;
    float acu1=0;
    float acu2=0;
    float acu3=0;
    float promC1;
    float promC2;
    float promC3;

    for (int i=0; i<10; i++) {
        cout<<"Numero de articulo: "<<endl;
        cin>>numArt;
        cout<<"Precio unitario: "<<endl;
        cin>>precio;
        cout<<"Clase de articulo: "<<endl;
        cin>>claseArt;

        switch (claseArt){
            case 1:
                if (precio>masCaro1) {
                    masCaro1=precio;
                }
                contCant1++;
                acu1+=precio;
                break;
            case 2:
                if (precio>masCaro2) {
                    masCaro2=precio;
                }
                contCant2++;
                acu2+=precio;
                break;
            case 3:
                if (precio>masCaro3) {
                    masCaro3=precio;
                }
                contCant3++;
                acu3+=precio;
                break;

            default:
                break;
        }
    }

    promC1=acu1/(float)contCant1;
    promC2=acu2/(float)contCant2;
    promC3=acu3/(float)contCant3;

    cout<<"Precio mas caro clase 1: "<<masCaro1<<endl;
    cout<<"Precio promedio: "<<promC1<<endl;
    cout<<endl;
    cout<<"Precio mas caro clase 2: "<<masCaro2<<endl;
    cout<<"Precio promedio: "<<promC2<<endl;
    cout<<endl;
    cout<<"Precio mas caro clase 3: "<<masCaro3<<endl;
    cout<<"Precio promedio: "<<promC3<<endl;

    system("pause");
    return 0;
}