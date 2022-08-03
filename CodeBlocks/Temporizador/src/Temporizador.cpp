#include <iostream>
using namespace std;
#include "Temporizador.h"

Temporizador::Temporizador(){
    _horas=0;
    _min=0;
    _seg=0;
}

Temporizador::Temporizador(int hs, int minu,int segu){

    if( 0<=hs && hs<2 && 0<=minu && minu<60 && 0<=segu && segu<60 ) {
        _horas=hs;
        _min=minu;
        _seg=segu;
    } else {
        _horas=0;
        _min=0;
        _seg=0;
    }
}

void Temporizador::mostrar(){
    if (_horas<10) {
        cout<<"0"<<_horas;
    }else{
        cout<<_horas;
    }

    if (_min<10) {
        cout<<":0"<<_min;
    }else{
        cout<<":"<<_min;
    }

    if (_seg<10) {
        cout<<":0"<<_seg<<endl;
    }else{
        cout<<":"<<_seg<<endl;
    }
}

void Temporizador::setTipo(int tipo){
    switch (tipo){
        case 1:
             _tipo=true;
            break;
        case 2:
             _tipo=false;
            break;
    }
}

int Temporizador::consolidarHora(Temporizador a){

    return a._horas*10000+a._min*100+a._seg;
}

void Temporizador::tic(){
    if (_tipo){

    } else {

    }

}

int Temporizador::comparar(Temporizador uno, Temporizador otro){
    int unoT, otroT;
    unoT=consolidarHora(uno);
    otroT=consolidarHora(otro);

    if (unoT==otroT){
        return 0;
    } else if (unoT>otroT) {
        return 1;
    } else {
        return -1;
    }
}



