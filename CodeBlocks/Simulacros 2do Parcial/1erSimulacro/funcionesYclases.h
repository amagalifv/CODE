#ifndef FUNCIONESYCLASES_H_INCLUDED
#define FUNCIONESYCLASES_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstring>
# include<ctime>
using namespace std;

const char *AR_CIUDADES="ciudades.dat";
const char *AR_MEDICIONES="ciudades.dat";

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


//*************************************************
class Ciudad {
    private:
        int _codigoC;
        char _nombre[30];
        int _codigoProv;
    public:
    void Mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();

    //GETTERS
    int getCodigo(){return _codigoC;}
    const char *getNombre(){return _nombre;}
    int getCodigoProvincia(){return _codigoProv;}
    //SETTERS
    void setCodigo(int c){_codigoC=c;}
    void setNombre(const char *n){strcpy(_nombre,n);}
    void setCodigoProvincia(int p){_codigoProv=p;}
};

void Ciudad::Mostrar(){
    cout<<"CODIGO CUIDAD           :";
    cout<<getCodigo()<<endl;
    cout<<"NOMBRE                  :";
    cout<<getNombre()<<endl;
    cout<<"CODIGO PROVINCIA        :";
    cout<<getCodigoProvincia()<<endl;
}
bool Ciudad::leerDeDisco(int pos){
    FILE *pCli;
    int leyo;

    pCli=fopen(AR_CIUDADES,"rb");
    if (pCli==NULL){return false;}

    fseek(pCli, sizeof(Ciudad)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Ciudad),1,pCli);
    fclose(pCli);

    if (leyo==1) {return true;}
    else{return false;}
}

bool Ciudad::grabarEnDisco(){
    FILE *pProm;
    bool escribio;

    pProm=fopen(AR_CIUDADES,"ab");
    if (pProm==NULL){return false;}

    escribio=fwrite(this ,sizeof(Ciudad),1,pProm);
    fclose(pProm);

    if (escribio==1) {return true;}
    else{return false;}
}
//***************************************************
class Medicion {
    private:
        int _codigoC;
        int _visibilidad;
        float _temperatura;
        Fecha _fecha;
    public:
    void Mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();

    //GETTERS
    int getCodigo(){return _codigoC;}
    int getVisibilidad(){return _visibilidad;}
    float getTemperatura(){return _temperatura;}
    Fecha getFecha(){return _fecha;}
    //SETTERS
    void setCodigo(int c){_codigoC=c;}
    void setVisibilidad(int v){_visibilidad=v;}
    void setTemperatura(float p){_temperatura=p;}
    void setTemperatura(Fecha f){_fecha=f;}
};

void Medicion::Mostrar(){
    cout<<"CODIGO CUIDAD           :";
    cout<<getCodigo()<<endl;
    cout<<"VISIBILIDAD             :";
    cout<<getVisibilidad()<<endl;
    cout<<"TEMPERATURA             :";
    cout<<getVisibilidad()<<endl;
    _fecha.Mostrar();
}

bool Medicion::leerDeDisco(int pos){
    FILE *pMedi;
    int leyo;

    pMedi=fopen(AR_MEDICIONES,"rb");
    if (pMedi==NULL){return false;}

    fseek(pMedi, sizeof(Medicion)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(Medicion),1,pMedi);
    fclose(pMedi);

    if (leyo==1) {return true;}
    else{return false;}
}

bool Medicion::grabarEnDisco(){
    FILE *pMedi;
    bool escribio;

    pMedi=fopen(AR_MEDICIONES,"ab");
    if (pMedi==NULL){return false;}

    escribio=fwrite(this ,sizeof(Medicion),1,pMedi);
    fclose(pMedi);

    if (escribio==1) {return true;}
    else{return false;}
}

//***************************************************************


#endif // FUNCIONESYCLASES_H_INCLUDED
