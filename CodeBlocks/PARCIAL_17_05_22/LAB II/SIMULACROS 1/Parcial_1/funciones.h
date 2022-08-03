#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "Clases.h"
const char *AR_CLUB = "clubes.dat";
const char *AR_SOCIO = "socios.dat";
const char *AR_INSCRIP = "inscriptos.dat";
const char *AR_REGISTRO = "registros.dat";

class Registro{
    private:
        int _dni;
        char _nombre[30];
        char _apellido[30];
    public:
        Registro(int dni=0, const char *nom="AAAA", const char *ape="AAAA", const char *email="aa@aa.aa",const char *tel="0"){//FALTA FECHA
            _dni=dni;
            strcpy(_apellido, ape);
            strcpy(_nombre, nom);
        }
        //GETS
        int getDni(){return _dni;}
        const char *getApellido(){return _apellido;}
        const char *getNombre(){return _nombre;}
        // SETS
        void setDni(int dni){_dni=dni;}
        void setApellido(const char nom[30]){strcpy(_apellido, nom);}
        void setNombre(const char nom[30]){strcpy(_nombre, nom);}

        void Cargar();
        void Mostrar();
        bool leerDeDisco(int);
        bool grabarEnDisco();
};

int buscarDniEnSocios(int dni){
    FILE *pSoc;
    Socio soc;
    int devol=1;
    int i=0;

    pSoc=fopen(AR_SOCIO,"rb");
    if (pSoc==NULL){return -2;}

    while (devol==1) {
        devol=fread(&soc ,sizeof(Socio),1,pSoc);

        if (soc.getDni()==dni && soc.getEstado()==true) {
            return i;
            fclose(pSoc);
        }
        i++;
    }
    fclose(pSoc);
    return -1;
}

int buscarDniEnInscrip(int dni){
    FILE *pIns;
    Inscripcion insc;
    int devol=1;
    int i=0;

    pIns=fopen(AR_INSCRIP,"rb");
    if (pIns==NULL){return -2;}

    while (devol==1) {
        devol=fread(&insc ,sizeof(Club),1,pIns);

        if (insc.getDni()==dni && insc.getEstado()==true) {
            return i;
            fclose(pIns);
        }
        i++;
    }
    fclose(pIns);
    return -1;
}



void punto1(){
    int pos=0;
    Inscripcion insc;
    Socio soc;
    int aux, posS;
    Registro regi;

    while (insc.leerDeDisco(pos)==1){
        if (insc.getFechaInsc().fConsolidada()>20209999 && insc.getFechaInsc().fConsolidada()<20199999) {
            aux=insc.getDni();
            posS=buscarDniEnSocios(aux);
            if (posS>=0) {
                soc.leerDeDisco(posS);
                if (soc.getTipoSoc()==3) {
                    regi.setNombre(soc.getNombre());
                    regi.setDni(soc.getDni());
                    regi.setApellido(soc.getApellido());
                    regi.grabarEnDisco();
                }
            }
        }
        pos++;
    }
}
/*
Listar los socios que tengan una inscripción de tipo temporal del año pasado.
*/
void punto2(){
  int pos=0;
    Inscripcion insc;
    Socio soc;
    int aux, posS;
    Registro regi;

    while (soc.leerDeDisco(pos)==1){
        if (soc.getTipoSoc()==1) {
            aux=soc.getDni();
            posS=buscarDniEnInscrip(aux);
            if (posS>=0) {
                insc.leerDeDisco(posS);
                if (insc.getFechaInsc().fConsolidada()<20219999 && insc.getFechaInsc().fConsolidada()>20199999) {
                    soc.Mostrar();
                }
            }
        }
        pos++;
    }
}

#endif // FUNCIONES_H_INCLUDED
