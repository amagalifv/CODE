#include <iostream>
using namespace std;

#define MAX_IDSERIES 10

typedef struct{
int idSerie;
short int temporada;
long int cantDescargas;
string tituEpi;
int episodio;
int fecha;
}ST_EPI;

void cargarVector(ST_EPI series[], int cantSeries){
    series[0]={100010001,1,10,"Aaaaaaaaa",1,20210601};
    series[1]={100010001,2,2,"Bbbbbb",2,20210602};

    series[2]={100010002,1,1,"ccccc",1,20210603};

    series[3]={100010003,1,3,"dddddd",1,20210604};

    return;
}

void impCorteC (ST_EPI series[], int cantSeries) {
    int i = 0;
    int contEpiSerie = 0;
    int contEpiTemp = 0;
    int contDescTemp=0;
    int contDescSerie=0;
    int contTotSeries=0;
    int key;
    int key2;

    while(i < cantSeries) {

        key = series[i].idSerie;
        cout<<"Serie: "<<series[i].idSerie<<endl;
        contEpiSerie = 0;
        contDescSerie=0;
        contTotSeries++;
        
        while (i < cantSeries && key == series[i].idSerie) {

            key2=series[i].temporada;
            cout<<"Temporada: "<<series[i].temporada<<endl;
            cout<<"N. de Episodio  Tit del Epis.  Cant.Desc.  Fecha Desc."<<endl;
            contEpiTemp = 0;
            contDescTemp=0;
            
            while(i<cantSeries && key == series[i].idSerie && key2==series[i].temporada) {
                
                cout<<series[i].episodio<<"\t\t"<<series[i].tituEpi<<"\t\t"<<series[i].cantDescargas<<"\t\t"<<series[i].fecha<<endl;
                contEpiTemp++;
                contDescTemp+=series[i].cantDescargas;
                i++; 
            }
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"Cant.Tot. de Epi. de la Temporada: "<<contEpiTemp<<endl;
            cout<<"Tot descargas de la temporada: "<<contDescTemp<<endl;
            cout<<endl;
            contEpiSerie+=contEpiTemp;
            contDescSerie+=contDescTemp;
        }
        cout<<endl;
        cout<<"Cant.Tot. de Epi. de la Serie: "<<contEpiSerie<<endl;
        cout<<"Tot descargas de la Serie: "<<contDescSerie<<endl;
        cout<<endl;
    }
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"TOTAL GENERAL DE SERIES: "<<contTotSeries<<endl;

    return;
}

int main () {
    ST_EPI series[MAX_IDSERIES];
    int cantSeries=4;

    //cout<<"Ingrese la cantidad de series del listado"<<endl;
    //cin>>cantSeries;

    cargarVector(series, cantSeries);

    impCorteC(series, cantSeries);
    
    system("pause");
    return 0;
}