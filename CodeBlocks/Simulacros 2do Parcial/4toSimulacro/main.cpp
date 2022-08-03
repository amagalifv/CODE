# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

#include "Cls_Funcs.h"
const char *AR_CANTCOSECHAS = "cantcosechas.dat";

class CantCereal{
    private:
        int _codCereal;
        char _nombre[20];
        float _tonelsCosecha;
        bool _estado;
    public:
    CantCereal(){
        _tonelsCosecha=0;
        _estado=true;
    }
    void Mostrar();
    void Cargar();
    int leerDeDisco(int);
    int grabarEnDisco();
    //GETTERS
    int getCodigoCereal(){return _codCereal;}
    const char *getNombre(){return _nombre;}
    float getTonelsCosecha(){return _tonelsCosecha;}
    bool getEstado(){return _estado;}
    //SETTERS
    void setCodigoCereal(int c){_codCereal=c;}
    void setNombre(const char *n){strcpy(_nombre,n);}
    void setTonelsCosecha(float tc){_tonelsCosecha=tc;}
    void setEstado(bool e){_estado=e;}
    //sobrecarga de operador == para codigo
    bool operator== (int codigo){
        if (codigo==getCodigoCereal()) {return true;}
        return false;
    }
};
void CantCereal::Cargar(){
    int aux;
    float aux2;
    char texto[20];

    cout << "INGRESE EL CODIGO DE CEREAL     :";
    cin >> aux;
    setCodigoCereal(aux);

    cout << "INGRESE EL NOMBRE               :";
    cin.getline(texto, 20);
    strcpy(_nombre, texto);

    cout << "INGRESE EL NUMERO DE TONELADAS  :";
    cin >> aux2;
    setTonelsCosecha(aux2);

    setEstado(true);
}
void CantCereal::Mostrar(){

    cout << "CODIGO DE CEREAL     :" << getCodigoCereal() << endl;
    cout << "NOMBRE               :" << getNombre() << endl;
    cout << "NUMERO DE TONELADAS  :" << getTonelsCosecha() << endl;
    cout << endl;
}

/*
-1 si no lo pudo abrir archivo
 1 si carga en el obj de la cls la info que leyo
 0 si no pudo leer
*/
int CantCereal::leerDeDisco(int pos){
    FILE *pCant;
    int leyo;

    pCant = fopen(AR_CANTCOSECHAS, "rb");
    if (pCant == NULL)
    {
        return -1;
    }

    fseek(pCant, sizeof(CantCereal) * pos, SEEK_SET);
    leyo = fread(this, sizeof(CantCereal), 1, pCant);
    fclose(pCant);

    return leyo;
}
/*
-1 error de apertura de archivo
 0 error fwrite
 1 si escribió exitosamente
*/
int CantCereal::grabarEnDisco(){
    FILE *pCant;
    bool escribio;

    pCant = fopen(AR_CANTCOSECHAS, "ab");
    if (pCant == NULL)
    {
        return -1;
    }

    escribio = fwrite(this, sizeof(CantCereal), 1, pCant);
    fclose(pCant);
    return escribio;
}

int cargarCereales(CantCereal *v){
    Cereal cer;
    int i=0;

    while (cer.leerDeDisco(i)==1) {
        v[i].setCodigoCereal(cer.getCodigoCereal());
        v[i].setNombre(cer.getNombre());

        i++;
    }
    return i;
}

//ALGORITMO DE ORDENAMIENTO DE MENOR A MAYOR POR CODIGO DE CEREAL
//LO ORDENO PARA LUEGO REALIZAR UNA BUSQUEDA BINARIA
void burbujeoReloaded(CantCereal *v, int tam){
    CantCereal aux;
    int i=0;
    bool ordenado = false;

    while (i < tam && !ordenado){

        ordenado= true;

        for (int j = 0; j<tam-i-1 ; j++){

            if (v[j].getCodigoCereal()>v[j+1].getCodigoCereal()){
                aux = v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                ordenado = false;
            }
        }

        i++;
    }

}

int busquedaBinariaEstructuras(CantCereal *v, int tam, int nro){
    //Cuando arranco evaluo todo elvector de 0 a n-1
    int inicio=0;
    int fin=tam-1;

    while(fin >= inicio){
        int mitad =inicio + (fin - inicio)/2;

        //si el elemento es el del medio, devolvemos la posicion
        if (v[mitad].getCodigoCereal()==nro){
            return mitad;
        }

        //si el elemento es menor entonces solo puede estar en la primera mitad
        if (v[mitad].getCodigoCereal()>nro){
            fin=mitad - 1; //Cambio el limite superior
        }else{
            inicio=mitad+1; //Cambio el limite inferior
        }
    }
    // Si llegamos hasta aca es que el elemento no estaba
    return -1;
}


void acumularToneladas(CantCereal *v, int &tam){
    Cosecha cos;
    int i=0;
    int pos;

    while (cos.leerDeDisco(i)==1) {
        pos=busquedaBinariaEstructuras(v,tam,cos.getCodigoCereal());
        if (pos>-1){v[pos].setTonelsCosecha(v[pos].getTonelsCosecha()+cos.getTonelsCosecha());}
        i++;
    }
}

void grabarEnArchivo(CantCereal *v, int tam){

    for (int i=0; i<tam; i++) {
        v[i].grabarEnDisco();
    }
}

int busquedaEnCereales(int cod){
    Cereal cer;
    int i=0;

    while(cer.leerDeDisco(i)==1) {
        if (cer.getCodigoCereal()==cod) {
            return i;
        }
        i++;
    }
    return -1;
}

void puntoB(){
    Cosecha cos;
    Cereal cer;
    int mtrz[20][12];
    int i=0;
    int pos;

    while(cos.leerDeDisco(i)==1){
        mtrz[cos.getCodigoCereal()-1][cos.getFecha().getMes()-1]++;
        i++;
    }

    for (int i=0; i<20; i++) {
        cout<<"********************************"<<endl;
        cout<<"CEREAL Nro "<<i+1<<", ";
        pos=busquedaEnCereales(i+1);
        if(pos>-1){
            cer.leerDeDisco(pos);
            cout<<cer.getNombre()<<endl;
        }

        for (int j=0; j<12; j++) {
            cout<<"MES "<<j+1<<": "<<mtrz[i][j]<<endl;
        }
        cout<<endl;
    }
}


int main(){
    /*     PUNTO A     */
    CantCereal *vAux;
    int tam;

    // HALLAR TAM
    tam=cargarCereales(vAux);
    vAux=new CantCereal[tam];
    // ORDENO DE MIN A MAJ POR CODIGO DE CEREAL
    burbujeoReloaded(vAux, tam);
    //ACUMULO TONELADAS EN EL VEC
    acumularToneladas(vAux, tam);
    //GUARDO MI VECTOR EN ARCHIVO
    grabarEnArchivo(vAux, tam);
    delete vAux;

    /*     PUNTO B     */
    puntoB();

    system("pause");
    return 0;
}
