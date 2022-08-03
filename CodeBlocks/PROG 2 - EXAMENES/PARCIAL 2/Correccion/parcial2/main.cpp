# include<iostream>
# include<cstdlib>
# include<cstring>
# include<cstdio>
# include<cstring>
using namespace std;

#include "parcial2.h"

const char *AR_AVIONNOACTIVO="avionnoactiva.dat";

class AvionNoActivo{
    private:
        int codigoAvion;
        char marca[30];
        int tipo;
        bool activo=true;

    public:
        void Cargar(){
        cin>>codigoAvion;
        cargarCadena(marca,29);
        cin>>tipo;
        activo=true;
        }
        void Mostrar(){
            cout<<codigoAvion<<endl;
            cout<<marca<<endl;
            cout<<tipo<<endl;
        }
        //GETTERS
        int getCodigoAvion(){return codigoAvion;}
        int getTipo(){return tipo;}
        const char *getMarca(){return marca;}
        bool getActivo(){return activo;}
        //SETTERS
        void setCodigoAvion(int ca){codigoAvion=ca;}
        void setTipo(int t){tipo=t;}
        void setMarca(const char *m){strcpy(marca,m);}
        void setActivo(bool a){activo=a;}

        int leerDeDisco(int pos){
            FILE *p;
            p=fopen(AR_AVIONNOACTIVO, "rb");
            if(p==NULL) return -1;
            fseek(p, sizeof(AvionNoActivo) * pos,0);
            int leyo=fread(this, sizeof(AvionNoActivo),1, p);
            fclose(p);
            return leyo;
        }

        int grabarEnDisco(){
            FILE *p;
            p=fopen(AR_AVIONNOACTIVO, "ab");
            if(p==NULL) return -1;
            int grabo=fwrite(this, sizeof(AvionNoActivo),1, p);
            fclose(p);
            return grabo;
        }
};
/* PUNTO 1
Generar un archivo con los aviones que no se hayan utilizado en el año actual. Por cada avión no usado
este año se debe registrar el código de avión, el tipo, y la marca.
*/

void generarArchivo(){
    Pasaje pas;
    Avion avi;
    AvionNoActivo aviNew;
    int i=0, j=0,cont=0;


    while (avi.leerDeDisco(i)==1) {

        while (pas.leerDeDisco(j)==1) {
            if (pas.getFechaCompra().getAnio()==2022 && pas.getCodigoAvion()==avi.getCodigoAvion()) {
                cont++;
            }
            j++;
        }
        if (cont==0) {
            aviNew.setCodigoAvion(avi.getCodigoAvion());
            aviNew.setMarca(avi.getMarca());
            aviNew.setTipo(avi.getTipo());

            aviNew.grabarEnDisco();
        }

        j=0;
        cont=0;
        i++;
    }
}

void listarArchivoNuevo(){
    AvionNoActivo avi;
    int i=0;

    while(avi.leerDeDisco(i)==1){
        avi.Mostrar();
    }
}

/* PUNTO 2
Calcular e informar el mes de este año con más cantidad de pasajes vendidos
*/
void mesConMasPasajesVendidos(){
    int v[12]={0};
    int i=0, max=0, iMax=0;
    Pasaje pas;

    while (pas.leerDeDisco(i)==1) {
        if (pas.getActivo()) {
            v[pas.getFechaCompra().getMes()-1]=v[pas.getFechaCompra().getMes()-1]+pas.getCantidad();
        }
        i++;
    }

    max=v[0];
    for (int j=1; j<12; j++) {
        if (v[j]>max) {
            max=v[j];
            iMax=j;
        }
    }

    cout<<"EL/LOS MES/ES CON MAS VENTA DE PASAJES ES/SON: "<<iMax+1;

    for (int k=0; k<12; k++) {
        if (v[k]==max) {
            cout<<" y el "<<k+1;
        }
    }
    cout<<endl;
}

/* PUNTO 3
Generar un vector dinámico con todos los pasajes y listar luego los pasajes del vector que pertenezcan a un
código de avión que se ingresa por teclado.
*/
void buscarCodAvEnPasajes(int cod){
    int i=0;
    Pasaje pas;
    Pasaje *vec;
    int tam=0;

    while (pas.leerDeDisco(i)==1) {
        if (pas.getActivo()==true) {
            tam++;
        }
        i++;
    }

    vec=new Pasaje[tam];
    i=0;
    tam=0;
    while (pas.leerDeDisco(i)==1) {
        if (pas.getActivo()==true) {
            vec[tam]=pas;
            tam++;
        }
        i++;
    }

    for (int j=0; j<tam; j++) {
        cout<<"\n";
        if (vec[j].getCodigoAvion()==cod) {
            vec[j].Mostrar();
            cout<<"\n";
        }
    }
    delete vec;
}

/* PUNTO 4
Sobrecargar el operador < para la clase Vuelo de manera tal que sea verdadero cuando el objeto que llama
al método tenga un valor de de tiempo de vuelo menor a un valor de tipo float que se recibe como parámetro
*/
bool Vuelo::operator<(float tiempoDeViaje){
    if (getTiempoViaje()<tiempoDeViaje) {
        return true;
    }
    return false;
}

int main(){
    int opc, codAvion;
    float tiempoDeViaje;
    Vuelo vueloPrimerRegistro;

    while(true){
        cout<<"************************************\n";
        cout<<"           MENU PRINCIPAL           \n";
        cout<<"************************************\n";
        cout<<"      1) PUNTO  1                   \n";
        cout<<"      2) PUNTO  2                   \n";
        cout<<"      3) PUNTO  3                   \n";
        cout<<"      4) PUNTO  4                   \n";
        cout<<"************************************\n";
        cout<<"      0) FIN DEL PROGRAMA           \n";
        cout<<"************************************\n";
        cout<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: ";
        cin>>opc;
        system("cls");

        switch(opc){

            case 1:
                void generarArchivo();
                void listarArchivoNuevo();
                break;
            case 2:
                void mesConMasPasajesVendidos();
                break;
            case 3:
                cout<<"INGRESE EL CODIGO DE AVION A BUSCAR: "<<endl;
                cin>>codAvion;
                buscarCodAvEnPasajes(codAvion);
                break;
            case 4:
                cout<<"INGRESE EL TIEMPO DE VIAJE A COMPARAR: "<<endl;
                cin>>tiempoDeViaje;
                vueloPrimerRegistro.leerDeDisco(0); //comparo contra el primer registro, no importa si está activo, es solo de forma ilustrativa
                if (vueloPrimerRegistro<tiempoDeViaje) {
                    cout<<"\nEs verdadero\n";
                }else{
                    cout<<"\nEs falso\n";
                }
                break;
            default:
                return 0;
                break;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }

    system("pause");
    return 0;
}
