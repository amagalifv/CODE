#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
#include <iostream>
#include <cstdlib>
using namespace std;


class Fecha{
    private:
        int _dia, _mes, _anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            this->_dia=dia;
            this->_mes=mes;
            this->_anio=anio;
        }
        void Mostrar();
        void Cargar();
        int fConsolidada(){return ((_anio*10000)+(_mes*100)+(_dia));}
        ///gets()
        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}
        ///sets()
        void setDia(int d){if(d>=1 && d<=31) _dia=d;}
        void setMes(int m){if(m>=1 && m<=12) _mes=m;}
        void setAnio(int a){if(a>=1920 && a<=2010)_anio=a;}
};

void Fecha::Mostrar(){
    if (getDia()<10){
        cout<<"0"<<getDia();
    }else{
        cout<<getDia();
    }
    cout<<"/";
    if (getMes()<10){
        cout<<"0"<<getMes();
    }else{
        cout<<getMes();
    }
    cout<<"/"<<getAnio()<<endl;
}

void Fecha::Cargar(){
    int aux;

    cout<<"INGRESE EL DIA:             ";
    cin>>aux;
    setDia(aux);

    cout<<"INGRESE EL MES:             ";
    cin>>aux;
    setMes(aux);

    cout<<"INGRESE EL AÑO (4 digitos): ";
    cin>>aux;
    setAnio(aux);
}

#endif // CLSFECHA_H_INCLUDED
