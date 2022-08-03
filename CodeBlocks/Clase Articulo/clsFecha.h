#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

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
        ///gets()
        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}
        ///sets()
        void setDia(int d){_dia=d;}
        void setMes(int m){if(m>=1 && m<=12) _mes=m;}
        void setAnio(int a){_anio=a;}
        ~Fecha(){};
};

void Fecha::Mostrar(){
    cout<<" "<<getDia<<"/"<<getMes<<"/"<<getAnio;
}

#endif // CLSFECHA_H_INCLUDED
