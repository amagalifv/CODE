#ifndef CLS_Y_FUNCS_H_INCLUDED
#define CLS_Y_FUNCS_H_INCLUDED
# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}


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
        void setAnio(int a){if(a>=1920){_anio=a;}else{_dia=0;_mes=0;_anio=0;}}
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

    setDia(dia);setMes(mes);setAnio(anio);
}




#endif // CLS_Y_FUNCS_H_INCLUDED
