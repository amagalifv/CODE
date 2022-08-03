#ifndef CLSYFUNCIONES_H_INCLUDED
#define CLSYFUNCIONES_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstring>
# include<ctime>
using namespace std;

/*
Una aplicación de venta de música registra las compras de los usuarios en un archivo con el siguiente formato:

Número de compra (int), el DNI y el nombre del usuario, la fecha, el género musical (1 a 50) y el código de la canción (char[5]).

A partir de los señalado desarrollar los siguientes puntos.

    1) Crear la clase correspondiente con sets() y gets() para todas las propiedades.
    2) Agregar una sobrecarga de un operador que compare la propiedad número de compra con un valor que recibe como parámetro
    3) Hacer una función externa (o las que se consideren necesarias) que reciba una fecha y muestre todas las ventas registradas en el archivo ese día.
    4) Hacer una función externa (o las que se consideren necesarias) que muestre la cantidad de ventas registradas por género musical.
    5)Generar un vector dinámico para cargar los 10 primeros registros del archivo del punto anterior.
    Mostrar el vector.
*/

bool validarFecha(int d, int m, int a);

class Fecha {
    private:
        int _dia, _mes, _anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            _dia=dia;
            _mes=mes;
            _anio=anio;
        }
        void Mostrar();
        void Cargar();
        ///gets()
        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}
        ///sets()
        void setDia(int d){if(d>=1 && d<=31){ _dia=d;}else{_dia=0;_mes=0;_anio=0;}}
        void setMes(int m){if(m>=1 && m<=12){ _mes=m;}else{_dia=0;_mes=0;_anio=0;}}
        void setAnio(int a){if(a>=1920 && a<=2022){_anio=a;}else{_dia=0;_mes=0;_anio=0;}}
        bool operator== (Fecha f){
            if (f.getDia()==_dia && f.getMes()==_mes && f.getAnio()==_anio){return true;}
            return false;
        }
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
    int dia, mes, anio;

    cout<<"INGRESE EL DIA:             ";
    cin>>dia;

    cout<<"INGRESE EL MES:             ";
    cin>>mes;

    cout<<"INGRESE EL AÑO (4 digitos): ";
    cin>>anio;

    if (validarFecha(dia, mes, anio)){setDia(dia);setMes(mes);setAnio(anio);}

}

bool validarFecha(int d, int m, int a){
    bool bandera=true;
    int v[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int anioActual;

    //chequear dia segun mes
    if(d>=v[m-1]){
        if (d==29 && m==2 && a%4==0) {
            //chequear febrero y año bisiesto
            if (a%100==0 && a%400!=0){bandera=false;}
            else{ bandera=true;}
        }else{bandera=false;}
    }

    //chequear mes
    if (m<1 || m>12){bandera=false;}

    //chequear año
    time_t fechaActual;
    time(&fechaActual);
    struct tm *pST_tiempo = localtime(&fechaActual);
    anioActual=pST_tiempo->tm_year+1900;
    if (a<1900 || a>anioActual) {bandera=false;}

    return bandera;
}


#endif // CLSYFUNCIONES_H_INCLUDED
