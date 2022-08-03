#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H
#include <iostream>
using namespace std;

class Temporizador {
    public:
        Temporizador();// constructor
        Temporizador(int hs, int min, int seg);
        void mostrar();
        void setTipo(int tipo);
        void tic();
        int comparar(Temporizador otro);
    private:
        int _horas;
        int _min;
        int _seg;
        bool _tipo;
};

Temporizador::Temporizador(){
    _horas=0;
    _min=0;
    _seg=0;
}

Temporizador::Temporizador(int hs, int minu,int segu){
    _horas=0;
    _min=0;
    _seg=0;

    if(0<=hs && 0<=minu && minu<60 && 0<=segu && segu<60) {
        _horas=hs;
        _min=minu;
        _seg=segu;
    } else {
        _horas=0;
        _min=0;
        _seg=0;
        cout<<"Los valores ingresados no fueron correctos, el temporizador se reinicio"<<endl;
    }
}

void Temporizador::mostrar(){

    if (_horas<10) {
        cout<<"0";
    }
    cout<<_horas<<":";

    if (_min<10) {
        cout<<"0";
    }
    cout<<_min<<":";


    if (_seg<10) {
        cout<<"0";
    }
    cout<<_seg<<endl;

}

void Temporizador::setTipo(int tipo){
    switch (tipo){
        case 1:
             _tipo=true;
            break;
        case 2:
             _tipo=false;
            break;
        default:
             _tipo=true;
            break;
    }
}

void Temporizador::tic(){
    if (_tipo){
        //temporizador que aumenta
        if (_seg>=59) {
            if (_min>=59) {
                _horas++;
                _min=0;
                _seg=0;
            } else {
                _min++;
                _seg=0;
            }
        } else {
            _seg++;
        }
    } else {
        //temporizador que disminuye
        if (_seg==0) {
            if (_min==0) {
                if (_horas==0) {
                    cout<<"El contador está en 0 no podemos decrementarlo"<<endl;
                }else{
                    _horas--;
                    _min=59;
                    _seg=59;
                }
            } else {
                _min--;
                _seg=59;
            }
        } else {
            _seg--;
        }
    }

}

int Temporizador::comparar(Temporizador otro){
    int unoT, otroT;

    unoT=_horas*10000+_min*100+_seg;
    otroT=otro._horas*10000+otro._min*100+otro._seg;

    if (unoT==otroT){
        return 0;
    } else if (unoT>otroT) {
        return 1;
    } else {
        return -1;
    }
}

#endif