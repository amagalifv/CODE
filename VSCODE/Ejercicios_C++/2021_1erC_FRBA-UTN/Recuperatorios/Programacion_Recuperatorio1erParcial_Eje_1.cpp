#include <iostream>
#include<math.h>
using namespace std;

void calcularTipoTriangulo(float a,float b,float c, string &mensaje){
    
    if (a==b && b==c){
        mensaje="equilatero";
    }

    if (a==b && b!=c || b==c && c!=a || a==c && a!=b){
        mensaje="isoceles";
    }

    if (a!=b && a!=c && b!=c){
         mensaje="escaleno";
    }
    
    return;
}

void cargarDatoFloat (string mensaje, float &dato) {
    
    cout<<mensaje<<endl;
    cin>>dato;

    return;
}

float calcularPerimetro(float a,float b,float c){
    float perimet=0;

    perimet=a+b+c;

    return perimet;
}

float calcularArea(float a,float b,float c, float perimetro){
    float area=0;
    float s=0;
    s=perimetro/2;

    area=sqrt(s*(s-a)*(s-b)*(s-c));

    return area;
}

void imprimirFloat (float dato, string mensaje) {

    cout<<mensaje<<dato<<endl;

    return;
}

void imprimirString (string dato, string mensaje) {

    cout<<mensaje<<dato<<endl;

    return;
}

int main () {
    float a;
    float b;
    float c;
    string ingreso;
    string tipoTriang;
    float perimetro=0;
    float perimetroMax=0;
    int iPerMax=0;
    int i=1;
    float area;

    cout<<"Ingrese cualquier letra para evaluar triangulos o FIN para terminar"<<endl;
    cin>>ingreso;

    while ( ingreso != "Fin") {

        cargarDatoFloat("1er lado:", a);

        cargarDatoFloat("2do lado:", b);

        cargarDatoFloat("3er lado:", c);

        calcularTipoTriangulo(a,b,c,tipoTriang);
        imprimirString(tipoTriang,"El tipo de triangulo es: ");

        perimetro=calcularPerimetro(a,b,c);
        imprimirFloat(perimetro, "El perimetro es: ");

        if (perimetro>perimetroMax){
            perimetroMax=perimetro;
            iPerMax=i;
        }

        area=calcularArea(a,b,c,perimetro);
        imprimirFloat(area, "El area es: ");

        i++;
        cout<<"Ingrese cualquier letra para evaluar triangulos o FIN para terminar"<<endl;
        cin>>ingreso;
    }

    imprimirFloat(perimetroMax, "El perimetro maximo es: ");
    imprimirFloat(iPerMax, "La posicion en que fue ingresado es: ");
 
    system("pause");
    return 0;
}