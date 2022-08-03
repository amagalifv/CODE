# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

#include "funciones.h"

const char *AR_PROMRECAUDACION="promrecaudacion.dat";

class PromRecaudacion {
    private:
        int _codigo;
        char _nombre[30];
        float _promRecaudacion;
    public:
    void Mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();

    //GETTERS
    int getCodigo(){return _codigo;}
    const char *getNombre(){return _nombre;}
    float getPromeRecaudacion(){return _promRecaudacion;}
    //SETTERS
    void setCodigo(int c){_codigo=c;}
    void setNombre(const char *n){strcpy(_nombre,n);}
    void setPromeRecaudacion(float p){_promRecaudacion=p;}
};

void PromRecaudacion::Mostrar(){
    cout<<"CODIGO CUIDAD           :";
    cout<<getCodigo()<<endl;
    cout<<"NOMBRE                  :";
    cout<<getNombre()<<endl;
    cout<<"PROMEDIO DE RECAUDACION :";
    cout<<getPromeRecaudacion()<<endl;
}
bool PromRecaudacion::leerDeDisco(int pos){
    FILE *pProm;
    int leyo;

    pProm=fopen(AR_PROMRECAUDACION,"rb");
    if (pProm==NULL){return false;}

    fseek(pProm, sizeof(PromRecaudacion)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(PromRecaudacion),1,pProm);
    fclose(pProm);

    if (leyo==1) {return true;}
    else{return false;}
}

bool PromRecaudacion::grabarEnDisco(){
    FILE *pProm;
    bool escribio;

    pProm=fopen(AR_PROMRECAUDACION,"ab");
    if (pProm==NULL){return false;}

    escribio=fwrite(this ,sizeof(PromRecaudacion),1,pProm);
    fclose(pProm);

    if (escribio==1) {return true;}
    else{return false;}
}

int BucarCodEmpMasGrande (){
    Empresa obj;
    int i=0;
    int maxCod=0; //SUPONGO QUE COD EMP VA DE 1 A ???

    while (obj.leerDeDisco(i)) {
        if (obj.getCodigoEmp()>maxCod) {
            maxCod=obj.getCodigoEmp();
        }

        i++;
    }
    return maxCod;
}

void ponerEnCero(int *v, int &tam){
    for (int i=0; i<tam; i++){
        v[i]=0;
    }
}

bool generarArchivo(){
    int tam;
    int *vCant;
    int *vAcu;
    Empresa emp;
    Pasaje pas;
    PromRecaudacion prome;
    int i=0;

    tam=BucarCodEmpMasGrande();

    vCant=new int[tam];
    if (vCant==NULL){return false;}
    vAcu=new int[tam];
    if (vAcu==NULL){return false;}

    ponerEnCero(vCant, tam);
    ponerEnCero(vAcu, tam);


    while (pas.leerDeDisco(i)){
        vCant[pas.getCodigoEmp()-1]++;
        vAcu[pas.getCodigoEmp()-1]+=pas.getImporte();

        i++;
    }

    // GENERO ARCHIVO
    for (int j=0; j<tam; j++) {
        i=0;
        prome.setPromeRecaudacion(vAcu[j]/vCant[j]);
        prome.setCodigo(j+1);

        while (emp.leerDeDisco(i)) {
            if (i==emp.getCodigoEmp()-1) {
                prome.setNombre(emp.getNombre());
                break;
            }
        }
        prome.grabarEnDisco();
    }


    delete vCant;
    delete vAcu;

    return true;
}

int mesMax(int *v){
    Pasaje medi;
    int i=0;
    int mesMax;

    while (medi.leerDeDisco(i)) {
        v[medi.getFecha().getMes()-1]++;

        i++;
    }

    mesMax=v[0];
    for (int i=1; i<12; i++) {
        if (v[i]>mesMax) {
            mesMax=v[i];
        }
    }
    return mesMax+1;
}
void imprimirMesMax(int *v, int &mesMax){

    for (int i=0; i<12; i++) {
        if (mesMax==v[i]) {
            cout<<", "<<v[i]+1;
        }
    }
}

int main(){
    int v[12]={0};
    int max;
    //Punto A: Generar un archivo con el siguiente formato: Código de empresa, nombre, y promedio de recaudación entre todos los viajes.



    //Punto B: El mes con mayor cantidad de pasajes vendidos.
    max=mesMax(v);
    cout<<"El mes/es que tuvo más ventas es: "<<max;
    imprimirMesMax(v, max);

    system("pause");
    return 0;
}
