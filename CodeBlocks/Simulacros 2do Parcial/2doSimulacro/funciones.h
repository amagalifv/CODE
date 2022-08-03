#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

# include<iostream>
# include<cstdlib>
# include<cstring>
# include<ctime>
using namespace std;

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

class Empresa{
    private:
    int _codigoEmp;
    int _tipoEmp;/*(1: local.; 2: interurbano; 3: nacional; 4: internacional)*/
    char _nombre[20];
    char _direccion[20];

    public:
    void Mostrar();
    void Cargar();
    bool leerDeDisco(int);
    bool grabarEnDisco();

    //GETTERS
    int getCodigoEmp (){return _codigoEmp;}
    int getTipoEmp(){return _tipoEmp;}
    const char *getNombre(){return _nombre;}
    const char *getDireccion(){return _direccion;}
    //SETTERS
    void setCodigoEmp(int c){_codigoEmp=c;}
    void setTipoEmp(int t){_tipoEmp=t;}
    void setNombre(const char *n){strcpy(_nombre,n);}
    void setDireccion(const char *d){strcpy(_direccion,d);}
};

class Pasaje{
    private:
        int _nroPasaje;
        int _codigoEmp;
        int _cuitCliente;
        float _importe;
        Fecha _fecha;
        char _formaPago; //(‘C’: contado; ‘D’: débito; ‘T’: crédito, ‘H’: cheque)
    public:
    void Mostrar();
    void Cargar();
    bool leerDeDisco(int);
    bool grabarEnDisco();

    //GETTERS
    int getNroPasaje(){return _nroPasaje;}
    int getCodigoEmp(){return _codigoEmp;}
    int getCuitCliente(){return _cuitCliente;}
    float getImporte(){return _importe;}
    Fecha getFecha(){return _fecha;}
    char getFormaPago(){return _formaPago;}
    //SETTERS
    void setCodigoEmp(int co){_codigoEmp=co;}
    void setNroPasaje(int pas){_nroPasaje=pas;}
    void setCuitCliente(int cu){_cuitCliente=cu;}
    void setImporte(float i){_importe=i;}
    void setFecha(Fecha f){_fecha=f;}
    void setFormaPago(char p){_formaPago=p;}
};

#endif // FUNCIONES_H_INCLUDED
