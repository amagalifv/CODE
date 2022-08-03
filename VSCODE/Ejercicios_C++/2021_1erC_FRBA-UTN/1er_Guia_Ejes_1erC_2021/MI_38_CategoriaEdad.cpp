#include <iostream>
using namespace std;

int pedirValor (string mensaje);
int calcularCatEdad(int num);

int main () {
 int edad=0;
 int grupoEtario=0;

 edad= pedirValor ("Ingrese una edad");
 grupoEtario= calcularCatEdad(edad);

 cout << "La categoria segun la edad es "<< grupoEtario <<endl;

 system("pause");
 return 0;
}

int pedirValor (string mensaje){
    int num;
    cout<<mensaje<<endl;
    cin>>num;

    return num;
}

int calcularCatEdad(int num){
    int grupoSegunEdad;

    if (num<=14){
        grupoSegunEdad=1;
    }else{
        if (num<=21){
           grupoSegunEdad=2;
        }else{
            if (num<=28){
                grupoSegunEdad=3;
            }else{
                if (num<=35){
                    grupoSegunEdad=4;
                }else{
                    if (num<=42){
                        grupoSegunEdad=5;
                    }else{
                        if (num<=49){
                            grupoSegunEdad=6;
                        }else{
                            if (num<=63){
                                grupoSegunEdad=7;
                            }else{
                               grupoSegunEdad=8;
                            }
                        }
                    }
                }
            }
        }
    }


    return grupoSegunEdad;
}
