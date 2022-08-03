# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

#include "clsCadena.h"

int main(){
    /*Cadena objCad("Hola a todos!");
    objCad.Mostrar();
    cout<<objCad.getDimension()<<endl;

    objCad.setpCad("Adios!");
    objCad.Mostrar();
    cout<<objCad.getDimension()<<endl;
    cout<<endl;

    Cadena aux("nada");
    if (aux==objCad) {
        cout<<"SON IGUALES"<<endl;
    }else{cout<<"NO SON IGUALES"<<endl;}

    if(objCad=="Adios!"){
        cout<<"objCad ES IGUAL A -Adios!-"<<endl;
    }else{cout<<"objCad NO ES IGUAL A -Adios!-"<<endl;}
    */
    Cadena objCad("Hola a todos!");
    objCad.ConvertirMayuscula();
    objCad.Mostrar();

    system("pause");
    return 0;
}
