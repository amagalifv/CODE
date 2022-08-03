#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

class Fecha{
    private:///s�lo era accesible desde dentro de la clase
        int dia, mes, anio;///propiedades o variables de la clase
    public:///accesible dentro y fuera de la clase
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Mostrar();
        void Cargar();
        int consolidarFecha();
        ///gets()
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        ///sets()
        void setDia(int d){dia=d;}
        void setMes(int m){if(m>=1 && m<=12) mes=m;}
        void setAnio(int a){anio=a;}
        ~Fecha(){};
};

void Fecha::Mostrar(){
    ///cout<<this<<endl;
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<endl;
}

void Fecha::Cargar(){
    int d;
    cout<<"DIA: ";
    cin>>d;
    setDia(d);
    cout<<"MES: ";
    cin>>d;
    setMes(d);
    cout<<"ANIO: ";
    cin>>d;
    setAnio(d);
}

int Fecha::consolidarFecha(){
    return anio*10000+mes*100+dia;
}


#endif // FECHA_H_INCLUDED
