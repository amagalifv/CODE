# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

#include "funcionesYclases.h"

// *********************** PRIMERA ***********************
const char *AR_PROMCIUDADES="prociudades.dat";
class PromCiudades {
    private:
        int _codigo;
        char _nombre[30];
        float _promVisibilidad;
    public:
    void Mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();

    //GETTERS
    int getCodigo(){return _codigo;}
    const char *getNombre(){return _nombre;}
    float getPromeVisibilidad(){return _promVisibilidad;}
    //SETTERS
    void setCodigo(int c){_codigo=c;}
    void setNombre(const char *n){strcpy(_nombre,n);}
    void setPromeVisibilidad(float p){_promVisibilidad=p;}
};

void PromCiudades::Mostrar(){
    cout<<"CODIGO CUIDAD           :";
    cout<<getCodigo()<<endl;
    cout<<"NOMBRE                  :";
    cout<<getNombre()<<endl;
    cout<<"PROMEDIO DE VISIBILIDAD :";
    cout<<getPromeVisibilidad()<<endl;
}
bool PromCiudades::leerDeDisco(int pos){
    FILE *pCli;
    int leyo;

    pCli=fopen(AR_PROMCIUDADES,"rb");
    if (pCli==NULL){return false;}

    fseek(pCli, sizeof(PromCiudades)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(PromCiudades),1,pCli);
    fclose(pCli);

    if (leyo==1) {return true;}
    else{return false;}
}

bool PromCiudades::grabarEnDisco(){
    FILE *pProm;
    bool escribio;

    pProm=fopen(AR_PROMCIUDADES,"ab");
    if (pProm==NULL){return false;}

    escribio=fwrite(this ,sizeof(PromCiudades),1,pProm);
    fclose(pProm);

    if (escribio==1) {return true;}
    else{return false;}
}

int contarCiudades (){
    Ciudad obj;
    int i=0;

    while (obj.leerDeDisco(i)) {
        i++;
    }
    return i;
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
    Ciudad ciu;
    Medicion medi;
    PromCiudades prome;
    int i=0;

    tam=contarCiudades();

    vCant=new int[tam];
    if (vCant==NULL){return false;}
    vAcu=new int[tam];
    if (vAcu==NULL){return false;}

    ponerEnCero(vCant, tam);
    ponerEnCero(vAcu, tam);


    while (medi.leerDeDisco(i)){
        vCant[medi.getCodigo()-1]++;
        vAcu[medi.getCodigo()-1]+=medi.getVisibilidad();

        i++;
    }

    // GENERO ARCHIVO
    for (int j=0; j<tam; j++) {
        i=0;
        prome.setPromeVisibilidad(vAcu[j]/vCant[j]);
        prome.setCodigo(j);

        while (ciu.leerDeDisco(i)) {
            if (i==ciu.getCodigo()-1) {
                prome.setNombre(ciu.getNombre());
                break;
            }
        }
        prome.grabarEnDisco();
    }


    delete vCant;
    delete vAcu;

    return true;
}

void listarMesMayo(){
    int mtrz[6][31]={0};
    Medicion medi;
    int i=0;

    while (medi.leerDeDisco(i)) {

        if (medi.getFecha().getMes()==5 && medi.getFecha().getAnio()==2022) {

            if (0<=medi.getVisibilidad()&&medi.getVisibilidad()<=50) {
            mtrz[0][medi.getFecha().getDia()-1]++;
            }
            if (50<medi.getVisibilidad()&&medi.getVisibilidad()<=500) {
                mtrz[1][medi.getFecha().getDia()-1]++;
            }
            if (500<medi.getVisibilidad()&&medi.getVisibilidad()<=1000) {
                mtrz[2][medi.getFecha().getDia()-1]++;
            }
            if (1000<medi.getVisibilidad()&&medi.getVisibilidad()<=4000) {
                mtrz[3][medi.getFecha().getDia()-1]++;
            }
            if (4000<medi.getVisibilidad()&&medi.getVisibilidad()<=10000) {
                mtrz[4][medi.getFecha().getDia()-1]++;
            }
            if (10000<medi.getVisibilidad()) {
                mtrz[5][medi.getFecha().getDia()-1]++;
            }
        }

        i++;
    }

    //IMPRESION DE LOS QUE ACUMULÉ ARRIBA
    for (int i=0; i<31; i++) {

        for (int i=0; i<6; i++) {
         ///imprimo aca
        }
    }

}

// *********************** SEGUNDO ***********************
const char *AR_CIUDADESMYB="ciudadesmyb.dat";
class CiudadesModBuena {
    private:
        int _codigo;
        char _nombre[30];
        int _cantidadMyB;
    public:
    void Mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();

    //GETTERS
    int getCodigo(){return _codigo;}
    const char *getNombre(){return _nombre;}
    int getCantidadMyB(){return _cantidadMyB;}
    //SETTERS
    void setCodigo(int c){_codigo=c;}
    void setNombre(const char *n){strcpy(_nombre,n);}
    void setcantidadMyB(int p){_cantidadMyB=p;}
};

void CiudadesModBuena::Mostrar(){
    cout<<"CODIGO CUIDAD: ";
    cout<<getCodigo()<<endl;
    cout<<"NOMBRE: ";
    cout<<getNombre()<<endl;
    cout<<"CANTIDAD DE REGISTROS CON BUENA Y MODERADA VISIBILIDAD: ";
    cout<<getCantidadMyB()<<endl;
}
bool CiudadesModBuena::leerDeDisco(int pos){
    FILE *pCli;
    int leyo;

    pCli=fopen(AR_CIUDADESMYB,"rb");
    if (pCli==NULL){return false;}

    fseek(pCli, sizeof(CiudadesModBuena)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(CiudadesModBuena),1,pCli);
    fclose(pCli);

    if (leyo==1) {return true;}
    else{return false;}
}

bool CiudadesModBuena::grabarEnDisco(){
    FILE *pProm;
    bool escribio;

    pProm=fopen(AR_CIUDADESMYB,"ab");
    if (pProm==NULL){return false;}

    escribio=fwrite(this ,sizeof(CiudadesModBuena),1,pProm);
    fclose(pProm);

    if (escribio==1) {return true;}
    else{return false;}
}

bool generarArchivo2() {
    Ciudad ciu;
    Medicion medi;
    CiudadesModBuena modBue;
    int cont=0;
    int i=0;
    int j=0;
    bool band;

    while (ciu.leerDeDisco(i)){

        while (medi.leerDeDisco(j)) {

            if (medi.getCodigo()==ciu.getCodigo() && medi.getVisibilidad()>4000) {
                cont++;
            }
            j++;
        }
        modBue.setCodigo(ciu.getCodigo());
        modBue.setNombre(ciu.getNombre());
        modBue.setcantidadMyB(cont);
        band=modBue.grabarEnDisco();
        if (band==false) {return band;}

        j=0;
        cont=0;
        i++;
    }

    return true;
}

void buscarMin (CiudadesModBuena *v, int tam) {
    int min;
    int iMin=0;

    min=v[0].getCantidadMyB();

    for (int i=1; i<tam; i++) {
        if (v[i].getCantidadMyB()<min) {
            min=v[i].getCantidadMyB();
            iMin=i;
        }
    }

    cout<<"La ciudad con menos dias de  niebla es "<<v[iMin].getNombre()<<endl;
}

void ciudadConMenosDiasNieblaNeblina(){
    Ciudad ciu;
    Medicion medi;
    int i=0;
    int j=0;
    int v[31]={0};
    CiudadesModBuena *vModBue;
    int tam=0;
    int cont=0;

    tam=contarCiudades();
    vModBue = new CiudadesModBuena [tam];

    while (ciu.leerDeDisco(i)){

        while (medi.leerDeDisco(j)) {

            if (medi.getCodigo()==ciu.getCodigo() && medi.getVisibilidad()<=4000) {
                v[medi.getFecha().getMes()-1]++;
            }
            j++;
        }
        //cuento los días que tuvieron al menos 1 registro de visibilidad de niebla o neblina
        for (int k=0; k<31; k++) {
            if (v[k]>0) {
                cont++;
                v[k]=0;
            }
        }
        vModBue[i].setCodigo(ciu.getCodigo());
        vModBue[i].setNombre(ciu.getNombre());
        vModBue[i].setcantidadMyB(cont);

        cont=0;
        j=0;
        i++;
    }

    //busco el minimo e imprimo
    buscarMin(vModBue , tam);

    delete vModBue;
}

void generarVectorCiudades(int cod){
    Ciudad ciu;
    Ciudad *vCiu;
    int tam=0;
    int i=0;

    tam=contarCiudades();
    vCiu = new Ciudad[tam];

    while (ciu.leerDeDisco(i)) {
        vCiu[i]=ciu;
    }

    for (int j=0; j<tam; j++) {
        if (vCiu[j].getCodigoProvincia()==cod) {
            vCiu[j].Mostrar();
        }
    }
}

int main(){
    bool resp;
    int cod;

    //PUNTO A Generar un archivo con el siguiente formato: Código de ciudad, nombre, promedio de visibilidad.
    resp=generarArchivo();
    if (resp) {cout<<"EL ARCHIVO SE GENERÓ EXITOSAMENTE"<<endl;}
    else{cout<<"EL ARCHIVO NO PUDO GENERASE"<<endl;}

    //PUNTO B La cantidad de mediciones de cada grado de visibilidad por cada día del mes de mayo.
    listarMesMayo();

    //-----------------------------------------------------------------------------
    //PUNTO A Generar un archivo con el siguiente formato: Código de ciudad, nombre, cantidad de mediciones con moderada o buena visibilidad.
    resp=generarArchivo2();
    if (resp) {cout<<"EL ARCHIVO SE GENERÓ EXITOSAMENTE"<<endl;}
    else{cout<<"EL ARCHIVO NO PUDO GENERASE"<<endl;}

    // PUNTO B - La ciudad con menos días de niebla y neblina.
    ciudadConMenosDiasNieblaNeblina();

    // PUNTO C - Generar un vector de ciudades de manera dinámica, copiar todo el archivo de ciudades, y mostrar aquellas ciudades de una provincia cuyo código de provincia se ingrese por teclado.
    cout<<"Ingrese el codigo de provincia del que desee ver las ciudades registradas(de 1 a 24): ";
    cin>>cod;
    generarVectorCiudades(cod);

    system("pause");
    return 0;
}
