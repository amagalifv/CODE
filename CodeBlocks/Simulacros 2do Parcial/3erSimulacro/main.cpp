#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "Cls_Funcs.h"
const char *AR_TONECOSECHAS = "tonecosechas.dat";

class ToneCosechadas{
private:
    int _codEmp; // de 1 a ....
    char _nombre[20];
    float _tonelsCosecha;

public:
    void Mostrar();
    void Cargar();
    int leerDeDisco(int);
    int grabarEnDisco();
    // GETTERS
    int getCodigoEmpresa() { return _codEmp; }
    const char *getNombre() { return _nombre; }
    float getTonelsCosecha() { return _tonelsCosecha; }
    // SETTERS
    void setCodigoEmpresa(int c) { _codEmp = c; }
    void setNombre(const char *n) { strcpy(_nombre, n); }
    void setTonelsCosecha(float tc) { _tonelsCosecha = tc; }
};
void ToneCosechadas::Cargar(){
    int aux;
    float aux2;
    char texto[20];

    cout << "INGRESE EL CODIGO DE EMPRESA    :";
    cin >> aux;
    setCodigoEmpresa(aux);

    cout << "INGRESE EL NOMBRE               :";
    cin.getline(texto, 20);
    strcpy(_nombre, texto);

    cout << "INGRESE EL NUMERO DE TONELADAS  :";
    cin >> aux2;
    setTonelsCosecha(aux2);
}
void ToneCosechadas::Mostrar(){

    cout << "CODIGO DE EMPRESA    :" << getCodigoEmpresa() << endl;
    cout << "NOMBRE               :" << getNombre() << endl;
    cout << "NUMERO DE TONELADAS  :" << getTonelsCosecha() << endl;
    cout << endl;
}

/*******************************************************
-1 si no lo pudo abrir archivo
 1 si carga en el obj de la cls la info que leyo
 0 si no pudo leer
********************************************************/
int ToneCosechadas::leerDeDisco(int pos){
    FILE *pTone;
    int leyo;

    pTone = fopen(AR_TONECOSECHAS, "rb");
    if (pTone == NULL)
    {
        return -1;
    }

    fseek(pTone, sizeof(ToneCosechadas) * pos, SEEK_SET);
    leyo = fread(this, sizeof(ToneCosechadas), 1, pTone);
    fclose(pTone);

    return leyo;
}

/*********************************
-1 error de apertura de archivo
 0 error fwrite
 1 si escribió exitosamente
**********************************/
int ToneCosechadas::grabarEnDisco(){
    FILE *pTone;
    bool escribio;

    pTone = fopen(AR_TONECOSECHAS, "ab");
    if (pTone == NULL)
    {
        return -1;
    }

    escribio = fwrite(this, sizeof(ToneCosechadas), 1, pTone);
    fclose(pTone);
    return escribio;
}

int contarCantEmpresas(){
    Empresa emp;
    int i = 0;

    while (emp.leerDeDisco(i) == 1){
        i++;
    }

    return i;
}

void ponerEnCero(float *v, int &tam){
    for (int i=0; i<tam; i++){
        v[i]=0;
    }
}

void acumularToneladas(float *v, int &tam){
    Cosecha cos;
    int i = 0;

    while (cos.leerDeDisco(i)==1){

        if (cos.getCodigoEmp()<=tam){
            v[cos.getCodigoEmp()-1]+=cos.getTonelsCosecha();
        }

        i++;
    }
}

void generarArchivo(float *v, int &tam){
    ToneCosechadas ton;
    Empresa emp;
    int i=0;

    while (emp.leerDeDisco(i)==1) {
        ton.setCodigoEmpresa(emp.getCodigoEmpresa());
        ton.setNombre(emp.getNombre());
        ton.setTonelsCosecha(v[i]);

        ton.grabarEnDisco();

        i++;
    }
}

void acumularTonesCere10(float *meses, int tam){
    Cosecha cos;
    int i=0;

    while(cos.leerDeDisco(i)==1){
        if(cos.getCodigoCereal()==10) {
            meses[cos.getFecha().getMes()-1]+=cos.getTonelsCosecha();
        }
        i++;
    }

}

int mesMax(float *v, int tam){
    int mesMax;
    int i;

    mesMax=v[0];
    for (i=1; i<tam; i++) {
        if (v[i]>mesMax) {
            mesMax=v[i];
        }
    }
    return i+1;
}

void imprimirMesMax(float *v, int tam,int &mesMax){
    float toneladas;

    toneladas=v[mesMax-1];

    for (int i=0; i<tam; i++) {
        if (mesMax==v[i]) {
            cout<<", "<<v[i]+1;
        }
    }
}

int main(){
    //Punto A
    float *v;
    int tam;

    tam = contarCantEmpresas();
    v = new float[tam];

    ponerEnCero(v, tam);
    acumularToneladas(v, tam);
    generarArchivo(v, tam);

    delete v;

    //Punto B
    float meses[12]={0};
    int tam;
    int max;

    acumularTonesCere10(meses, 12);
    max=mesMax(meses,12);
    cout<<"El mes/es que tuvo más ventas es: "<<max<<" con "<<meses[max-1]<<" toneladas";
    imprimirMesMax(meses,12, max);

    system("pause");
    return 0;
}
