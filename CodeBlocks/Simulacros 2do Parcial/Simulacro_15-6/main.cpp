# include<iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

#include "ClsyFunciones.h"

/*
Una aplicación de venta de música registra las compras de los usuarios en un archivo con el siguiente formato:

Número de compra (int), el DNI y el nombre del usuario, la fecha, el género musical (1 a 50) y el código de la canción (char[5]).

A partir de los señalado desarrollar los siguientes puntos.

    1) Crear la clase correspondiente con sets() y gets() para todas las propiedades.
    2) Agregar una sobrecarga de un operador que compare la propiedad número de compra con un valor que recibe como parámetro
    3) Hacer una función externa (o las que se consideren necesarias) que ||||||RECIBA UNA FECHA||||||| y muestre todas las ventas registradas en el archivo ese día.
    4) Hacer una función externa (o las que se consideren necesarias) que muestre la cantidad de ventas registradas por género musical.
    5)Generar un vector dinámico para cargar los 10 primeros registros del archivo del punto anterior.
    6)Mostrar el vector.
*/
const char *AR_VENTASMUSICA="ventasmusica.dat";

class VentaMusica{
    private:
        int _nroCompra;
        int _dni;
        char _nombreUsuario[20];
        Fecha _fecha;
        int _generoM;
        char _codigoCancion[5];
    public:
        void Cargar();
        void Mostrar();
        int grabarEnDisco();
        int leerDeDisco(int);

        //GETTERS
        int getNroCompra(){return _nroCompra;}
        int getDni(){return _dni;}
        const char *getNombreUsuario(){return _nombreUsuario;}
        Fecha getFecha(){return _fecha;}
        int getGeneroMusica(){return _generoM;}
        const char *getCodigoCancion(){return _codigoCancion;}
        //SETTERS
        void setNroCompra(int n){_nroCompra=n;}
        void setDni(int d){_dni=d;}
        void setNombreUsuario(const char *nom){strcpy(_nombreUsuario,nom);}
        void setFecha(Fecha f){_fecha=f;}
        void setGeneroMusica(int g){_generoM=g;}
        void setCodigoCancion(const char *cod){strcpy(_codigoCancion,cod);}

        //SOBRECARGA!!
        bool operator==(int &aux){
            if (getNroCompra()==aux){return true;}
            return false;
        }
};

void VentaMusica::Cargar(){
    int aux;
    char texto[5], textoL[20];

    cout<<"INGRESE EL NUMERO DE COMPRA  :";
    cin>>aux;
    setNroCompra(aux);

    cout<<"INGRESE EL DNI               :";
    cin>>aux;
    setDni(aux);

    cout<<"INGRESE EL NOMBRE DE USUARIO :";
    cin.getline(textoL, 20);
    strcpy(_nombreUsuario, textoL);

    _fecha.Cargar();

    cout<<"INGRESE EL GENERO MUSICAL   :";
    cin>>aux;
    setGeneroMusica(aux);

    cout<<"INGRESE EL CODIGO DE CANCION";
    cin.getline(textoL, 5);
    strcpy(_nombreUsuario, texto);
}

void VentaMusica::Mostrar(){
    cout<<"EL NUMERO DE COMPRA  :"<<getNroCompra()<<endl;

    cout<<"EL DNI               :"<<getDni()<<endl;

    cout<<"EL NOMBRE DE USUARIO :"<<getNombreUsuario()<<endl;

    _fecha.Mostrar();

    cout<<"EL GENERO MUSICAL   :"<<getGeneroMusica()<<endl;

    cout<<"EL CODIGO DE CANCION"<<getCodigoCancion()<<endl;

}

/*******************************************************
-1 si no lo pudo abrir archivo
 1 si carga en el obj de la cls la info que leyo
 0 si no pudo leer
********************************************************/
int VentaMusica::leerDeDisco(int pos){
    FILE *pVen;
    int leyo;

    pVen=fopen(AR_VENTASMUSICA,"rb");
    if (pVen==NULL){return -1;}

    fseek(pVen, sizeof(VentaMusica)*pos,SEEK_SET);
    leyo=fread(this ,sizeof(VentaMusica),1,pVen);
    fclose(pVen);

    return leyo;
}

/*********************************
-1 error de apertura de archivo
 0 error fwrite
 1 si escribió exitosamente
**********************************/
int VentaMusica::grabarEnDisco(){
    FILE *pVen;
    bool escribio;

    pVen=fopen(AR_VENTASMUSICA,"ab");
    if (pVen==NULL){return -1;}

    escribio=fwrite(this ,sizeof(VentaMusica),1,pVen);
    fclose(pVen);
    return escribio;
}

void listarFechaDeterminada(Fecha f){
    VentaMusica ven;
    int i=0;

    cout<<"***************** VENTAS AL ";
    f.Mostrar();
    cout<<"*****************"<<endl;

    while (ven.leerDeDisco(i)==1) {
        if(f==ven.getFecha()) {
            ven.Mostrar();
            cout<<endl<<endl;
        }

        i++;
    }
}

void AcumularCantVentasPorGeneroM(int *v, int tam){
    VentaMusica ven;
    int i=0;

    while (ven.leerDeDisco(i)==1) {
        if (ven.getGeneroMusica()<tam) {
            v[ven.getGeneroMusica()-1]++;
        }
        i++;
    }
}

void MostrarCantVentasPorGeneroM(int *v, int tam){

    for (int i=0; i<tam; i++) {
        cout<<"GENERO MUSICAL "<<i+1<<" cantidad de ventas: "<<v[i]<<endl;
    }
}

void cargarVectorDinamico(VentaMusica *vDin, int &tam){
    VentaMusica obj;
    int i=0;

    while (obj.leerDeDisco(i)==1 && i<tam) {
        vDin[i]=obj;
        i++;
    }
}

void mostrarVectorDinamico(VentaMusica *vDin, int &tam){
    for (int i=0; i<tam; i++) {
        vDin[i].Mostrar();
    }
}



int main(){
    Fecha f;
    int v[50]={0};
    VentaMusica *vDin;
    int tam=10;

    f.Cargar();
    listarFechaDeterminada(f);

    AcumularCantVentasPorGeneroM(v,50);
    MostrarCantVentasPorGeneroM(v,50);

    vDin= new VentaMusica[tam];
    cargarVectorDinamico(vDin, tam);
    mostrarVectorDinamico(vDin, tam);
    delete vDin;


    system("pause");
    return 0;
}
