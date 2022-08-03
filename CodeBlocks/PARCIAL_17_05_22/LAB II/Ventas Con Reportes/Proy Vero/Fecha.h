#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "FechaGlobales.h"

using namespace std;

class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;

public:
    ///CONSTRUCTOR CON VALORES POR OMISIÓN
    Fecha(int pDia=0, int pMes=0, int pAnio=0){
        _dia=pDia;
        _mes=pMes;
        _anio=pAnio;
    }

    ///SETTERS
    void setDia(int pDia){
        if(validarNumero(pDia, "Dia")){
            _dia=pDia;
        }
    }

    void setMes(int pMes){
        if(validarNumero(pMes, "Mes")){
           _mes=pMes;
        }
    }

    void setAnio(int pAnio){
        if(validarNumero(pAnio, "Anio")){
           _anio=pAnio;
        }
    }

    ///GETTERS
    int getDia(){return _dia;}
    int getMes(){return _mes;}
    int getAnio(){return _anio;}

    ///METODOS
    void Mostrar();
    void Cargar();
    void CargarNacimiento();
    int ConsolidarFecha(){return ((_anio*10000)+(_mes*100)+(_dia));}

};
///METODOS DE LA CLASE FECHA
void Fecha::Cargar(){
    int dia;
    int mes;
    int anio;

    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;

    while(!validarFechaVenta(dia, mes, anio)){
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
    }

    setDia(dia);
    setMes(mes);
    setAnio(anio);
}
void Fecha::CargarNacimiento(){
    int dia;
    int mes;
    int anio;

    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;

    while(!validarFechaNacimiento(dia, mes, anio)){
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
    }

    setDia(dia);
    setMes(mes);
    setAnio(anio);
}
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
///FIN METODOS DE LA CLASE FECHA


#endif // FECHA_H_INCLUDED
