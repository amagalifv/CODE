#ifndef FECHAGLOBALES_H_INCLUDED
#define FECHAGLOBALES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
///PROTOTIPO DE FUNCIONES GOBALES
bool validarNumero(int nro, const char *texto);
bool validarFechaNacimiento(int pDia, int pMes, int pAnio);
bool validarFechaVenta(int pDia, int pMes, int pAnio);
///FIN PROTOTIPOS DE FUNCIONES GLOBALES

///FUNCIONES GLOBALES
bool validarFechaNacimiento(int pDia, int pMes, int pAnio){
    if(pAnio<1920 || pAnio>2010){
        cout<<"Anio invalido."<<endl;
        return false;
    }

    if(pMes<=0 || pMes>12){
        cout<<"Mes invalido"<<endl;
        return false;
    }
    else{
        if(pMes==2){
            if(pDia<=0 || pDia>28){
                cout<<"Dia invalido."<<endl;
                return false;
            }
        }
        else{
            if(pMes==4 || pMes==6 || pMes==9 || pMes==11){
                if(pDia<=0 || pDia>30){
                    while(pDia<=0){
                        cout<<"Dia invalido."<<endl;
                        return false;
                    }
                }
            }
            else{
                if(pDia<=0 || pDia>31){
                    while(pDia<=0 || pDia>31){
                        cout<<"Dia invalido."<<endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
bool validarFechaVenta(int pDia, int pMes, int pAnio){
    if(pAnio<1920){
        cout<<"Anio invalido."<<endl;
        return false;
    }

    if(pMes<=0 || pMes>12){
        cout<<"Mes invalido"<<endl;
        return false;
    }
    else{
        if(pMes==2){
            if(pDia<=0 || pDia>28){
                cout<<"Dia invalido."<<endl;
                return false;
            }
        }
        else{
            if(pMes==4 || pMes==6 || pMes==9 || pMes==11){
                if(pDia<=0 || pDia>30){
                    while(pDia<=0){
                        cout<<"Dia invalido."<<endl;
                        return false;
                    }
                }
            }
            else{
                if(pDia<=0 || pDia>31){
                    while(pDia<=0 || pDia>31){
                        cout<<"Dia invalido."<<endl;
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
bool validarNumero(int nro, const char *texto){
    if(nro<=0){
        while(nro<=0){
            cout<<texto<<" invalido, ingreselo nuevamente: ";
            cin>>nro;
        }
    }
    return true;
}
///FIN FUNCIONES GLOBALES

#endif // FECHAGLOBALES_H_INCLUDED
